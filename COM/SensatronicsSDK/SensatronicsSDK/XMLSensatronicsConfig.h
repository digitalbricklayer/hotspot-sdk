#pragma once

#include <string>
#include <map>
#include "IXMLElementHandler.h"

class CXMLSensatronicsProbeConfig
{
public:
	CXMLSensatronicsProbeConfig(LPCTSTR ProbeId) 
	: m_sProbeId(ProbeId)
	, m_sProbeHint(_T(""))
	, m_sProbeType(_T(""))
	, m_sProbeName(_T(""))
	, m_sProbeUnits(_T(""))
	, m_sProbeGroup(_T("")) {
	};

	~CXMLSensatronicsProbeConfig() {
	};

	LPCTSTR getProbeId() {
		return m_sProbeId;
	};

	LPCTSTR getProbeHint() {
		return m_sProbeHint;
	};

	void setProbeHint(LPCTSTR ProbeHint) {
		m_sProbeHint = ProbeHint;
	};

	LPCTSTR getProbeType() {
		return m_sProbeType;
	};

	void setProbeType(LPCTSTR ProbeType) {
		m_sProbeType = ProbeType;
	};

	LPCTSTR getProbeName() {
		return m_sProbeName;
	};

	void setProbeName(LPCTSTR ProbeName) {
		m_sProbeName = ProbeName;
	};

	LPCTSTR getProbeUnits() {
		return m_sProbeUnits;
	};

	void setProbeUnits(LPCTSTR ProbeUnits) {
		m_sProbeUnits = ProbeUnits;
	};

	LPCTSTR getProbeGroup() {
		return m_sProbeGroup;
	};

	void setProbeGroup(LPCTSTR ProbeGroup) {
		m_sProbeGroup = ProbeGroup;
	};
private:
	CString m_sProbeId;
	CString m_sProbeHint;
	CString m_sProbeType;
	CString m_sProbeName;
	CString m_sProbeUnits;
	CString m_sProbeGroup;
};

class CXMLSensatronicsSensorConfig
{
public:
	typedef std::map<std::wstring, CXMLSensatronicsProbeConfig*> ProbesContainer;
public:
	CXMLSensatronicsSensorConfig(LPCTSTR SensorId) 
	: m_sSensorId(SensorId) 
	, m_sSensorName(_T(""))
	, m_sSensorModel(_T(""))
	, m_sSensorFirmwareVersion(_T(""))
	, m_sSensorFirmwareReleaseDate(_T("")) {
	};
	~CXMLSensatronicsSensorConfig() {
		Clear();
	};

	LPCTSTR getSensorId() {
		return m_sSensorId;
	};

	LPCTSTR getSensorName() {
		return m_sSensorName;
	};

	void setSensorName(LPCTSTR SensorName) {
		m_sSensorName = SensorName;
	};

	LPCTSTR getSensorModel() {
		return m_sSensorModel;
	};

	void setSensorModel(LPCTSTR SensorModel) {
		m_sSensorModel = SensorModel;
	};

	LPCTSTR getSensorFirmwareVersion() {
		return m_sSensorFirmwareVersion;
	};

	void setSensorFirmwareVersion(LPCTSTR SensorFirmwareVersion) {
		m_sSensorFirmwareVersion = SensorFirmwareVersion;
	};

	LPCTSTR getSensorFirmwareReleaseDate() {
		return m_sSensorFirmwareReleaseDate;
	};

	void setSensorFirmwareReleaseDate(LPCTSTR SensorFirmwareReleaseDate) {
		m_sSensorFirmwareReleaseDate = SensorFirmwareReleaseDate;
	};

	void AddProbe(CXMLSensatronicsProbeConfig* Probe) {
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
			CXMLSensatronicsProbeConfig *pProbe = it->second;

			delete pProbe;
		}

		m_ProbeContainer.clear();

	};
private:
	ProbesContainer m_ProbeContainer;
	CString m_sSensorId;
	CString m_sSensorName;
	CString m_sSensorModel;
	CString m_sSensorFirmwareVersion;
	CString m_sSensorFirmwareReleaseDate;
};

class CXMLSensatronicsConfig : public IXMLElementHandler
{
public:
	typedef std::map<std::wstring, CXMLSensatronicsSensorConfig*> SensorsContainer;
public:
	typedef enum {
		SENSATRONICS_EMPTY,
		SENSATRONICS_UNIT_NAME,
		SENSATRONICS_UNIT_MODEL,
		SENSATRONICS_UNIT_SERIALNUMBER,
		SENSATRONICS_UNIT_FIRMWARERELEASEDATE,
		SENSATRONICS_UNIT_FIRMWAREVERSION,
		SENSATRONICS_UNIT_WEBSITE,
		SENSATRONICS_UNIT_MANUFACTURER,
		SENSATRONICS_GROUP_NAME,
		SENSATRONICS_PROBE_NAME,
		SENSATRONICS_PROBE_UNITS,
	} SensatronicsElementsMap;
public:
	CXMLSensatronicsConfig(void);
public:
	~CXMLSensatronicsConfig(void);
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
	CXMLSensatronicsSensorConfig* m_pCurrentSensor;
	CXMLSensatronicsProbeConfig* m_pCurrentProbe;
	SensatronicsElementsMap m_CurrentElement;
	CString m_sGroup;
};
