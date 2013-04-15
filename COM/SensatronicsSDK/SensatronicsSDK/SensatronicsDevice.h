// SensatronicsDevice.h : Declaration of the CSensatronicsDevice

#pragma once
#include "resource.h"       // main symbols

#include "SensatronicsSDK.h"

#include "ProbeCollection.h"

#include "XMLSensatronicsData.h"
#include "XMLSensatronicsConfig.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CSensatronicsDevice

class ATL_NO_VTABLE CSensatronicsDevice :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<ISensatronicsDevice, &IID_ISensatronicsDevice, &LIBID_SensatronicsSDKLib, 0xFFFF, 0xFFFF>
{
public:
	CSensatronicsDevice()
	{
		m_bstrName = L"";
		m_bstrModel = L"not set";
		m_bstrUnit = L"";
	}

BEGIN_COM_MAP(CSensatronicsDevice)
	COM_INTERFACE_ENTRY(ISensatronicsDevice)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{

		/*
		The following code must be in all FinalContructs of classes
		that use this class as a base class


		CComObject<CProbeCollection>* pProbes;
		hr = CComObject<CProbeCollection>::CreateInstance(&pProbes);
		if(FAILED(hr))
			return hr;
		m_pProbes = pProbes;
		*/

		return S_OK;
	}

	void FinalRelease()
	{
	}
protected:
	CComPtr<IProbeCollection> m_pProbes;
protected:
	CComBSTR m_bstrName;
	CComBSTR m_bstrModel;
protected:
	CComBSTR m_bstrUnit;
protected:
	virtual HRESULT ProcessConfig(CXMLSensatronicsConfig* pXMLSensatronicsConfig) = 0;
	virtual HRESULT ProcessProbeConfig(CXMLSensatronicsProbeConfig* pXMLSensatronicsProbeConfig, bool* pbTempUnitSet);
protected:
	virtual HRESULT AddProbe(IProbe* pProbe);
protected:
	STDMETHOD(Poll)();
protected:
	STDMETHOD(GetConfig)(void) = 0;
	virtual CXMLSensatronicsData* GetData() = 0;
protected:
	STDMETHOD(GetProbeData)(IProbe* spProbe, CXMLSensatronicsData* xmlSensatronicsData, IDataPoint** pDataPoint);
protected:
	STDMETHOD(get_Model)(BSTR* pVal);
protected:
	STDMETHOD(put_Model)(BSTR newVal);
protected:
	STDMETHOD(get_Name)(BSTR* pVal);
protected:
	STDMETHOD(put_Name)(BSTR newVal);
protected:
	STDMETHOD(get_ProbeCollection)(IDispatch** pVal);
protected:
	STDMETHOD(get_Probe)(SHORT probeId, IDispatch** pVal);
public:


};

//OBJECT_ENTRY_AUTO(__uuidof(SensatronicsDevice), CSensatronicsDevice)
