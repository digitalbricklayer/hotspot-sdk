// DataConnector.cpp : Implementation of DataConnectoror

#include "stdafx.h"
#include "DataConnector.h"
#include "XMLParser.h"
#include "HTTPParser.h"
#include "ModelFHelper.h"
#include <boost/lexical_cast.hpp>
#include "openxtra.h"


// DataConnector

HRESULT CDataConnector::RequestXML(BSTR Val, IXMLElementHandler* ElementHandler)
{
	HRESULT hr = E_OUTOFMEMORY;

	CXMLParser xmlParser(ElementHandler);

	hr = xmlParser.Parse(Val);

	return hr;
}

HRESULT CDataConnector::RequestXML(VARIANT Val, IXMLElementHandler* ElementHandler)
{
	HRESULT hr = E_OUTOFMEMORY;

	CXMLParser xmlParser(ElementHandler);

	hr = xmlParser.Parse(Val);

	return hr;
}

STDMETHODIMP CDataConnector::RequestModelEXMLData(BSTR Id, BSTR Val, LONG* Handler)
{
	HRESULT hr = E_OUTOFMEMORY;

	IXMLElementHandler* ElementHandler = static_cast<IXMLElementHandler*>((IXMLElementHandler*)Handler);

	hr = RequestMockSensorsXML(Id, ElementHandler, VARIANT_TRUE);
	
	if(FAILED(hr))
		hr = RequestXML(Val, ElementHandler);

	return hr;
}

STDMETHODIMP CDataConnector::RequestModelEXMLConfigData(BSTR Id, BSTR Val, LONG* Handler)
{
	HRESULT hr = E_OUTOFMEMORY;

	IXMLElementHandler* ElementHandler = static_cast<IXMLElementHandler*>((IXMLElementHandler*)Handler);

	hr = RequestMockSensorsXML(Id, ElementHandler, VARIANT_FALSE);
	
	if(FAILED(hr))
		hr = RequestXML(Val, ElementHandler);

	return hr;
}

STDMETHODIMP CDataConnector::RequestModelFSerialComConfigData(BSTR Id, BSTR ComPort, LONG* Handler)
{
	HRESULT hr = E_OUTOFMEMORY;

	IXMLElementHandler* ConfigElementHandler = static_cast<IXMLElementHandler*>((IXMLElementHandler*)Handler);

	if(ConfigElementHandler != NULL)
	{
		CComBSTR bstrConfigXML(OPENXTRA::Constants::sModelFXMLConfig);
		VARIANT varVal;
		VariantInit(&varVal);
		varVal.vt = VT_BSTR;
		varVal.bstrVal = bstrConfigXML.Copy();

		hr = RequestXML(varVal, ConfigElementHandler);
	}

	return hr;
}

STDMETHODIMP CDataConnector::RequestModelFSerialComData(BSTR Id, BSTR ComPort, LONG* Handler)
{
	HRESULT hr = E_OUTOFMEMORY;

	IXMLElementHandler* DataElementHandler = static_cast<IXMLElementHandler*>((IXMLElementHandler*)Handler);


	hr = RequestMockSensorsXML(Id, DataElementHandler, VARIANT_TRUE);
	
	if(FAILED(hr))
	{
		try
		{
			CString sCommandHistory(_T(""));
			CString sXML(_T(""));

			int nComPort = -1;

			try
			{
				nComPort = boost::lexical_cast<int>(ComPort);
			}
			catch(boost::bad_lexical_cast&)
			{
				return E_OUTOFMEMORY;
			}

			CModelFHelper ModelFHelper;

			if(ModelFHelper.connectModelF(nComPort))
			{
				ModelFHelper.poll(&sCommandHistory);

				sXML.Format(_T("<Sensatronics><BatteryStatus>%s</BatteryStatus><Group id=\"1\"><Probe id=\"1\"><Value>%s</Value></Probe><Probe id=\"2\"><Value>%s</Value></Probe></Group></Sensatronics>"), ModelFHelper.m_sBattery, ModelFHelper.m_sProbe1Temp, ModelFHelper.m_sProbe2Temp);

				ModelFHelper.disconnectModelF();

				VARIANT varVal;
				VariantInit(&varVal);
				varVal.vt = VT_BSTR;
				varVal.bstrVal = CComBSTR(sXML).Copy();

				hr = RequestXML(varVal, DataElementHandler);
			}
			else
			{
				return E_ACCESSDENIED;
			}
		}
		catch(...)
		{
			return E_OUTOFMEMORY;
		}
	}

	return hr;
}

HRESULT CDataConnector::ConvertHTTPDataToXMLConfigAndData(BSTR Model, BSTR Config, BSTR* pXMLConfig, BSTR Data, BSTR* pXMLData)
{
	HRESULT hr = E_OUTOFMEMORY;

	CString sDataXML(_T(""));
	CString sConfigXML(_T(""));

	if(CString(Model) == L"EM1")
	{
		OPENXTRA::SensatronicsConvertToXML::ConvertEMConfigAndData(Config, &sConfigXML, Data, &sDataXML);
	}
	else
	{
		OPENXTRA::SensatronicsConvertToXML::ConvertModelEConfigAndData(Config, &sConfigXML, Data, &sDataXML);
	}

	hr = CComBSTR(sDataXML).CopyTo(pXMLData);
	hr = CComBSTR(sConfigXML).CopyTo(pXMLConfig);

	return hr;
}

HRESULT CDataConnector::RequestHTTP(BSTR IpAddress, BSTR Path, BSTR* pVal)
{
	HRESULT hr = E_OUTOFMEMORY;

	CString sResponse(_T(""));

	CHTTPParser HTTPParser;

	if(HTTPParser.HTTPGet(IpAddress, Path, sResponse))
	{
		*pVal = CComBSTR(sResponse).Copy();
		hr = S_OK;
	}
	else
		hr = E_OUTOFMEMORY;

	return hr;
}

STDMETHODIMP CDataConnector::RequestModelEHTTPConfigAndData(BSTR Id, BSTR IpAddress, BSTR ConfigPath, BSTR DataPath, BSTR Model, LONG* ConfigHandler, LONG* DataHandler)
{
	HRESULT hr = E_OUTOFMEMORY;

	IXMLElementHandler* ConfigElementHandler = static_cast<IXMLElementHandler*>((IXMLElementHandler*)ConfigHandler);
	IXMLElementHandler* DataElementHandler = static_cast<IXMLElementHandler*>((IXMLElementHandler*)DataHandler);

	CComBSTR bstrIpAddress(IpAddress);

	hr = RequestMockSensorsXML(Id, ConfigElementHandler, VARIANT_FALSE);
	hr = RequestMockSensorsXML(Id, DataElementHandler, VARIANT_TRUE);
	
	if(FAILED(hr))
	{
		if(bstrIpAddress.Length() != 0)
		{
			CComBSTR bstrConfig(L"");
			hr = RequestHTTP(IpAddress, ConfigPath, &bstrConfig);

			if(FAILED(hr))
				return hr;

			CComBSTR bstrData(L"");
			hr = RequestHTTP(IpAddress, DataPath, &bstrData);

			if(FAILED(hr))
				return hr;

			CComBSTR bstrConfigXML(L"");
			CComBSTR bstrDataXML(L"");

			hr = ConvertHTTPDataToXMLConfigAndData(Model, bstrConfig.Copy(), &bstrConfigXML, bstrData.Copy(), &bstrDataXML);

			if(FAILED(hr))
				return hr;

			VARIANT varVal;
			VariantInit(&varVal);
			varVal.vt = VT_BSTR;
			varVal.bstrVal = bstrConfigXML.Copy();

			hr = RequestXML(varVal, ConfigElementHandler);

			if(FAILED(hr))
				return hr;

			VariantInit(&varVal);
			VariantClear(&varVal);
			varVal.vt = VT_BSTR;
			varVal.bstrVal = bstrDataXML.Copy();
			hr = RequestXML(varVal, DataElementHandler);
		}
		else
		{
			hr = E_OUTOFMEMORY;
		}
	}

	return hr;
}

#if defined(DEBUG)
#import "..\MockSensors\Debug\MockSensors.tlb"
//#elif defined(NDEBUG)
//#import "..\MockSensors\Release\MockSensors.tlb"
//#else
//#error Either DEBUG or NDEBUG must be defined
#endif

HRESULT CDataConnector::RequestMockSensorsXML(const BSTR SensorId, IXMLElementHandler* ElementHandler, VARIANT_BOOL Data)
{
	HRESULT hr = E_OUTOFMEMORY;

#if defined(DEBUG)

	try
	{
		MockSensorsLib::IMockSensorPtr spMockSensor(__uuidof(MockSensorsLib::MockSensor));

		if(Data == VARIANT_TRUE)
		{
			_bstr_t bstrSensorPollData = spMockSensor->GetSensorPollData(SensorId);

			VARIANT varVal;
			VariantInit(&varVal);
			varVal.vt = VT_BSTR;
			varVal.bstrVal = bstrSensorPollData.copy(true);
			hr = RequestXML(varVal, ElementHandler);
		}
		else
		{
			_bstr_t bstrSensorConfigData = spMockSensor->GetSensorConfigData(SensorId);

			VARIANT varVal;
			VariantInit(&varVal);
			varVal.vt = VT_BSTR;
			varVal.bstrVal = bstrSensorConfigData.copy(true);
			hr = RequestXML(varVal, ElementHandler);
		}
	}
	catch (const _com_error&)
	{
		hr = E_FAIL;
	}
	catch (...)
	{
		hr = E_UNEXPECTED;
	}
#endif

	return hr;
}