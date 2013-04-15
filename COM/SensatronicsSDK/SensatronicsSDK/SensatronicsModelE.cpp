// SensatronicsModelE.cpp : Implementation of CSensatronicsModelE

#include "stdafx.h"
#include "SensatronicsModelE.h"
#include "openxtra.h"

#include "Probe.h"

// CSensatronicsModelE

STDMETHODIMP CSensatronicsModelE::Poll()
{
	return CSensatronicsDevice::Poll();
}

STDMETHODIMP CSensatronicsModelE::get_IpAddress(BSTR* pVal)
{
	if (pVal)
	{
		return m_bstrIpAddress.CopyTo(pVal);
	}
	else
		return E_OUTOFMEMORY;
}

STDMETHODIMP CSensatronicsModelE::put_IpAddress(BSTR newVal)
{
	CComBSTR Val(newVal);

	if(Val.Length() == 0 || Val == m_bstrIpAddress)
	{
		return E_INVALIDARG;
	}
	else
	{
		m_bstrIpAddress = Val;
		return S_OK;
	}
}

STDMETHODIMP CSensatronicsModelE::get_Name(BSTR* pVal)
{
	return CSensatronicsDevice::get_Name(pVal);
}

STDMETHODIMP CSensatronicsModelE::put_Name(BSTR newVal)
{
	return CSensatronicsDevice::put_Name(newVal);
}

STDMETHODIMP CSensatronicsModelE::get_Mask(BSTR* pVal)
{
	if (pVal)
	{
		return m_bstrMask.CopyTo(pVal);
	}
	else
		return E_OUTOFMEMORY;
}

STDMETHODIMP CSensatronicsModelE::put_Mask(BSTR newVal)
{
	CComBSTR Val(newVal);

	if(Val.Length() == 0 || Val == m_bstrMask)
	{
		return E_INVALIDARG;
	}
	else
	{
		m_bstrMask = Val;
		return S_OK;
	}
}

STDMETHODIMP CSensatronicsModelE::get_Gateway(BSTR* pVal)
{
	if (pVal)
	{
		return m_bstrGateway.CopyTo(pVal);
	}
	else
		return E_OUTOFMEMORY;
}

STDMETHODIMP CSensatronicsModelE::put_Gateway(BSTR newVal)
{
	CComBSTR Val(newVal);

	if(Val.Length() == 0 || Val == m_bstrGateway)
	{
		return E_INVALIDARG;
	}
	else
	{
		m_bstrGateway = Val;
		return S_OK;
	}
}

STDMETHODIMP CSensatronicsModelE::get_SerialNumber(BSTR* pVal)
{
	if (pVal)
	{
		return m_bstrSerialNumber.CopyTo(pVal);
	}
	else
		return E_OUTOFMEMORY;
}

STDMETHODIMP CSensatronicsModelE::get_SnmpTrapIpAddress(BSTR* pVal)
{
	if (pVal)
	{
		return m_bstrSnmpTrapAddress.CopyTo(pVal);
	}
	else
		return E_OUTOFMEMORY;
}

STDMETHODIMP CSensatronicsModelE::put_SnmpTrapIpAddress(BSTR newVal)
{
	CComBSTR Val(newVal);

	if(Val.Length() == 0 || Val == m_bstrSnmpTrapAddress)
	{
		return E_INVALIDARG;
	}
	else
	{
		m_bstrSnmpTrapAddress = Val;
		return S_OK;
	}
}

STDMETHODIMP CSensatronicsModelE::get_SnmpWriteCommunityString(BSTR* pVal)
{
	if (pVal)
	{
		return m_bstrSnmpWriteCommunityString.CopyTo(pVal);
	}
	else
		return E_OUTOFMEMORY;
}

STDMETHODIMP CSensatronicsModelE::put_SnmpWriteCommunityString(BSTR newVal)
{
	CComBSTR SnmpWriteCommunityString(newVal);

	if(SnmpWriteCommunityString.Length() > MAX_COMMUNITY_STRING)
	{
		return E_INVALIDARG;
	}
	else
	{
		m_bstrSnmpWriteCommunityString = SnmpWriteCommunityString;
		return S_OK;
	}
}

STDMETHODIMP CSensatronicsModelE::get_SnmpReadCommunityString(BSTR* pVal)
{
	if (pVal)
	{
		return m_bstrSnmpReadCommunityString.CopyTo(pVal);
	}
	else
		return E_OUTOFMEMORY;
}

STDMETHODIMP CSensatronicsModelE::put_SnmpReadCommunityString(BSTR newVal)
{
	CComBSTR SnmpReadCommunityString(newVal);

	if(SnmpReadCommunityString.Length() > MAX_COMMUNITY_STRING)
	{
		return E_INVALIDARG;
	}
	else
	{
		m_bstrSnmpReadCommunityString = SnmpReadCommunityString;
		return S_OK;
	}
}

STDMETHODIMP CSensatronicsModelE::get_SoftwareVersion(BSTR* pVal)
{
	if (pVal)
	{
		return m_bstrSoftwareVersion.CopyTo(pVal);
	}
	else
		return E_OUTOFMEMORY;
}

STDMETHODIMP CSensatronicsModelE::put_SoftwareVersion(BSTR newVal)
{
	CComBSTR Val(newVal);

	if(Val.Length() == 0 || Val == m_bstrSoftwareVersion)
	{
		return E_INVALIDARG;
	}
	else
	{
		m_bstrSoftwareVersion = Val;
		return S_OK;
	}
}

STDMETHODIMP CSensatronicsModelE::get_SoftwareReleaseDate(BSTR* pVal)
{
	if (pVal)
	{
		return m_bstrSoftwareReleaseDate.CopyTo(pVal);
	}
	else
		return E_OUTOFMEMORY;
}

STDMETHODIMP CSensatronicsModelE::put_SoftwareReleaseDate(BSTR newVal)
{
	CComBSTR Val(newVal);

	if(Val.Length() == 0 || Val == m_bstrSoftwareReleaseDate)
	{
		return E_INVALIDARG;
	}
	else
	{
		m_bstrSoftwareReleaseDate = Val;
		return S_OK;
	}
}




STDMETHODIMP CSensatronicsModelE::GetConfig(void)
{
	HRESULT hr = E_NOTIMPL;

	hr = GetXMLConfig();
	if(FAILED(hr))
	{
		// The device my not be supporting the XML interface so try the HTTP one

		GetHTTPConfigAndData();

		hr = S_OK;
	}

	return hr;
}

HRESULT CSensatronicsModelE::GetXMLConfig()
{
	HRESULT hr = S_OK;

	CComPtr<IDataConnector> pDataConnector = 0;
	hr = pDataConnector.CoCreateInstance(__uuidof(DataConnector));

	if(SUCCEEDED(hr))
	{
		CString sURL(_T(""));
		CXMLSensatronicsConfig XMLSensatronicsConfig;
		LONG* plHandler = (LONG*)&XMLSensatronicsConfig;	// so we can pass this through to

		sURL.Format(_T("http://%s/xmlconfig"), m_bstrIpAddress);

		hr = pDataConnector->RequestModelEXMLConfigData(m_bstrName.Copy(), CComBSTR(sURL), plHandler);

		if(SUCCEEDED(hr))
		{
			hr = ProcessConfig(&XMLSensatronicsConfig);
		}
	}

	return hr;
}

HRESULT CSensatronicsModelE::ProcessConfig(CXMLSensatronicsConfig* pXMLSensatronicsConfig)
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

			put_SoftwareVersion(CComBSTR(pXMLSensatronicsSensorConfig->getSensorFirmwareVersion()));

			put_SoftwareReleaseDate(CComBSTR(pXMLSensatronicsSensorConfig->getSensorFirmwareReleaseDate()));

			//if(m_bstrName != pXMLSensatronicsSensorConfig->getSensorName())
			if(m_bstrName == _T(""))
			{
				put_Name(CComBSTR(pXMLSensatronicsSensorConfig->getSensorName()));
			}

			CComBSTR(pXMLSensatronicsSensorConfig->getSensorId()).CopyTo(&m_bstrSerialNumber);

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

CXMLSensatronicsData* CSensatronicsModelE::GetData()
{
	HRESULT hr = S_OK;

	CXMLSensatronicsData* xmlSensatronicsData = GetXMLData();

	if(xmlSensatronicsData == NULL)
	{
		// The device my not be supporting the XML interface so try the HTTP one
		xmlSensatronicsData = GetHTTPConfigAndData();
	}

	return xmlSensatronicsData;
}

CXMLSensatronicsData* CSensatronicsModelE::GetXMLData()
{
	HRESULT hr = S_OK;

	CXMLSensatronicsData* xmlSensatronicsData = NULL;

	CComPtr<IDataConnector> pDataConnector = 0;
	hr = pDataConnector.CoCreateInstance(__uuidof(DataConnector));

	if(SUCCEEDED(hr))
	{
		CString sURL(_T(""));
		xmlSensatronicsData = new CXMLSensatronicsData;
		LONG* plHandler = (LONG*)xmlSensatronicsData;	// so we can pass this through to

		sURL.Format(_T("http://%s/xmldata"), m_bstrIpAddress);

		hr = pDataConnector->RequestModelEXMLData(m_bstrName.Copy(), CComBSTR(sURL), plHandler);

		if(SUCCEEDED(hr))
		{
#ifdef _DEBUG
			// Only display this in debug mode, this is just to check that the Parser worked
/*			const CXMLSensatronicsData::SensorsContainer& sensorsContainer = ptempXMLSensatronicsData->getSensorsContainer();

			CXMLSensatronicsData::SensorsContainer::const_iterator sensors_it = sensorsContainer.begin();

			for(; sensors_it != sensorsContainer.end(); ++sensors_it)
			{
				CXMLSensatronicsSensorData* pXMLSensatronicsSensorData = sensors_it->second;

				sTrace.Format(_T("Sensor %s"), pXMLSensatronicsSensorData->getSensorId());
				reportEvent(SERVEREVENTLOG, HotSpotEventLog_Info, L"CSensatronicsModelE::Poll", CComBSTR(sTrace));

				const CXMLSensatronicsSensorData::ProbesContainer& probesContainer = pXMLSensatronicsSensorData->getProbeElements();

				CXMLSensatronicsSensorData::ProbesContainer::const_iterator probes_it = probesContainer.begin();

				for(; probes_it != probesContainer.end(); ++probes_it)
				{
					CXMLSensatronicsProbeData* pXMLSensatronicsProbeData = probes_it->second;

					sTrace.Format(_T("   Probe %s Value = %s"), pXMLSensatronicsProbeData->getProbeId(), pXMLSensatronicsProbeData->getProbeValue());
					reportEvent(SERVEREVENTLOG, HotSpotEventLog_Info, L"CSensatronicsModelE::Poll", CComBSTR(sTrace));
				}

			}*/
#endif
		}
		else
		{
			delete xmlSensatronicsData;
			xmlSensatronicsData = NULL;
		}
	}

	return xmlSensatronicsData;
}

CXMLSensatronicsData* CSensatronicsModelE::GetHTTPConfigAndData(VARIANT_BOOL vbConfigOnly)
{
	HRESULT hr = S_OK;

	CXMLSensatronicsData* xmlSensatronicsData = NULL;

	CComPtr<IDataConnector> pDataConnector = 0;
	hr = pDataConnector.CoCreateInstance(__uuidof(DataConnector));

	if(SUCCEEDED(hr))
	{
		xmlSensatronicsData = new CXMLSensatronicsData;
		LONG* plDataHandler = (LONG*)xmlSensatronicsData;	// so we can pass this through to

		CXMLSensatronicsConfig XMLSensatronicsConfig;
		LONG* plConfigHandler = (LONG*)&XMLSensatronicsConfig;	// so we can pass this through to

		if(CString(_T("EM1")) == m_bstrModel)
		{
			hr = pDataConnector->RequestModelEHTTPConfigAndData(m_bstrName.Copy(), m_bstrIpAddress.Copy(), L"/config", L"/data", m_bstrModel.Copy(), plConfigHandler, plDataHandler);
		}
		else
		{
			hr = pDataConnector->RequestModelEHTTPConfigAndData(m_bstrName.Copy(), m_bstrIpAddress.Copy(), L"/config", L"/temp", m_bstrModel.Copy(), plConfigHandler, plDataHandler);
		}

		if(SUCCEEDED(hr))
		{
			hr = ProcessConfig(&XMLSensatronicsConfig);
		}
		else
		{
			delete xmlSensatronicsData;
			xmlSensatronicsData = NULL;
		}
	}

	return xmlSensatronicsData;
}

STDMETHODIMP CSensatronicsModelE::get_Model(BSTR* pVal)
{
	return CSensatronicsDevice::get_Model(pVal);
}

STDMETHODIMP CSensatronicsModelE::put_Model(BSTR newVal)
{
	return CSensatronicsDevice::put_Model(newVal);
}

STDMETHODIMP CSensatronicsModelE::get_Probe(SHORT probeId, IDispatch** pVal)
{
	return CSensatronicsDevice::get_Probe(probeId, pVal);
}

STDMETHODIMP CSensatronicsModelE::get_Probes(IDispatch** pVal)
{
	return CSensatronicsDevice::get_ProbeCollection(pVal);
}
