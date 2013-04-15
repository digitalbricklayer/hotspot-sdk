// DataPoint.h : Declaration of the CDataPoint

#pragma once
#include "resource.h"       // main symbols

#include "SensatronicsSDK.h"
#include "_IDataPointEvents_CP.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CDataPoint

class ATL_NO_VTABLE CDataPoint :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDataPoint, &CLSID_DataPoint>,
	public IConnectionPointContainerImpl<CDataPoint>,
	public CProxy_IDataPointEvents<CDataPoint>,
	public IDispatchImpl<IDataPoint, &IID_IDataPoint, &LIBID_SensatronicsSDKLib, 0xFFFF, 0xFFFF>
{
public:
	CDataPoint()
	{
		m_bstrUnit = L"unknown";
		VariantClear(&m_varValue);
		VariantInit(&m_varValue);
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DATAPOINT)


BEGIN_COM_MAP(CDataPoint)
	COM_INTERFACE_ENTRY(IDataPoint)
//	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, IDataPoint)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CDataPoint)
	CONNECTION_POINT_ENTRY(__uuidof(_IDataPointEvents))
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
	VARIANT m_varValue;
	CComBSTR m_bstrUnit;
	CTime m_UTCDataTime;
public:
	STDMETHOD(get_Value)(VARIANT* pVal);
public:
	STDMETHOD(put_Value)(VARIANT newVal);
public:
	STDMETHOD(get_Unit)(BSTR* pVal);
public:
	STDMETHOD(put_Unit)(BSTR newVal);
public:
	STDMETHOD(get_Time)(DATE* pVal);
public:
	STDMETHOD(put_Time)(DATE newVal);
public:
	STDMETHOD(get_UTCTime)(LONGLONG* pVal);
public:
	STDMETHOD(put_UTCTime)(LONGLONG newVal);
public:
	STDMETHOD(get_UTCTimeAsString)(BSTR* pVal);
public:
	STDMETHOD(put_UTCTimeAsString)(BSTR newVal);
};

OBJECT_ENTRY_AUTO(__uuidof(DataPoint), CDataPoint)
