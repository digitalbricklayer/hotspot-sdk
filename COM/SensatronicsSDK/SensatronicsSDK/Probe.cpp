// Probe.cpp : Implementation of CProbe

#include "stdafx.h"
#include "Probe.h"
#include "openxtra.h"
#include "DataConnector.h"


// CProbe

STDMETHODIMP CProbe::get_Name(BSTR* pVal)
{
	if (pVal)
	{
		*pVal = m_bstrName.Copy();
		return S_OK;
	}
	else
		return E_OUTOFMEMORY;
}

STDMETHODIMP CProbe::put_Name(BSTR newVal)
{
	CComBSTR name(newVal);

	if(name.Length() == 0 || name.Length() > MAX_PROBE_NAME || name == m_bstrName)
	{
		return E_INVALIDARG;
	}
	else
	{
		m_bstrName = name;
		return S_OK;
	}
}

STDMETHODIMP CProbe::get_Type(BSTR* pVal)
{
	if (pVal)
	{
		*pVal = m_bstrType.Copy();
		return S_OK;
	}
	else
		return E_OUTOFMEMORY;

}

STDMETHODIMP CProbe::put_Type(BSTR newVal)
{
	CComBSTR type(newVal);
	CComBSTR old(m_bstrType);

	// return error if the new type is empty, is not a valid type or is already that type
	if(type.Length() == 0 || OPENXTRA::Constants::sProbeValidTypes.Find(type) == -1 || type == old)
	{
		return E_INVALIDARG;
	}
	else
	{
		m_bstrType = type;
		return S_OK;
	}
}

STDMETHODIMP CProbe::get_Number(SHORT* pVal)
{
	if (pVal)
	{
		*pVal = m_sintNumber;
		return S_OK;
	}
	else
	{
		return E_OUTOFMEMORY;
	}
}

STDMETHODIMP CProbe::put_Number(SHORT newVal)
{
	m_sintNumber = newVal;
	return S_OK;
}

STDMETHODIMP CProbe::Poll(IDataPoint* pDataPoint)
{
	HRESULT hr = E_OUTOFMEMORY;

	//FireEvent_OnPollBegin();

	if(m_pMostRecentDataPoint)
	{
		m_pMostRecentDataPoint.Release();

		hr = pDataPoint->QueryInterface(IID_IDataPoint, (void**) &m_pMostRecentDataPoint);
	}
	else
	{
		hr = pDataPoint->QueryInterface(IID_IDataPoint, (void**) &m_pMostRecentDataPoint);
	}

	//FireEvent_OnPollEnd();

	return hr;
}

STDMETHODIMP CProbe::get_Group(LONG* pVal)
{
	if(pVal)
	{
		*pVal = m_longGroup;
		return S_OK;
	}
	else
		return E_INVALIDARG;
}

STDMETHODIMP CProbe::put_Group(LONG newVal)
{
	m_longGroup = newVal;

	return S_OK;
}

STDMETHODIMP CProbe::get_MostRecentDataPoint(IDataPoint** pVal)
{
	if (pVal && m_pMostRecentDataPoint)
	{
		HRESULT hr = E_OUTOFMEMORY;

		hr = m_pMostRecentDataPoint->QueryInterface(IID_IDataPoint, (void**) pVal);

		return hr;
	}
	else
		return E_OUTOFMEMORY;
}
