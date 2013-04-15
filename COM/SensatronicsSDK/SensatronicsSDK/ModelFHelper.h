// ModelFHelper.h: interface for the CModelFHelper class.

#pragma once
#include "..\..\Libs\SerialCOMLibrary\SerialPortEx.h"

class CModelFHelper  
{
public:
	CModelFHelper();
	virtual ~CModelFHelper();

	bool poll(CString *psCommandHistory);
	bool disconnectModelF();
	bool connectModelF(const int nCOMPort);

	CString m_sProbe1Temp;
	CString m_sProbe2Temp;
	CString m_sBattery;

private:
	CSerialPortEx *m_pSerialPort;
	COMMCONFIG m_CommConfig;

};
