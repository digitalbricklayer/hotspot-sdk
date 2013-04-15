#pragma once

#include <string>
#include <map>
#include "IXMLElementHandler.h"

class CXMLSensatronicsProbeData
{
public:
	CXMLSensatronicsProbeData(LPCTSTR ProbeId) : m_sProbeId(ProbeId) {
	};

	~CXMLSensatronicsProbeData() {
	};

	LPCTSTR getProbeId() {
		return m_sProbeId;
	};

	LPCTSTR getProbeValue() {
		return m_sProbeValue;
	};

	void setProbeValue(LPCTSTR ProbeValue) {
		m_sProbeValue = ProbeValue;
	};
private:
	CString m_sProbeId;
	CString m_sProbeValue;
};

class CXMLSensatronicsSensorData
{
public:
	typedef std::map<std::wstring, CXMLSensatronicsProbeData*> ProbesContainer;
public:
	CXMLSensatronicsSensorData(LPCTSTR SensorId) : m_sSensorId(SensorId), m_sBatteryStatus(_T("")) {
	};
	~CXMLSensatronicsSensorData() {
		Clear();
	};

	LPCTSTR getSensorId() {
		return m_sSensorId;
	};

	void setBatteryStatus(LPCTSTR BatteryStatus) {
		m_sBatteryStatus = BatteryStatus;
	};

	LPCTSTR getBatteryStatus() {
		return m_sBatteryStatus;
	};

	void AddProbe(CXMLSensatronicsProbeData* Probe) {
		m_ProbeContainer[Probe->getProbeId()] = Probe;
	};

	const ProbesContainer& getProbeElements() {
		return m_ProbeContainer;
	};
protected:
	void Clear() {
		ProbesContainer::iterator it = m_ProbeContainer.begin();

		for(; it != m_ProbeContainer.end(); ++it)
		{
			CXMLSensatronicsProbeData *pProbe = it->second;

			delete pProbe;
		}

		m_ProbeContainer.clear();

	};
private:
	ProbesContainer m_ProbeContainer;
	CString m_sSensorId;
	CString m_sBatteryStatus;


};

class CXMLSensatronicsData : public IXMLElementHandler
{
public:
	typedef std::map<std::wstring, CXMLSensatronicsSensorData*> SensorsContainer;
public:
	CXMLSensatronicsData(void);
public:
	~CXMLSensatronicsData(void);
public:
    virtual void OnXMLStartElement(const CXMLElement& xmlElement);
public:
    virtual void OnXMLElementData(LPCTSTR elementData);
public:
    virtual void OnXMLEndElement(const CXMLElement& xmlElement);
public:    
    virtual void OnXMLError(int line, int column, LPCTSTR errorText, unsigned long errorCode);
public:
    virtual bool OnXMLAbortParse(const CXMLElement& xmlElement);
public:
	const SensorsContainer& getSensorsContainer() {
		return m_SensorsContainer;
	};
protected:
	void Clear();
private:
	SensorsContainer m_SensorsContainer;
	CXMLSensatronicsSensorData* m_pCurrentSensor;
	CXMLSensatronicsProbeData* m_pCurrentProbe;
	bool m_bProbeValue;
	bool m_bBatteryStatus;
};
