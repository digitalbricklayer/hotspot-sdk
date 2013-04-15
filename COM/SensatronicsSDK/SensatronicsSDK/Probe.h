// Probe.h : Declaration of the CProbe

#pragma once
#include "resource.h"       // main symbols

#include "SensatronicsSDK.h"
#include "_IProbeEvents_CP.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CProbe

#if 0
class ATL_NO_VTABLE CProbe :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CProbe, &CLSID_Probe>,
	public IConnectionPointContainerImpl<CProbe>,
	public CProxy_IProbeEvents<CProbe>,
	public IDispatchImpl<IProbe, &IID_IProbe, &LIBID_SensatronicsSDKLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IDispatchImpl<_IProbeEvents, &__uuidof(_IProbeEvents), &LIBID_SensatronicsSDKLib, 0xFFFF, 0xFFFF>
#else
class ATL_NO_VTABLE CProbe :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CProbe, &CLSID_Probe>,
	public IConnectionPointContainerImpl<CProbe>,
	public CProxy_IProbeEvents<CProbe>,
	public IDispatchImpl<IProbe, &IID_IProbe, &LIBID_SensatronicsSDKLib, 0xFFFF, 0xFFFF>
#endif
{
public:
	CProbe()
	{
		m_bstrName = L"default";
		m_bstrType = L"not set";
		m_sintNumber = -1;
		m_longGroup = -1;
		m_pMostRecentDataPoint = NULL;
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_PROBE)


	BEGIN_COM_MAP(CProbe)
		COM_INTERFACE_ENTRY(IProbe)
		COM_INTERFACE_ENTRY2(IDispatch, IProbe)
		COM_INTERFACE_ENTRY(IConnectionPointContainer)
	END_COM_MAP()

	BEGIN_CONNECTION_POINT_MAP(CProbe)
		CONNECTION_POINT_ENTRY(__uuidof(_IProbeEvents))
	END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}
private:
	CComBSTR m_bstrName;	//MAX_PROBE_NAME
	CComBSTR m_bstrType;
	SHORT m_sintNumber;
	LONG m_longGroup;
protected:
	CComPtr<IDataPoint> m_pMostRecentDataPoint;
public:
	STDMETHOD(get_Name)(BSTR* pVal);
public:
	STDMETHOD(put_Name)(BSTR newVal);
public:
	STDMETHOD(get_Type)(BSTR* pVal);
public:
	STDMETHOD(put_Type)(BSTR newVal);
public:
	STDMETHOD(get_Number)(SHORT* pVal);
public:
	STDMETHOD(Poll)(IDataPoint* pDataPoint);
public:
	STDMETHOD(put_Number)(SHORT newVal);
public:
	STDMETHOD(get_Group)(LONG* pVal);
public:
	STDMETHOD(put_Group)(LONG newVal);
public:
	STDMETHOD(get_MostRecentDataPoint)(IDataPoint** pVal);

	// _IProbeEvents Methods
public:
};

OBJECT_ENTRY_AUTO(__uuidof(Probe), CProbe)
