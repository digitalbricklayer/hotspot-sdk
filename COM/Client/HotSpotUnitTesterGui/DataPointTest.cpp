// CDataPointTest.cpp

#include "StdAfx.h"
#include "DataPointTest.h"

#include <ProxyDataPoint.h>
#include <ProxySensatronicsModelE.h>
#include <ProxyProbe.h>
#include <ProxyMockSensors.h>
#include <bad_argument_error.h>

const std::wstring CDataPointTest::ConfigInXml = 
	L"<?xml version=\"1.0\" encoding=\"ISO-8859-1\" ?>"
	L"<Sensatronics id=\"EM9G2F0T105\">"
	L" <Unit hint=\"th,c3\">"
	L"  <Name hint=\"h\">Jim</Name>"
	L"  <Model>EM1</Model>"
	L"  <Serial_Number>EM9G2F0T105</Serial_Number>"
	L"  <Firmware_Release_Date>April 22, 2005    </Firmware_Release_Date>"
	L"  <Firmware_Version>5.0</Firmware_Version>"
	L"  <Website>http://www.sensatronics.com/</Website>"
	L"  <Manufacturer>Sensatronics</Manufacturer>"
	L" </Unit>"
	L" <Group id=\"1\" hint=\"th\">"
	L"  <Name hint=\"h\">Group 1</Name>"
	L"  <Probe id=\"1\" hint=\"tr,c3\" type=\"Temperature\">"
	L"   <Name>Temperature</Name>"
	L"   <Units>°C</Units>"
	L"  </Probe>"
	L"  <Probe id=\"2\" hint=\"tr,c3\" type=\"Humidity\">"
	L"   <Name>Humidity</Name>"
	L"   <Units>% RH</Units>"
	L"  </Probe>"
	L"  <Probe id=\"3\" hint=\"tr,c3\" type=\"Wetness\">"
	L"   <Name>Wetness</Name>"
	L"  </Probe>"
	L" </Group>"
	L" <Group id=\"2\" hint=\"th\">"
	L"  <Name hint=\"h\">Group 2</Name>"
	L"  <Probe id=\"4\" hint=\"tr,c3\" type=\"Temperature\">"
	L"   <Name>Temperature</Name>"
	L"   <Units>°F</Units>"
	L"  </Probe>"
	L"  <Probe id=\"5\" hint=\"tr,c3\" type=\"Humidity\">"
	L"   <Name>Humidity</Name>"
	L"   <Units>% RH</Units>"
	L"  </Probe>"
	L"  <Probe id=\"6\" hint=\"tr,c3\" type=\"Wetness\">"
	L"   <Name>Wetness</Name>"
	L"  </Probe>"
	L" </Group>"
	L" <Group id=\"3\" hint=\"th\">"
	L"  <Name hint=\"h\">Group 3</Name>"
	L"  <Probe id=\"7\" hint=\"tr,c3\" type=\"Temperature\">"
	L"   <Name>Temperature</Name>"
	L"   <Units>°R</Units>"
	L"  </Probe>"
	L"  <Probe id=\"8\" hint=\"tr,c3\" type=\"Humidity\">"
	L"   <Name>Humidity</Name>"
	L"   <Units>% RH</Units>"
	L"  </Probe>"
	L"  <Probe id=\"9\" hint=\"tr,c3\" type=\"Wetness\">"
	L"   <Name>Wetness</Name>"
	L"  </Probe>"
	L" </Group>"
	L" <Group id=\"4\" hint=\"th\">"
	L"  <Name hint=\"h\">Group 4</Name>"
	L"  <Probe id=\"10\" hint=\"tr,c3\" type=\"Temperature\">"
	L"   <Name>Temperature</Name>"
	L"   <Units>°K</Units>"
	L"  </Probe>"
	L"  <Probe id=\"11\" hint=\"tr,c3\" type=\"Humidity\">"
	L"   <Name>Humidity</Name>"
	L"   <Units>% RH</Units>"
	L"  </Probe>"
	L"  <Probe id=\"12\" hint=\"tr,c3\" type=\"Wetness\">"
	L"   <Name>Wetness</Name>"
	L"  </Probe>"
	L" </Group>"
	L"</Sensatronics>";

const std::wstring CDataPointTest::XmlData = 
	L"<Sensatronics id=\"EM9G2F0T105\">"
	L" <Group id=\"1\">"
	L"  <Probe id=\"1\">"
	L"   <Value>25.0</Value>"
	L"  </Probe>"
	L"  <Probe id=\"2\">"
	L"   <Value>55.0</Value>"
	L"  </Probe>"
	L"  <Probe id=\"3\">"
	L"   <Value>4.5</Value>"
	L"   </Probe>"
	L" </Group>"
	L" <Group id=\"2\">"
	L"  <Probe id=\"4\">"
	L"   <Value>77.00</Value>"
	L"  </Probe>"
	L"  <Probe id=\"5\">"
	L"   <Value>39.3</Value>"
	L"  </Probe>"
	L"  <Probe id=\"6\">"
	L"   <Value>-999.9</Value>"
	L"  </Probe>"
	L" </Group>"
	L" <Group id=\"3\">"
	L"  <Probe id=\"7\">"
	L"   <Value>536.67</Value>"
	L"  </Probe>"
	L"  <Probe id=\"8\">"
	L"   <Value>-999.9</Value>"
	L"  </Probe>"
	L"  <Probe id=\"9\">"
	L"   <Value>-999.9</Value>"
	L"  </Probe>"
	L" </Group>"
	L" <Group id=\"4\">"
	L"  <Probe id=\"10\">"
	L"   <Value>298.15</Value>"
	L"  </Probe>"
	L"  <Probe id=\"11\">"
	L"   <Value>-999.9</Value>"
	L"  </Probe>"
	L"  <Probe id=\"12\">"
	L"   <Value>-999.9</Value>"
	L"  </Probe>"
	L" </Group>"
	L"</Sensatronics>";

const std::wstring CDataPointTest::XmlPoll = 
	L"<Sensatronics id=\"EM9G2F0T105\">"
	L" <Group id=\"1\">"
	L"  <Probe id=\"1\">"
	L"   <Value>25.0</Value>"
	L"  </Probe>"
	L"  <Probe id=\"2\">"
	L"   <Value>55.0</Value>"
	L"  </Probe>"
	L"  <Probe id=\"3\">"
	L"   <Value>4.5</Value>"
	L"   </Probe>"
	L" </Group>"
	L" <Group id=\"2\">"
	L"  <Probe id=\"4\">"
	L"   <Value>77.00</Value>"
	L"  </Probe>"
	L"  <Probe id=\"5\">"
	L"   <Value>39.3</Value>"
	L"  </Probe>"
	L"  <Probe id=\"6\">"
	L"   <Value>-999.9</Value>"
	L"  </Probe>"
	L" </Group>"
	L" <Group id=\"3\">"
	L"  <Probe id=\"7\">"
	L"   <Value>536.67</Value>"
	L"  </Probe>"
	L"  <Probe id=\"8\">"
	L"   <Value>-999.9</Value>"
	L"  </Probe>"
	L"  <Probe id=\"9\">"
	L"   <Value>-999.9</Value>"
	L"  </Probe>"
	L" </Group>"
	L" <Group id=\"4\">"
	L"  <Probe id=\"10\">"
	L"   <Value>298.15</Value>"
	L"  </Probe>"
	L"  <Probe id=\"11\">"
	L"   <Value>-999.9</Value>"
	L"  </Probe>"
	L"  <Probe id=\"12\">"
	L"   <Value>-999.9</Value>"
	L"  </Probe>"
	L" </Group>"
	L"</Sensatronics>";

CPPUNIT_TEST_SUITE_REGISTRATION(CDataPointTest);

CDataPointTest::CDataPointTest()
: m_Sensor(0), m_Probe(0), m_DataPoint(0)
{
}

CDataPointTest::~CDataPointTest()
{
}

void CDataPointTest::setUp()
{
	CoInitialize(NULL);
	const std::wstring SensorName(L"Jim");
	m_PollTime = CTime::GetCurrentTime();

	m_MockSensors.reset(new CProxyMockSensors);

	m_MockSensors->AddSensor(SensorName, ConfigInXml, XmlData, m_PollTime);

	m_Sensor.reset(new CProxySensatronicsModelE);
	m_Sensor->SetModel(L"EM1");
	m_Sensor->SetName(SensorName);
	m_Sensor->SetIpAddress(L"10.0.0.103");
	m_Sensor->SetSnmpReadCommunityName(L"public");

	m_Sensor->Poll();

	m_Probe.reset(m_Sensor->FindProbeByNumber(1));
	m_DataPoint.reset(m_Probe->GetMostRecentDataPoint());
}

void CDataPointTest::tearDown()
{
	m_DataPoint.reset();
	m_Probe.reset();
	m_Sensor.reset();
	m_MockSensors.reset();

	CoUninitialize();
}

void CDataPointTest::testGetTime()
{
	CPPUNIT_ASSERT(m_PollTime == m_DataPoint->GetTime());
}

void CDataPointTest::testGetValue()
{
	CPPUNIT_ASSERT_EQUAL(25.00, m_DataPoint->GetValue());
}

void CDataPointTest::testUnitEmpty()
{
	CPPUNIT_ASSERT_THROW(m_DataPoint->SetUnit(L""), bad_argument_error);
}

void CDataPointTest::testUnitJunk()
{
	CPPUNIT_ASSERT_THROW(m_DataPoint->SetUnit(L"Z"), bad_argument_error);
}
