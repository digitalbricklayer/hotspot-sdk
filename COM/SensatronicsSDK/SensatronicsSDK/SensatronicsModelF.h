// SensatronicsModelF.h : Declaration of the CSensatronicsModelF

#pragma once
#include "resource.h"       // main symbols

#include "SensatronicsSDK.h"
#include "_ISensatronicsModelFEvents_CP.h"

#include "SensatronicsDevice.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CSensatronicsModelF

class ATL_NO_VTABLE CSensatronicsModelF :
	public CSensatronicsDevice,
	public CComCoClass<CSensatronicsModelF, &CLSID_SensatronicsModelF>,
	public IConnectionPointContainerImpl<CSensatronicsModelF>,
	public CProxy_ISensatronicsModelFEvents<CSensatronicsModelF>,
	public IDispatchImpl<ISensatronicsModelF, &IID_ISensatronicsModelF, &LIBID_SensatronicsSDKLib, 0xFFFF, 0xFFFF>
{
public:
	CSensatronicsModelF()
	{
		m_bstrBatteryStatus = L"not available";
		m_bstrComPort = L"";
		m_bstrModel = L"ModelF";
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SENSATRONICSMODELF)


BEGIN_COM_MAP(CSensatronicsModelF)
	COM_INTERFACE_ENTRY(ISensatronicsModelF)
	COM_INTERFACE_ENTRY_NOINTERFACE(ISensatronicsDevice)
	COM_INTERFACE_ENTRY2(IDispatch, ISensatronicsModelF)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY_CHAIN(CSensatronicsDevice)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CSensatronicsModelF)
	CONNECTION_POINT_ENTRY(__uuidof(_ISensatronicsModelFEvents))
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
	CComBSTR m_bstrComPort;
	CComBSTR m_bstrBatteryStatus;
public:
	STDMETHOD(Poll)();
public:
	CXMLSensatronicsData* GetSerialComData(void);
public:
	STDMETHOD(get_Name)(BSTR* pVal);
public:
	STDMETHOD(put_Name)(BSTR newVal);
public:
	STDMETHOD(get_ComPort)(BSTR* pVal);
public:
	STDMETHOD(put_ComPort)(BSTR newVal);
public:
	STDMETHOD(get_BatteryStatus)(BSTR* pVal);
public:
	STDMETHOD(GetConfig)(void);
protected:
	HRESULT ProcessConfig(CXMLSensatronicsConfig* pXMLSensatronicsConfig);
protected:
	CXMLSensatronicsData* GetData();
public:
	STDMETHOD(get_Model)(BSTR* pVal);
public:
	STDMETHOD(get_Probe)(SHORT probeId, IDispatch** pVal);
public:
	STDMETHOD(get_Probes)(IDispatch** pVal);
};

OBJECT_ENTRY_AUTO(__uuidof(SensatronicsModelF), CSensatronicsModelF)
