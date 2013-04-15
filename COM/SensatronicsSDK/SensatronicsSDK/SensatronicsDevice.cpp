// SensatronicsDevice.cpp : Implementation of CSensatronicsDevice

#include "stdafx.h"
#include "SensatronicsDevice.h"

#include "openxtra.h"


// CSensatronicsDevice

HRESULT CSensatronicsDevice::ProcessProbeConfig(CXMLSensatronicsProbeConfig* pXMLSensatronicsProbeConfig, bool* pbTempUnitSet)
{
	SHORT nId = -1;
	LONG nGroup = -1;

	HRESULT hr = S_OK;

	try
	{
		// convert both the Probe and Group ID for use later
		std::wstring sValue(pXMLSensatronicsProbeConfig->getProbeId());
		nId = boost::lexical_cast<short>(sValue);

		sValue = pXMLSensatronicsProbeConfig->getProbeGroup();
		nGroup = boost::lexical_cast<short>(sValue);
	}
	catch(boost::bad_lexical_cast&)
	{
		nId = -1;
		nGroup = 0;
	}

	if(nId != -1)
	{
		CString sProbeUnit(pXMLSensatronicsProbeConfig->getProbeUnits());

		// because all probes will use the same temperature unit, we only need to do this once
		if(CString(pXMLSensatronicsProbeConfig->getProbeType()) == _T("Temperature") && *pbTempUnitSet == false)
		{
			if(sProbeUnit.Find(_T("C")) != -1)
			{
				m_bstrUnit = L"C";
			}
			else if(sProbeUnit.Find(_T("K")) != -1)
			{
				m_bstrUnit = L"K";
			}
			else if(sProbeUnit.Find(_T("F")) != -1)
			{
				m_bstrUnit = L"F";
			}
			else if(sProbeUnit.Find(_T("R")) != -1)
			{
				m_bstrUnit = L"R";
			}										
			else
			{
				// this should never happen
				ATLASSERT(false);
				m_bstrUnit = L"";
			}

			// we dont need to do this again during this call
			*pbTempUnitSet = true;
		}

		VARIANT varId;
		VariantClear(&varId);

		varId.vt = VT_I2;
		varId.iVal = nId;

		// lets see if the probe already exists
		struct IDispatch* _probe = 0;
		hr = m_pProbes->ItemByNumber(varId, &_probe);

		if(SUCCEEDED(hr))
		{
			// it does so update it
			CComQIPtr<IProbe> spProbe = _probe;
			_probe->Release();

			spProbe->put_Name(CComBSTR(pXMLSensatronicsProbeConfig->getProbeName()));						
		}
		else
		{
			// it doesnt exist so we need to create it and add it
			CComPtr<IProbe> spProbe = 0;
			hr = spProbe.CoCreateInstance(__uuidof(Probe));

			if(SUCCEEDED(hr))
			{
				spProbe->put_Type(CComBSTR(pXMLSensatronicsProbeConfig->getProbeType()));
				spProbe->put_Name(CComBSTR(pXMLSensatronicsProbeConfig->getProbeName()));
				spProbe->put_Number(nId);
				spProbe->put_Group(nGroup);

				hr = AddProbe(spProbe);
			}
		}
	}
	else
	{
		ATLASSERT(false);
		hr = E_INVALIDARG;
	}

	return hr;
}

HRESULT CSensatronicsDevice::AddProbe(IProbe* pProbe)
{
	if(pProbe)
	{
		return m_pProbes->Add(pProbe);
	}
	else
		return E_OUTOFMEMORY;
}

STDMETHODIMP CSensatronicsDevice::Poll()
{
	HRESULT hr = S_OK;

	CTime currentDate = CTime::GetCurrentTime();

	hr = GetConfig();

	if(FAILED(hr))
		return hr;

	CXMLSensatronicsData* xmlSensatronicsData = GetData();

	if(xmlSensatronicsData != NULL)
	{
		LONG lCount = 0;
		m_pProbes->get_Count(&lCount);

		VARIANT Index;
		VariantInit(&Index);
		Index.vt = VT_I2;

		for(Index.iVal = 1; Index.iVal <= lCount; Index.iVal++)
		{
			struct IDispatch * _result = 0;
			hr = m_pProbes->ItemByNumber(Index, &_result);
			if(SUCCEEDED(hr))
			{
				CComQIPtr<IProbe> spProbe = _result;

				CComPtr<IDataPoint> pDataPoint;

				CString sId(_T(""));

				SHORT probeID = 0;

				spProbe->get_Number(&probeID);

				sId.Format(_T("%d"), probeID);

				if(SUCCEEDED(GetProbeData(spProbe, xmlSensatronicsData, &pDataPoint)))
				{
					pDataPoint->put_UTCTime(currentDate.GetTime());

					spProbe->Poll(pDataPoint);
				}
				
				_result->Release();
			}
		}
	}
	else
		hr = E_FAIL;

	delete xmlSensatronicsData;
	xmlSensatronicsData = NULL;

	return hr;
}

STDMETHODIMP CSensatronicsDevice::GetProbeData(IProbe* spProbe, CXMLSensatronicsData* xmlSensatronicsData, IDataPoint** pDataPoint)
{
	HRESULT hr = E_OUTOFMEMORY;

	if(xmlSensatronicsData)
	{
		CString sProbeId(_T(""));
		SHORT ProbeId = 0;
		spProbe->get_Number(&ProbeId);
		sProbeId.Format(_T("%d"), ProbeId);

		const CXMLSensatronicsData::SensorsContainer& sensorsContainer = xmlSensatronicsData->getSensorsContainer();

		CXMLSensatronicsData::SensorsContainer::const_iterator sensors_it = sensorsContainer.begin();

		// Should only be one
		//if(sensorsContainer.size() == 1)
		{
			for(; sensors_it != sensorsContainer.end(); ++sensors_it)
			{
				CXMLSensatronicsSensorData* pXMLSensatronicsSensorData = sensors_it->second;

				const CXMLSensatronicsSensorData::ProbesContainer& probesContainer = pXMLSensatronicsSensorData->getProbeElements();

				CXMLSensatronicsSensorData::ProbesContainer::const_iterator probes_it = probesContainer.begin();

				probes_it = probesContainer.find(CComBSTR(sProbeId).Copy());
				
				if(probes_it != probesContainer.end())
				{
					CXMLSensatronicsProbeData* pXMLSensatronicsProbeData = probes_it->second;
					if(sProbeId == pXMLSensatronicsProbeData->getProbeId())
					{
						double nValue = 0;
						CComBSTR bstrValue(pXMLSensatronicsProbeData->getProbeValue());

						try
						{
							std::wstring sValue(bstrValue);

							nValue = boost::lexical_cast<double>(sValue);
						}
						catch(boost::bad_lexical_cast& e)
						{
							// Built in MACRO to convert ANSI to Unicode
							CA2T pszaErr( e.what() );
							//return E_INVALIDARG;
						}						

						VARIANT Value;
						VariantInit(&Value);
						Value.vt = VT_R8;
						Value.dblVal = nValue;

						CComPtr<IDataPoint> spDataPoint;
						hr = spDataPoint.CoCreateInstance(__uuidof(DataPoint));

						if(SUCCEEDED(hr))
						{
							spDataPoint->put_Value(Value);							

							if(spProbe)
							{
								CComBSTR bstrProbeType(_T(""));
								spProbe->get_Type(&bstrProbeType);

								if(bstrProbeType == _T("Temperature"))
								{
									// first set the unit to what is on the physical device
									spDataPoint->put_Unit(m_bstrUnit);
								}
								else if(bstrProbeType == _T("Humidity"))
								{
									spDataPoint->put_Unit(_T("H"));
								}
								else if(bstrProbeType == _T("Wetness"))
								{
									spDataPoint->put_Unit(_T("W"));
								}
								else
								{
								}
							}

							return spDataPoint->QueryInterface(IID_IDataPoint,
								(void**) pDataPoint);
						}
						return E_OUTOFMEMORY;
					}
				}
			}
		}
	}
	//else
	//{
	//	hr = E_OUTOFMEMORY;
	//}

	return hr;
}

STDMETHODIMP CSensatronicsDevice::get_Model(BSTR* pVal)
{
	if (pVal)
	{
		return m_bstrModel.CopyTo(pVal);
	}
	else
		return E_OUTOFMEMORY;
}

STDMETHODIMP CSensatronicsDevice::put_Model(BSTR newVal)
{
	CComBSTR model(newVal);

	if(model.Length() == 0 || 
		((OPENXTRA::Constants::sSerialModelTypes.Find(model) == -1) && (OPENXTRA::Constants::sEthernetModelTypes.Find(model) == -1)))
	{
		return E_INVALIDARG;
	}
	else
	{

		m_bstrModel = model;
		return S_OK;
	}
}

STDMETHODIMP CSensatronicsDevice::get_Name(BSTR* pVal)
{
	if (pVal)
	{
		return m_bstrName.CopyTo(pVal);
	}
	else
		return E_OUTOFMEMORY;
}

STDMETHODIMP CSensatronicsDevice::put_Name(BSTR newVal)
{
	CComBSTR name(newVal);

	if(name.Length() == 0 || name.Length() > MAX_SENSOR_NAME  || name == m_bstrName)
	{
		return E_INVALIDARG;
	}
	else
	{
		m_bstrName = name;
		return S_OK;
	}
}

STDMETHODIMP CSensatronicsDevice::get_ProbeCollection(IDispatch** pVal)
{
	*pVal = m_pProbes;
	(*m_pProbes).AddRef();

	return S_OK;
}

STDMETHODIMP CSensatronicsDevice::get_Probe(SHORT probeId, IDispatch** pVal)
{
	VARIANT Index;
	VariantInit(&Index);
	Index.vt = VT_I2;
	Index.iVal = probeId;
	return m_pProbes->ItemByNumber(Index, pVal);
}
