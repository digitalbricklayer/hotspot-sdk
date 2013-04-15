// ProbeCollection.h : Declaration of the CProbeCollection

#pragma once
#include "resource.h"       // main symbols

#include "SensatronicsSDK.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CProbeCollection

class ATL_NO_VTABLE CProbeCollection :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CProbeCollection, &CLSID_ProbeCollection>,
	public IConnectionPointContainerImpl<CProbeCollection>,
	public IDispatchImpl<IProbeCollection, &IID_IProbeCollection, &LIBID_SensatronicsSDKLib, 0xFFFF, 0xFFFF>
{
public:
	typedef std::map<SHORT, IProbe*> ProbeContainer;
public:
	CProbeCollection()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PROBECOLLECTION)


BEGIN_COM_MAP(CProbeCollection)
	COM_INTERFACE_ENTRY(IProbeCollection)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CProbeCollection)
END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		Clear();
	}

private:
	ProbeContainer m_map;
	void GetProbe(IProbe* pProbe, CComBSTR& bstrName);
public:
	STDMETHOD(get_Count)(LONG* pVal);
public:
	STDMETHOD(Add)(IProbe* pProbe);
public:
	STDMETHOD(Item)(VARIANT Index, IDispatch** pItem);
public:
	STDMETHOD(Remove)(VARIANT Index);
public:
	STDMETHOD(Clear)(void);
public:
	STDMETHOD(get__NewEnum)(LPUNKNOWN* pVal);
public:
	STDMETHOD(ItemByNumber)(VARIANT Index, IDispatch** pItem);
};

OBJECT_ENTRY_AUTO(__uuidof(ProbeCollection), CProbeCollection)
