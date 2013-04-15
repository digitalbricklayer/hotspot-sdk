// DataConnector.h : Declaration of the CDataConnector

#pragma once
#include "resource.h"       // main symbols

#include "SensatronicsSDK.h"

#include "XMLSensatronicsData.h"
#include "XMLSensatronicsConfig.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CDataConnector

class ATL_NO_VTABLE CDataConnector :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDataConnector, &CLSID_DataConnector>,
	public IDispatchImpl<IDataConnector, &IID_IDataConnector, &LIBID_SensatronicsSDKLib, 0xFFFF, 0xFFFF>
{
public:
	CDataConnector()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DATACONNECTOR)


BEGIN_COM_MAP(CDataConnector)
	COM_INTERFACE_ENTRY(IDataConnector)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	STDMETHOD(RequestModelEXMLData)(BSTR Id, BSTR Val, LONG* Handler);
public:
	STDMETHOD(RequestModelFSerialComConfigData)(BSTR Id, BSTR ComPort, LONG* Handler);
public:
	STDMETHOD(RequestModelFSerialComData)(BSTR Id, BSTR ComPort, LONG* Handler);
public:
	STDMETHOD(RequestModelEXMLConfigData)(BSTR Id, BSTR Val, LONG* Handler);
public:
	STDMETHOD(RequestModelEHTTPConfigAndData)(BSTR Id, BSTR IpAddress, BSTR ConfigPath, BSTR DataPath, BSTR Model, LONG* ConfigHandler, LONG* DataHandler);
protected:
	HRESULT RequestXML(BSTR Val, IXMLElementHandler* ElementHandler);
	HRESULT RequestXML(VARIANT Val, IXMLElementHandler* ElementHandler);
	HRESULT RequestHTTP(BSTR IpAddress, BSTR Path, BSTR* pVal);
	HRESULT ConvertHTTPDataToXMLConfigAndData(BSTR Model, BSTR Config, BSTR* pXMLConfig, BSTR Data, BSTR* pXMLData);
protected:
	HRESULT RequestMockSensorsXML(const BSTR SensorId, IXMLElementHandler* ElementHandler, VARIANT_BOOL Data);

};

OBJECT_ENTRY_AUTO(__uuidof(DataConnector), CDataConnector)
