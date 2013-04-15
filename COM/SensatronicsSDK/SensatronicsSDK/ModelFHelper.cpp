// ModelFHelper.cpp: implementation of the CModelFHelper class.

#include "stdafx.h"
#include "ModelFHelper.h"
//#include "Helper.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CModelFHelper::CModelFHelper()
: m_pSerialPort ( NULL )
, m_sProbe1Temp ( _T("-99.9") )
, m_sProbe2Temp ( _T("-99.9") )
, m_sBattery ( _T(" Bat Ok") )
{

}

CModelFHelper::~CModelFHelper()
{
	if(m_pSerialPort != NULL)
		disconnectModelF();
}

bool CModelFHelper::connectModelF(const int nCOMPort)
{
	bool bReturn = false;

	try
	{
		CSerialPort::GetDefaultConfig(nCOMPort, m_CommConfig);

		m_pSerialPort = new CSerialPortEx;

		m_pSerialPort->Open(nCOMPort, 9600, CSerialPort::NoParity, 8, CSerialPort::OneStopBit, CSerialPort::NoFlowControl);

		HANDLE hPort = m_pSerialPort->Detach();
		m_pSerialPort->Attach(hPort);

		DWORD dwModemStatus;
		m_pSerialPort->GetModemStatus(dwModemStatus);

		DCB dcb;
		m_pSerialPort->GetState(dcb);

		dcb.BaudRate = 9600;
		m_pSerialPort->SetState(dcb);    

		DWORD dwErrors;                      
		m_pSerialPort->ClearError(dwErrors);

		m_pSerialPort->SetBreak();
		m_pSerialPort->ClearBreak();

		COMSTAT stat;
		m_pSerialPort->GetStatus(stat);

		COMMTIMEOUTS timeouts;
		m_pSerialPort->GetTimeouts(timeouts);

		m_pSerialPort->Setup(10000, 10000);

		m_pSerialPort->GetConfig(m_CommConfig);

		m_CommConfig.dcb.BaudRate = 9600;
		m_pSerialPort->SetConfig(m_CommConfig);

		m_pSerialPort->Set0WriteTimeout();
		m_pSerialPort->Set0ReadTimeout();
	}
	catch (...)
	{
		/*string sError("");
		string sTemp("");

		openxtra::utl::to_string<int>(pEx->m_dwError, sTemp);

		sError = "Error Caught";
		sError += "\n Error Number: " + sTemp + "\n\n";
		sError += pEx->GetErrorMessage();
		pEx->Delete();
		throw runtime_error(sError);*/
	}

	return bReturn;
}

bool CModelFHelper::disconnectModelF()
{
	bool bReturn = false;

	if(m_pSerialPort == NULL)
		return false;

	try
	{
		if(m_pSerialPort->IsOpen())
		{
			m_pSerialPort->TerminateOutstandingWrites();

			m_pSerialPort->Set0Timeout();

			m_pSerialPort->TerminateOutstandingReads();

			m_pSerialPort->ClearDTR();

			m_pSerialPort->ClearRTS();

			/*m_pSerialPort->SetDTR();

			m_pSerialPort->SetRTS();

			m_pSerialPort->SetXOFF();

			m_pSerialPort->SetXON();*/

			COMMPROP properties;
			m_pSerialPort->GetProperties(properties);

			m_pSerialPort->ClearWriteBuffer();

			m_pSerialPort->ClearReadBuffer();

			//m_pSerialPort->Flush();

			m_pSerialPort->Close();
		}

		delete m_pSerialPort;

		m_pSerialPort = NULL;
	}
	catch (...)
	{
		/*string sError("");
		string sTemp("");

		openxtra::utl::to_string<int>(pEx->m_dwError, sTemp);

		sError = "Handle Exception, Message:";
		sError += pEx->GetErrorMessage();
		sError += "\n Error Number: " + sTemp;
		pEx->Delete();
		throw runtime_error(sError);*/
	}

	return bReturn;
}

bool CModelFHelper::poll(CString *psCommandHistory)
{
	bool bReturn = false;
	std::string sCommandString("*");
	std::string sBuffer("");
	size_t nFind = -1;

	ATLASSERT(m_pSerialPort != NULL);

	if(m_pSerialPort == NULL)
		return false;

	try
	{
		m_pSerialPort->SetDTR();

		Sleep(500);

		m_pSerialPort->Write(sCommandString.c_str(), (DWORD)sCommandString.size());

		Sleep(1000);

		sBuffer = "";
		m_pSerialPort->ReadResponse(&sBuffer);

		{
			// Built in MACRO to convert Unicode to ANSI
			CA2T psztBuffer( sBuffer.c_str() );
			psCommandHistory->Append(psztBuffer);
		}

		// remove CR
		nFind = sBuffer.find(13);

		if(nFind != -1)
			sBuffer.replace(nFind, 1, "");

		// remove LF
		nFind = sBuffer.find(10);

		if(nFind != -1)
			sBuffer.replace(nFind, 1, "");

		if(sBuffer != "")
		{
			// Built in MACRO to convert Unicode to ANSI
			CA2T psztBuffer( sBuffer.c_str() );

			m_sProbe1Temp = psztBuffer;
			m_sProbe1Temp.Trim(_T(" "));
		}
		else
			m_sProbe1Temp = _T("-99.9");

		sBuffer = "";
		m_pSerialPort->ReadResponse(&sBuffer);

		{
			// Built in MACRO to convert Unicode to ANSI
			CA2T psztBuffer( sBuffer.c_str() );
			psCommandHistory->Append(psztBuffer);
		}

		// remove CR
		nFind = sBuffer.find(13);

		if(nFind != -1)
			sBuffer.replace(nFind, 1, "");

		// remove LF
		nFind = sBuffer.find(10);

		if(nFind != -1)
			sBuffer.replace(nFind, 1, "");

		if(sBuffer != "")
		{
			// Built in MACRO to convert Unicode to ANSI
			CA2T psztBuffer( sBuffer.c_str() );

			m_sProbe2Temp = psztBuffer;
			m_sProbe2Temp.Trim(_T(" "));
		}
		else
			m_sProbe2Temp = "-99.9";

		sBuffer = "";
		m_pSerialPort->ReadResponse(&sBuffer);
		
		{
			// Built in MACRO to convert Unicode to ANSI
			CA2T psztBuffer( sBuffer.c_str() );
			psCommandHistory->Append(psztBuffer);
		}

		// remove CR
		nFind = sBuffer.find(13);

		if(nFind != -1)
			sBuffer.replace(nFind, 1, "");

		// remove LF
		nFind = sBuffer.find(10);

		if(nFind != -1)
			sBuffer.replace(nFind, 1, "");

		if(sBuffer != "")
		{
			CA2T psztBuffer( sBuffer.c_str() );
			m_sBattery = psztBuffer;
		}
		else
			m_sBattery = _T("Bat Ok");
	}
	catch(...)
	{
		bReturn = false;
	}

	ATLTRACE2(*psCommandHistory);

	return bReturn;
}
