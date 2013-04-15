// SensatronicsModelE.h : Declaration of the CSensatronicsModelE

#pragma once
#include "resource.h"       // main symbols

#include "SensatronicsSDK.h"
#include "_ISensatronicsModelEEvents_CP.h"

#include "SensatronicsDevice.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CSensatronicsModelE

class ATL_NO_VTABLE CSensatronicsModelE :
	public CSensatronicsDevice,
	public CComCoClass<CSensatronicsModelE, &CLSID_SensatronicsModelE>,
	public IConnectionPointContainerImpl<CSensatronicsModelE>,
	public CProxy_ISensatronicsModelEEvents<CSensatronicsModelE>,
	public IDispatchImpl<ISensatronicsModelE, &IID_ISensatronicsModelE, &LIBID_SensatronicsSDKLib, 0xFFFF, 0xFFFF>
{
public:
	CSensatronicsModelE()
	{
		m_bstrIpAddress = L"";
		m_bstrMask = L"";
		m_bstrGateway = L"";
		m_bstrSoftwareVersion = L"";
		m_bstrSerialNumber = L"not available";
		m_bstrSnmpTrapAddress = L"";
		m_bstrSnmpWriteCommunityString = L"";
		m_bstrSnmpReadCommunityString = L"";
		m_bstrSoftwareReleaseDate = L"";
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SENSATRONICSMODELE)


BEGIN_COM_MAP(CSensatronicsModelE)
	COM_INTERFACE_ENTRY(ISensatronicsModelE)
	COM_INTERFACE_ENTRY_NOINTERFACE(ISensatronicsDevice)
	COM_INTERFACE_ENTRY2(IDispatch, ISensatronicsModelE)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY_CHAIN(CSensatronicsDevice)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CSensatronicsModelE)
	CONNECTION_POINT_ENTRY(__uuidof(_ISensatronicsModelEEvents))
END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		HRESULT hr;

		CComObject<CProbeCollection>* pProbes;
		hr = CComObject<CProbeCollection>::CreateInstance(&pProbes);
		if(FAILED(hr))
			return hr;
		m_pProbes = pProbes;

		return S_OK;
	}

	void FinalRelease()
	{
	}
private:
	// IP Address of the device
	CComBSTR m_bstrIpAddress;
	CComBSTR m_bstrMask;
	CComBSTR m_bstrGateway;
	CComBSTR m_bstrSoftwareVersion;	// the sensors firmware version
	CComBSTR m_bstrSoftwareReleaseDate;	// the sensors firmware release date
	CComBSTR m_bstrSerialNumber;
	CComBSTR m_bstrSnmpTrapAddress;
	CComBSTR m_bstrSnmpWriteCommunityString;		// MAX_COMMUNITY_STRING
	CComBSTR m_bstrSnmpReadCommunityString;		// MAX_COMMUNITY_STRING
public:
	STDMETHOD(Poll)();
public:
	STDMETHOD(get_IpAddress)(BSTR* pVal);
public:
	STDMETHOD(put_IpAddress)(BSTR newVal);
public:
	STDMETHOD(get_Name)(BSTR* pVal);
public:
	STDMETHOD(put_Name)(BSTR newVal);
public:
	STDMETHOD(get_Mask)(BSTR* pVal);
public:
	STDMETHOD(put_Mask)(BSTR newVal);
public:
	STDMETHOD(get_Gateway)(BSTR* pVal);
public:
	STDMETHOD(put_Gateway)(BSTR newVal);
public:
	STDMETHOD(get_SerialNumber)(BSTR* pVal);
public:
	STDMETHOD(get_SnmpTrapIpAddress)(BSTR* pVal);
public:
	STDMETHOD(put_SnmpTrapIpAddress)(BSTR newVal);
public:
	STDMETHOD(get_SnmpWriteCommunityString)(BSTR* pVal);
public:
	STDMETHOD(put_SnmpWriteCommunityString)(BSTR newVal);
public:
	STDMETHOD(get_SnmpReadCommunityString)(BSTR* pVal);
public:
	STDMETHOD(put_SnmpReadCommunityString)(BSTR newVal);
public:
	STDMETHOD(get_SoftwareVersion)(BSTR* pVal);
public:
	STDMETHOD(put_SoftwareVersion)(BSTR newVal);
public:
	STDMETHOD(get_SoftwareReleaseDate)(BSTR* pVal);
public:
	STDMETHOD(put_SoftwareReleaseDate)(BSTR newVal);
public:
	STDMETHOD(GetConfig)(void);
public:
	STDMETHOD(get_Model)(BSTR* pVal);
public:
	STDMETHOD(put_Model)(BSTR newVal);
protected:
	HRESULT GetXMLConfig();
	HRESULT ProcessConfig(CXMLSensatronicsConfig* pXMLSensatronicsConfig);
protected:
	CXMLSensatronicsData* GetData();
	CXMLSensatronicsData* GetXMLData();
	CXMLSensatronicsData* GetHTTPConfigAndData(VARIANT_BOOL vbConfigOnly = VARIANT_FALSE);
public:
	STDMETHOD(get_Probe)(SHORT probeId, IDispatch** pVal);
public:
	STDMETHOD(get_Probes)(IDispatch** pVal);
};

OBJECT_ENTRY_AUTO(__uuidof(SensatronicsModelE), CSensatronicsModelE)
