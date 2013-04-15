// MockSensor.h : Declaration of the CMockSensor

#pragma once
#include "resource.h"       // main symbols

#include "MockSensors.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CMockSensor

class ATL_NO_VTABLE CMockSensor :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMockSensor, &CLSID_MockSensor>,
	public IDispatchImpl<IMockSensor, &IID_IMockSensor, &LIBID_MockSensorsLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	typedef std::vector<CComBSTR> DataContainer;
	typedef std::map<CComBSTR, DataContainer> MockDataContainer;
	typedef std::map<CComBSTR, CComBSTR> MockConfigContainer;
	typedef std::vector<DATE> MockTimeStampContainer;
public:
	CMockSensor() : m_nPollCount( -1 )
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MOCKSENSOR)


BEGIN_COM_MAP(CMockSensor)
	COM_INTERFACE_ENTRY(IMockSensor)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()
	DECLARE_CLASSFACTORY_SINGLETON(CMockSensor)

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	STDMETHOD(AddSensor)(BSTR SensorId, BSTR ConfigData, BSTR PollData, DATE Time);
public:
	STDMETHOD(AddSensorPollData)(BSTR SensorId, BSTR PollData, DATE Time);
public:
	STDMETHOD(GetSensorPollData)(BSTR SensorId, BSTR* PollData);
private:
	MockDataContainer m_Data;
	MockConfigContainer m_Config;
	MockTimeStampContainer m_TimeStamp;
	ULONG m_nPollCount;
protected:
	void SetMaxPollCount(void);
public:
	STDMETHOD(get_PollCount)(ULONG* pVal);
public:
	STDMETHOD(put_PollCount)(ULONG newVal);
public:
	HRESULT AddConfigData(BSTR SensorId, BSTR ConfigData);
public:
	STDMETHOD(GetSensorConfigData)(BSTR SensorId, BSTR* ConfigData);
public:
	STDMETHOD(GetTimeStamp)(DATE* TimeStamp);
protected:
	HRESULT CreateSensor(BSTR SensorId);
};

OBJECT_ENTRY_AUTO(__uuidof(MockSensor), CMockSensor)
