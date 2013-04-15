// DataPoint.cpp : Implementation of CDataPoint

#include "stdafx.h"
#include "DataPoint.h"
#include "openxtra.h"

#include <comutils/comdate.h>
#include <boost/lexical_cast.hpp>


// CDataPoint

STDMETHODIMP CDataPoint::get_Value(VARIANT* pVal)
{
	VariantInit(pVal);
	
	VariantCopy(pVal, &m_varValue);
	
	return S_OK;
}

STDMETHODIMP CDataPoint::put_Value(VARIANT newVal)
{
	VariantClear(&m_varValue);
	VariantInit(&m_varValue);

	VariantCopy(&m_varValue, &newVal);

	return S_OK;
}

STDMETHODIMP CDataPoint::get_Unit(BSTR* pVal)
{
	if (pVal)
	{
		*pVal = m_bstrUnit.Copy();
		return S_OK;
	}
	else
		return E_OUTOFMEMORY;
}

STDMETHODIMP CDataPoint::put_Unit(BSTR newVal)
{
	CComBSTR bstrNewUnit(newVal);
	CComBSTR bstrOldUnit(m_bstrUnit);

	if(bstrNewUnit.Length() == 0/* || OPENXTRA::Maths::isEqual(m_varValue.dblVal, NO_VALUE_1) == true || OPENXTRA::Maths::isEqual(m_varValue.dblVal, NO_VALUE_2) == true*/)
		return E_INVALIDARG;

	if(m_bstrUnit == L"unknown" && (OPENXTRA::Constants::sUnitTemperatureTypes.Find(bstrNewUnit) != -1 || OPENXTRA::Constants::sUnitOtherTypes.Find(bstrNewUnit) != -1))
	{
		m_bstrUnit = newVal;
	}
	else
	{
		HRESULT hr = E_INVALIDARG;

		// see if they are compatible types
		if(OPENXTRA::Constants::sUnitTemperatureTypes.Find(m_bstrUnit) != -1)
		{
			CComBSTR bstrOldUnit(m_bstrUnit.Copy());
			VARIANT newVar;
			VariantInit(&newVar);
			VariantClear(&newVar);

			if(OPENXTRA::Maths::isEqual(m_varValue.dblVal, NO_VALUE_1) == true || OPENXTRA::Maths::isEqual(m_varValue.dblVal, NO_VALUE_2) == true)
			{				
				newVar.vt = VT_R8;
				newVar.dblVal = m_varValue.dblVal;
				hr = S_OK;
			}
			else
				hr = OPENXTRA::Temperature_Conversion::ConvertTemperature(m_varValue, bstrOldUnit, bstrNewUnit, &newVar);

			if(SUCCEEDED(hr))
			{
				
				m_bstrUnit = newVal;
				put_Value(newVar);
			}
		}
		else
		{
			HRESULT hr = E_INVALIDARG;
		}

		return hr;
	}

	return S_OK;
}

STDMETHODIMP CDataPoint::get_Time(DATE* pVal)
{
	if (pVal)
	{
		struct tm osTime;
		m_UTCDataTime.GetLocalTm(&osTime);
		*pVal = CComDATE( osTime );
		return S_OK;
	}
	else
		return E_OUTOFMEMORY;
}

STDMETHODIMP CDataPoint::put_Time(DATE newVal)
{
	return S_OK;
}

STDMETHODIMP CDataPoint::get_UTCTime(LONGLONG* pVal)
{
	if (pVal)
	{
		time_t Val = m_UTCDataTime.GetTime();
		*pVal = Val;
		return S_OK;
	}
	else
		return E_OUTOFMEMORY;
}

STDMETHODIMP CDataPoint::put_UTCTime(LONGLONG newVal)
{
	m_UTCDataTime = (time_t)newVal;

	return S_OK;
}

STDMETHODIMP CDataPoint::get_UTCTimeAsString(BSTR* pVal)
{
	CString sUTCTime(_T(""));

	time_t Val = m_UTCDataTime.GetTime();

	sUTCTime.Format(_T("%i"), Val);

	if(pVal)
	{
		*pVal = CComBSTR(sUTCTime).Copy();
		return S_OK;
	}
	else
		return E_OUTOFMEMORY;
}

STDMETHODIMP CDataPoint::put_UTCTimeAsString(BSTR newVal)
{
	try
	{
		LONGLONG Val = boost::lexical_cast<LONGLONG>(newVal);

		return put_UTCTime(Val);		
	}
	catch(boost::bad_lexical_cast&)
	{
		return E_OUTOFMEMORY;
	}
}
