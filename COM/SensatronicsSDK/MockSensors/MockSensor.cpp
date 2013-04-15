// MockSensor.cpp : Implementation of CMockSensor

#include "stdafx.h"
#include "MockSensor.h"
#include "..\SensatronicsSDK\XMLParser.h"
#include "..\SensatronicsSDK\XMLSensatronicsData.h"
#include "..\SensatronicsSDK\XMLSensatronicsConfig.h"


// CMockSensor

STDMETHODIMP CMockSensor::AddSensor(BSTR SensorId, BSTR ConfigData, BSTR PollData, DATE Time)
{
	HRESULT hr = S_OK;

	hr = CreateSensor(SensorId);

	AddConfigData(SensorId, ConfigData);

	AddSensorPollData(SensorId, PollData, Time);

	return hr;
}

STDMETHODIMP CMockSensor::AddSensorPollData(BSTR SensorId, BSTR PollData, DATE Time)
{
	HRESULT hr = S_OK;

	CString sTrace(_T(""));

	CComBSTR bstrSensorPollData(PollData);

	if(bstrSensorPollData.Length() <= 0)
		return E_INVALIDARG;

	CComBSTR bstrSensorId(SensorId);

	MockDataContainer::iterator MockDataContainer_it = m_Data.find(bstrSensorId);

	if(MockDataContainer_it == m_Data.end())
	{
		CreateSensor(bstrSensorId.Copy());

		MockDataContainer_it = m_Data.find(bstrSensorId);

		ATLASSERT(MockDataContainer_it != m_Data.end());

		MockDataContainer_it->second.push_back(bstrSensorPollData.Copy());
		
		// this sets up the MockManager to act as the Poll controller
		m_nPollCount = 0;
		m_TimeStamp.push_back(Time);
		SetMaxPollCount();
	}
	else
	{
		MockDataContainer_it->second.push_back(bstrSensorPollData.Copy());

		// this sets up the MockManager to act as the Poll controller
		m_nPollCount = 0;
		m_TimeStamp.push_back(Time);
		SetMaxPollCount();
	}

	return hr;
}

STDMETHODIMP CMockSensor::GetSensorPollData(BSTR SensorId, BSTR* PollData)
{
	HRESULT hr = E_OUTOFMEMORY;

	if(PollData)
	{
		MockDataContainer::iterator it = m_Data.find(SensorId);

		if(it != m_Data.end())
		{
			DataContainer& data = it->second;

			size_t s = data.size();
			if(data.size() > 0)
			{
				data[0].CopyTo(PollData);

				data.erase(data.begin());
				
				s = data.size();

				hr = S_OK;
			}
			else
				hr = E_NOTIMPL;	// The sensor exists but there is no data to return
		}
		else
		{
			hr = E_NOTIMPL;
		}
	}
	else
		hr = E_OUTOFMEMORY;

	SetMaxPollCount();

	return hr;
}

void CMockSensor::SetMaxPollCount(void) 
{
	HRESULT hr = S_OK;

	if(m_nPollCount != -1)
	{
		m_nPollCount = 0;

		MockDataContainer::iterator MockDataContainer_it = m_Data.begin();

		for(; MockDataContainer_it != m_Data.end(); MockDataContainer_it++)
		{
			DataContainer& data = MockDataContainer_it->second;

			size_t nCount = data.size();

			if(m_nPollCount < (UINT)nCount )
				m_nPollCount = (UINT)nCount;
		}

		if(m_nPollCount == 0)
		{
			m_TimeStamp.clear();
		}
	}
}

STDMETHODIMP CMockSensor::get_PollCount(ULONG* pVal)
{
	if(pVal)
	{
		*pVal = m_nPollCount;

		return S_OK;
	}
	else
		return E_OUTOFMEMORY;
}

STDMETHODIMP CMockSensor::put_PollCount(ULONG newVal)
{
	// TODO: Add your implementation code here

	return S_OK;
}

HRESULT CMockSensor::AddConfigData(BSTR SensorId, BSTR ConfigData)
{
	HRESULT hr = S_OK;

	CString sTrace(_T(""));

	CComBSTR bstrSensorConfigData(ConfigData);
	CComBSTR bstrSensorId(SensorId);

	if(bstrSensorConfigData.Length() <= 0 && bstrSensorId.Length() <= 0)
		return E_OUTOFMEMORY;

	m_Config[bstrSensorId.Copy()] = bstrSensorConfigData.Copy();

	return hr;
}

STDMETHODIMP CMockSensor::GetSensorConfigData(BSTR SensorId, BSTR* ConfigData)
{
	HRESULT hr = E_OUTOFMEMORY;

	if(ConfigData)
	{
		MockConfigContainer::iterator it = m_Config.find(SensorId);

		if(it != m_Config.end())
		{
			if(it->second.Length() > 0)
			{
				hr = it->second.CopyTo(ConfigData);
			}
			else
				hr = E_NOTIMPL;
		}
		else
		{
			hr = E_NOTIMPL;
		}
	}
	else
		hr = E_OUTOFMEMORY;

	return hr;
}

STDMETHODIMP CMockSensor::GetTimeStamp(DATE* TimeStamp)
{
	HRESULT hr = E_OUTOFMEMORY;

	if(TimeStamp)
	{
		if(m_TimeStamp.size() > 0)
		{
			*TimeStamp = m_TimeStamp[0];

			m_TimeStamp.erase(m_TimeStamp.begin());

			hr = S_OK;
		}
		else
		{
			hr = E_NOTIMPL;
		}
	}
	else
		hr = E_OUTOFMEMORY;

	return hr;
}

HRESULT CMockSensor::CreateSensor(BSTR SensorId)
{
	HRESULT hr = S_OK;
	CComBSTR bstrSensorId(SensorId);

	MockDataContainer::iterator MockDataContainer_it = m_Data.find(bstrSensorId);

	if(MockDataContainer_it == m_Data.end())
	{
		// this is a new so add it
		m_Data[bstrSensorId.Copy()] = DataContainer();

		MockDataContainer_it = m_Data.find(bstrSensorId);

		ATLASSERT(MockDataContainer_it != m_Data.end());

		hr = S_OK;
	}
	else
	{
		hr = S_OK;
	}

	return hr;
}

