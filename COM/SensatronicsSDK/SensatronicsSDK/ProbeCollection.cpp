// ProbeCollection.cpp : Implementation of CProbeCollection

#include "stdafx.h"
#include "ProbeCollection.h"


// CProbeCollection

void CProbeCollection::GetProbe(IProbe* pProbe, CComBSTR& bstrName)
{
	pProbe->get_Name(&bstrName);
}

STDMETHODIMP CProbeCollection::get_Count(LONG* pVal)
{
	if (pVal == NULL)
		return E_POINTER;

	*pVal = (long)m_map.size();

	return S_OK;
}

STDMETHODIMP CProbeCollection::Add(IProbe* pProbe)
{
	HRESULT hr = S_OK;

	if (pProbe == NULL)
		return E_POINTER;

	CComBSTR bstrName;
	GetProbe(pProbe, bstrName);

	SHORT nProbeNumber = -1;
	pProbe->get_Number(&nProbeNumber);

	if(bstrName.Length() == 0)
	{
		return E_INVALIDARG;
	}

	ProbeContainer::const_iterator it = m_map.begin();

	if(nProbeNumber == -1)
	{
		// Right we need to give this probe a valid id, so search through
		// the map until we find a free one

		for(nProbeNumber = 1; it != m_map.end(); nProbeNumber ++)
		{
			it = m_map.find(nProbeNumber);
		}

		// find the first free id, so lets give the probe that id
		pProbe->put_Number(nProbeNumber);
	}

	// find if probe already exists
	it = m_map.find(nProbeNumber);

	if(it == m_map.end())
	{
		m_map[nProbeNumber] = pProbe;

		pProbe->AddRef();
	}
	else	// already exists so dont add
	{
		return E_INVALIDARG;
	}

	return S_OK;
}

// Passing VT_I4 will search the index, i.e. if you want the probe at index 2
// Passing VT_I2 will search the probe number, i.e. if you want the probe whose probe number is 3
// Passing VT_BSTR will search for the probe name
STDMETHODIMP CProbeCollection::Item(VARIANT Index, IDispatch** pItem)
{
	// search the index
	if(Index.vt == VT_I4)
	{
		// 1 based index
		if(Index.lVal <= (LONG)m_map.size() && Index.lVal > 0)
		{
			LONG lCount = 1;
			ProbeContainer::iterator it;

			for(lCount = 1, it = m_map.begin(); it != m_map.end(); it++, lCount++)
			{
				if(lCount == Index.lVal)
				{
					// found it, copy the object into pItem
					IProbe* pProbe;

					pProbe = (*it).second;

					//put the IDispatch into pItem (also implicit AddRef())
					return pProbe->QueryInterface(IID_IDispatch,
						(void**) pItem);
				}
			}
		}
		else // Index out of range
			return E_INVALIDARG;
	}
	else if(Index.vt == VT_I2)	// search for the actual probe number
	{
		// 1 based index
		if(Index.iVal <= (SHORT)m_map.size() && Index.iVal > 0)
		{
			SHORT sCount = 1;
			ProbeContainer::iterator it;

			for(sCount = 1, it = m_map.begin(); it != m_map.end(); it++, sCount++)
			{
				if(sCount == Index.iVal)
				{
					// found it, copy the object into pItem
					IProbe* pProbe;

					pProbe = (*it).second;

					//put the IDispatch into pItem (also implicit AddRef())
					return pProbe->QueryInterface(IID_IDispatch,
						(void**) pItem);
				}
			}
		}
		else // Index out of range
			return E_INVALIDARG;
	}
	// check to see if a string has been passed
	else if(Index.vt == VT_BSTR)
	{
		ProbeContainer::iterator it;

		for(it = m_map.begin(); it != m_map.end(); it++)
		{
			IProbe* pProbe;

			pProbe = (*it).second;

			CComBSTR bstrName(_T(""));
			pProbe->get_Name(&bstrName);

			if(bstrName == Index.bstrVal)
			{
				// found it, copy the object into pItem
				IProbe* pProbe;

				pProbe = (*it).second;

				//put the IDispatch into pItem (also implicit AddRef())
				return pProbe->QueryInterface(IID_IDispatch,
					(void**) pItem);
			}
		}

		return E_INVALIDARG;
	}
	else // unrecognised index type
	{
		return E_INVALIDARG;
	}

	return S_OK;
}

STDMETHODIMP CProbeCollection::Remove(VARIANT Index)
{
	// Check to see if a number has been passed
	if(Index.vt == VT_I4)
	{
		ProbeContainer::iterator it;

		// look for an intem with this key

		it = m_map.find((SHORT)Index.lVal);
		if(it == m_map.end())
		{
			// cant find it
			return E_INVALIDARG;
		}
		IProbe* pProbe;

		pProbe = (*it).second;

		ATLASSERT(pProbe != NULL);

		CComBSTR bstrName(L"");
		pProbe->get_Name(&bstrName);

		pProbe->Release();
			
		m_map.erase(it);

		return S_OK;
	}

	// Check to see if a number has been passed
	if(Index.vt == VT_I2)
	{
		ProbeContainer::iterator it;

		// look for an intem with this key

		it = m_map.find(Index.iVal);
		if(it == m_map.end())
		{
			// cant find it
			return E_INVALIDARG;
		}
		IProbe* pProbe;

		pProbe = (*it).second;

		ATLASSERT(pProbe != NULL);

		CComBSTR bstrName(L"");
		pProbe->get_Name(&bstrName);

		pProbe->Release();
			
		m_map.erase(it);

		return S_OK;
	}

	// check to see if a string has been passed
	else if(Index.vt == VT_BSTR)
	{
		ProbeContainer::iterator it;

		for(it = m_map.begin(); it != m_map.end(); it++)
		{
			IProbe* pProbe;

			pProbe = (*it).second;

			CComBSTR bstrName(_T(""));
			pProbe->get_Name(&bstrName);

			if(bstrName == Index.bstrVal)
			{
				// found it, release the object
				CComBSTR bstrName(L"");
				pProbe->get_Name(&bstrName);

				pProbe->Release();
					
				m_map.erase(it);

				//put the IDispatch into pItem (also implicit AddRef())
				return S_OK;
			}
		}

		return E_INVALIDARG;
	}
	else // unrecognised index type
		return E_INVALIDARG;

	return S_OK;
}

STDMETHODIMP CProbeCollection::Clear(void)
{
	ProbeContainer::iterator it;

	for(it = m_map.begin(); it != m_map.end(); it++)
	{
		IProbe *pProbe = (it)->second;

		CComBSTR bstrName(L"");
		pProbe->get_Name(&bstrName);

		pProbe->Release();
	}

	m_map.clear();

	return S_OK;
}

STDMETHODIMP CProbeCollection::get__NewEnum(LPUNKNOWN* pVal)
{
	size_t lCount = m_map.size();

	// temp array to hold the objects

	VARIANT* var = new VARIANT[lCount];
	ProbeContainer::iterator it;
	int i = 0;

	// fill temp array with the objects
	for(it = m_map.begin(); it != m_map.end(); it++, i++)
	{
		IProbe* pProbe = (*it).second;
		VariantInit(&var[i]);
		var[i].vt = VT_DISPATCH;

		// VARIANT holds IDispatch pointers, also QI AddRef()s
		pProbe->QueryInterface(IID_IDispatch, (void**)&(var[i].pdispVal));
	}

	typedef CComObject< CComEnum<	IEnumVARIANT,
									&IID_IEnumVARIANT,
									VARIANT,
									_Copy<VARIANT> > > EnumVar;

	// create new instance
	EnumVar* pVar = new EnumVar;

	//init with the objects, a copy will be made
	pVar->Init(&var[0], &var[i], NULL, AtlFlagCopy);

#if 0
	lCount--;
	while(lCount >= 0)
	{
		VariantClear(&var[lCount]);
		lCount--;
	}
#else
	// now release objects in temp array
	for (size_t i = 0; i < lCount; i++)
	{
		VariantClear(&var[i]);
	}
#endif
	delete [] var;

	//return the IUnknown for the enumerator
	pVar->QueryInterface(IID_IUnknown, (void**)pVal);

	// we do not delete pVar, this is not a leak!
	return S_OK;
}

STDMETHODIMP CProbeCollection::ItemByNumber(VARIANT IndexVariant, IDispatch** pItem)
{
	SHORT Index;

	if (IndexVariant.vt == VT_I2)
	{
		Index = IndexVariant.iVal;
	}
	else if (IndexVariant.vt == VT_I4)
	{
		Index = (SHORT)IndexVariant.lVal;
	}
	else
	{
		ATLASSERT(FALSE);
		Index = 1;
	}

	// indexed by name
	ProbeContainer::iterator it;

	// look for an item with this key
	it = m_map.find(Index);
	if(it == m_map.end())
	{
		// cant find it
		return E_INVALIDARG;
	}

	IProbe* pProbe;

	pProbe = (*it).second;

	//put the IDispatch into pItem (also implicit AddRef())
	return pProbe->QueryInterface(IID_IDispatch, (void**) pItem);
}
