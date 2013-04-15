#include "StdAfx.h"
#include "XMLSensatronicsData.h"

CXMLSensatronicsData::CXMLSensatronicsData(void)
: m_pCurrentSensor(NULL)
, m_pCurrentProbe(NULL)
, m_bProbeValue(false)
, m_bBatteryStatus(false)
{
}

CXMLSensatronicsData::~CXMLSensatronicsData(void)
{
	Clear();
}

void CXMLSensatronicsData::OnXMLStartElement(const CXMLElement& xmlElement)
{
	CString sAttributeValue(_T(""));
	if(CString(_T("Sensatronics")) == xmlElement.GetElementName())
	{
		// Sensors will never overlap
		ATLASSERT(m_pCurrentSensor == NULL);

		CXMLSensatronicsSensorData* pCurrentSensor = new CXMLSensatronicsSensorData(xmlElement.GetAttributeValue(_T("id"), &sAttributeValue));

		m_pCurrentSensor = pCurrentSensor;
	}
	else if(CString(_T("Group")) == xmlElement.GetElementName())
	{
		// Ignore groups at the moment
	}
	else if(CString(_T("Probe")) == xmlElement.GetElementName())
	{
		ATLASSERT(m_pCurrentSensor != NULL);
		ATLASSERT(m_pCurrentProbe == NULL);

		CXMLSensatronicsProbeData* pCurrentProbe = new CXMLSensatronicsProbeData(xmlElement.GetAttributeValue(_T("id"), &sAttributeValue));

		m_pCurrentProbe = pCurrentProbe;

	}
	else if(CString(_T("Value")) == xmlElement.GetElementName())
	{
		m_bProbeValue = true;
	}
	else if(CString(_T("BatteryStatus")) == xmlElement.GetElementName())
	{
		m_bBatteryStatus = true;
	}
	else
	{
		// Unknown element
	}
}

void CXMLSensatronicsData::OnXMLElementData(LPCTSTR elementData)
{
	if(m_bProbeValue)
	{
		ATLASSERT(m_pCurrentProbe != NULL);

		m_pCurrentProbe->setProbeValue(elementData);
	}

	if(m_bBatteryStatus)
	{
		ATLASSERT(m_pCurrentSensor != NULL);
		
		m_pCurrentSensor->setBatteryStatus(elementData);
	}
}

void CXMLSensatronicsData::OnXMLEndElement(const CXMLElement& xmlElement)
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
	else if(CString(_T("Value")) == xmlElement.GetElementName())
	{
		m_bProbeValue = false;
	}
	else if(CString(_T("BatteryStatus")) == xmlElement.GetElementName())
	{
		m_bBatteryStatus = false;
	}
	else
	{
		// Unknown element
	}
}

void CXMLSensatronicsData::OnXMLError(int line, int column, LPCTSTR errorText, unsigned long errorCode)
{
	// do nothing
}

bool CXMLSensatronicsData::OnXMLAbortParse(const CXMLElement& xmlElement)
{
	return false;
}

void CXMLSensatronicsData::Clear()
{
	SensorsContainer::iterator it = m_SensorsContainer.begin();

	for(; it != m_SensorsContainer.end(); ++it)
	{
		CXMLSensatronicsSensorData* pSensor = it->second;

		delete pSensor;
	}

	m_SensorsContainer.clear();
}