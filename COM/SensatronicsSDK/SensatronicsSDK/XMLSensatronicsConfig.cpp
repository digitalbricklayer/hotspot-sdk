#include "StdAfx.h"
#include "XMLSensatronicsConfig.h"

CXMLSensatronicsConfig::CXMLSensatronicsConfig(void)
: m_pCurrentSensor(NULL)
, m_pCurrentProbe(NULL)
, m_CurrentElement(SENSATRONICS_EMPTY)
, m_sGroup(_T("0"))
{
}

CXMLSensatronicsConfig::~CXMLSensatronicsConfig(void)
{
	Clear();
}

void CXMLSensatronicsConfig::OnXMLStartElement(const CXMLElement& xmlElement)
{
	CString sAttributeValue(_T(""));
	if(CString(_T("Sensatronics")) == xmlElement.GetElementName())
	{
		// Sensors will never overlap
		ATLASSERT(m_pCurrentSensor == NULL);

		CXMLSensatronicsSensorConfig* pCurrentSensor = new CXMLSensatronicsSensorConfig(xmlElement.GetAttributeValue(_T("id"), &sAttributeValue));

		m_pCurrentSensor = pCurrentSensor;

		m_CurrentElement = SENSATRONICS_EMPTY;
	}
	else if(CString(_T("Unit")) == xmlElement.GetElementName())
	{
		m_CurrentElement = SENSATRONICS_EMPTY;
	}
	else if(CString(_T("Group")) == xmlElement.GetElementName())
	{
		m_sGroup = xmlElement.GetAttributeValue(_T("id"), &sAttributeValue);
		m_CurrentElement = SENSATRONICS_GROUP_NAME;
	}
	else if(CString(_T("Probe")) == xmlElement.GetElementName())
	{
		ATLASSERT(m_pCurrentSensor != NULL);
		ATLASSERT(m_pCurrentProbe == NULL);

		CXMLSensatronicsProbeConfig* pCurrentProbe = new CXMLSensatronicsProbeConfig(xmlElement.GetAttributeValue(_T("id"), &sAttributeValue));

		m_pCurrentProbe = pCurrentProbe;

		m_pCurrentProbe->setProbeHint(xmlElement.GetAttributeValue(_T("hint"), &sAttributeValue));

		m_pCurrentProbe->setProbeType(xmlElement.GetAttributeValue(_T("type"), &sAttributeValue));

		m_pCurrentProbe->setProbeGroup(m_sGroup);

		m_CurrentElement = SENSATRONICS_EMPTY;
	}
	else
	{
		if(CString(_T("Name")) == xmlElement.GetElementName())
		{
			if(m_pCurrentSensor != NULL && m_pCurrentProbe != NULL && m_CurrentElement != SENSATRONICS_GROUP_NAME)
			{
				m_CurrentElement = SENSATRONICS_PROBE_NAME;
			}
			else if(m_pCurrentSensor != NULL && m_pCurrentProbe == NULL && m_CurrentElement != SENSATRONICS_GROUP_NAME)
			{
				m_CurrentElement = SENSATRONICS_UNIT_NAME;
			}
			else
			{
				m_CurrentElement = SENSATRONICS_EMPTY;
			}
		}
		else if(CString(_T("Model")) == xmlElement.GetElementName())
		{
			m_CurrentElement = SENSATRONICS_UNIT_MODEL;
		}
		else if(CString(_T("Serial_Number")) == xmlElement.GetElementName())
		{
			m_CurrentElement = SENSATRONICS_UNIT_SERIALNUMBER;
		}
		else if(CString(_T("Firmware_Release_Date")) == xmlElement.GetElementName())
		{
			m_CurrentElement = SENSATRONICS_UNIT_FIRMWARERELEASEDATE;
		}
		else if(CString(_T("Firmware_Version")) == xmlElement.GetElementName())
		{
			m_CurrentElement = SENSATRONICS_UNIT_FIRMWAREVERSION;
		}
		else if(CString(_T("Website")) == xmlElement.GetElementName())
		{
			m_CurrentElement = SENSATRONICS_UNIT_WEBSITE;
		}
		else if(CString(_T("Manufacturer")) == xmlElement.GetElementName())
		{
			m_CurrentElement = SENSATRONICS_UNIT_MANUFACTURER;
		}
		else if(CString(_T("Units")) == xmlElement.GetElementName())
		{
			m_CurrentElement = SENSATRONICS_PROBE_UNITS;
		}
		else
		{
		}
	}
}

void CXMLSensatronicsConfig::OnXMLElementData(LPCTSTR elementData)
{
	switch(m_CurrentElement)
	{
	case SENSATRONICS_UNIT_NAME:
		m_pCurrentSensor->setSensorName(elementData);
		break;
	case SENSATRONICS_UNIT_MODEL:
		m_pCurrentSensor->setSensorModel(elementData);
		break;
	case SENSATRONICS_UNIT_SERIALNUMBER:
		break;
	case SENSATRONICS_UNIT_FIRMWARERELEASEDATE:
		m_pCurrentSensor->setSensorFirmwareReleaseDate(elementData);
		break;
	case SENSATRONICS_UNIT_FIRMWAREVERSION:
		m_pCurrentSensor->setSensorFirmwareVersion(elementData);
		break;
	case SENSATRONICS_UNIT_WEBSITE:
		break;
	case SENSATRONICS_UNIT_MANUFACTURER:
		break;
	case SENSATRONICS_GROUP_NAME:
		break;
	case SENSATRONICS_PROBE_NAME:
		m_pCurrentProbe->setProbeName(elementData);
		break;
	case SENSATRONICS_PROBE_UNITS:
		m_pCurrentProbe->setProbeUnits(elementData);
		break;
	default:	// SENSATRONICS_EMPTY
		break;
	};
}

void CXMLSensatronicsConfig::OnXMLEndElement(const CXMLElement& xmlElement)
{
	if(CString(_T("Sensatronics")) == xmlElement.GetElementName())
	{
		ATLASSERT(m_pCurrentSensor != NULL);
		// add it
		m_SensorsContainer[m_pCurrentSensor->getSensorId()] = m_pCurrentSensor;

		m_pCurrentSensor = NULL;
	}
	else if(CString(_T("Group")) == xmlElement.GetElementName())
	{
		// Ignore groups at the moment
	}
	else if(CString(_T("Probe")) == xmlElement.GetElementName())
	{
		ATLASSERT(m_pCurrentSensor != NULL);
		ATLASSERT(m_pCurrentProbe != NULL);

		m_pCurrentSensor->AddProbe(m_pCurrentProbe);

		m_pCurrentProbe = NULL;
	}
	else
	{
	}

	m_CurrentElement = SENSATRONICS_EMPTY;
}

void CXMLSensatronicsConfig::OnXMLError(int line, int column, LPCTSTR errorText, unsigned long errorCode)
{
	// do nothing
}

bool CXMLSensatronicsConfig::OnXMLAbortParse(const CXMLElement& xmlElement)
{
	return false;
}

void CXMLSensatronicsConfig::Clear()
{
	SensorsContainer::iterator it = m_SensorsContainer.begin();

	for(; it != m_SensorsContainer.end(); ++it)
	{
		CXMLSensatronicsSensorConfig* pSensor = it->second;

		delete pSensor;
	}

	m_SensorsContainer.clear();
}