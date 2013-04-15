// SensatronicsModelF.cpp : Implementation of CSensatronicsModelF

#include "stdafx.h"
#include "SensatronicsModelF.h"
#include "openxtra.h"

#include "Probe.h"

// CSensatronicsModelF

STDMETHODIMP CSensatronicsModelF::Poll()
{
	return CSensatronicsDevice::Poll();
}

STDMETHODIMP CSensatronicsModelF::get_Name(BSTR* pVal)
{
	return CSensatronicsDevice::get_Name(pVal);
}

STDMETHODIMP CSensatronicsModelF::put_Name(BSTR newVal)
{
	return CSensatronicsDevice::put_Name(newVal);
}

STDMETHODIMP CSensatronicsModelF::get_ComPort(BSTR* pVal)
{
	return m_bstrComPort.CopyTo(pVal);
}

STDMETHODIMP CSensatronicsModelF::put_ComPort(BSTR newVal)
{
	std::wstring ComPort(newVal);

	int nComPort = -1;

	if(ComPort.length() == 0)
	{
		return E_INVALIDARG;
	}
	else
	{
		try
		{
			nComPort = boost::lexical_cast<int>(ComPort);
		}
		catch(boost::bad_lexical_cast&)
		{
			return E_INVALIDARG;
		}

		if(nComPort <= 0)
			return E_INVALIDARG;

		m_bstrComPort = CComBSTR(ComPort.c_str()).Copy();
		return S_OK;
	}
}

STDMETHODIMP CSensatronicsModelF::get_BatteryStatus(BSTR* pVal)
{
	if (pVal)
	{
		return m_bstrBatteryStatus.CopyTo(pVal);
	}
	else
		return E_OUTOFMEMORY;
}

CXMLSensatronicsData* CSensatronicsModelF::GetSerialComData(void)
{
	HRESULT hr = S_OK;

	CXMLSensatronicsData* xmlSensatronicsData = NULL;

	CComPtr<IDataConnector> pDataConnector = 0;
	hr = pDataConnector.CoCreateInstance(__uuidof(DataConnector));

	if(SUCCEEDED(hr))
	{
		xmlSensatronicsData = new CXMLSensatronicsData;
		LONG* plDataHandler = (LONG*)xmlSensatronicsData;	// so we can pass this through to

		hr = pDataConnector->RequestModelFSerialComData(m_bstrName.Copy(), m_bstrComPort.Copy(), plDataHandler);

		if(SUCCEEDED(hr))
		{
			const CXMLSensatronicsData::SensorsContainer& sensorsContainer = xmlSensatronicsData->getSensorsContainer();

			CXMLSensatronicsData::SensorsContainer::const_iterator sensors_it = sensorsContainer.begin();

			if(sensors_it != sensorsContainer.end())
			{
				CXMLSensatronicsSensorData* pXMLSensatronicsSensorData = sensors_it->second;

				m_bstrBatteryStatus = pXMLSensatronicsSensorData->getBatteryStatus();
			}
		}
		else
		{
			delete xmlSensatronicsData;
			xmlSensatronicsData = NULL;
		}
	}

	return xmlSensatronicsData;
}

STDMETHODIMP CSensatronicsModelF::GetConfig(void)
{
	HRESULT hr = S_OK;

	CString sTrace(_T(""));

	CComPtr<IDataConnector> pDataConnector = 0;
	hr = pDataConnector.CoCreateInstance(__uuidof(DataConnector));

	if(SUCCEEDED(hr))
	{
		CXMLSensatronicsConfig XMLSensatronicsConfig;
		LONG* plConfigHandler = (LONG*)&XMLSensatronicsConfig;	// so we can pass this through to

		hr = pDataConnector->RequestModelFSerialComConfigData(m_bstrName.Copy(), m_bstrComPort.Copy(), plConfigHandler);

		if(SUCCEEDED(hr))
		{
			hr = ProcessConfig(&XMLSensatronicsConfig);
		}
	}

	return hr;
}

HRESULT CSensatronicsModelF::ProcessConfig(CXMLSensatronicsConfig* pXMLSensatronicsConfig)
{
	CString sTrace(_T(""));

	HRESULT hr = S_OK;
	bool bTempUnitSet = false;

	if(pXMLSensatronicsConfig)
	{
		const CXMLSensatronicsConfig::SensorsContainer& sensorsContainer = pXMLSensatronicsConfig->getSensorsContainer();

		CXMLSensatronicsConfig::SensorsContainer::const_iterator sensors_it = sensorsContainer.begin();

		if(sensors_it != sensorsContainer.end())
		{
			CXMLSensatronicsSensorConfig* pXMLSensatronicsSensorConfig = sensors_it->second;

			const CXMLSensatronicsSensorConfig::ProbesContainer& probesContainer = pXMLSensatronicsSensorConfig->getProbeElements();

			CXMLSensatronicsSensorConfig::ProbesContainer::const_iterator probes_it = probesContainer.begin();

			for(; probes_it != probesContainer.end(); ++probes_it)
			{
				CXMLSensatronicsProbeConfig* pXMLSensatronicsProbeConfig = probes_it->second;

				hr = ProcessProbeConfig(pXMLSensatronicsProbeConfig, &bTempUnitSet);
			}

		}
	}

	return hr;
}

CXMLSensatronicsData* CSensatronicsModelF::GetData()
{
	return GetSerialComData();
}

STDMETHODIMP CSensatronicsModelF::get_Model(BSTR* pVal)
{
	return CSensatronicsDevice::get_Model(pVal);
}

STDMETHODIMP CSensatronicsModelF::get_Probe(SHORT probeId, IDispatch** pVal)
{
	return CSensatronicsDevice::get_Probe(probeId, pVal);
}

STDMETHODIMP CSensatronicsModelF::get_Probes(IDispatch** pVal)
{
	return CSensatronicsDevice::get_ProbeCollection(pVal);
}