// CSensorFTest.cpp

#include "StdAfx.h"
#include "SensorFTest.h"

#include <ProxySensatronicsModelF.h>
#include <ProxyProbe.h>
#include <bad_argument_error.h>
#include <memory>

const std::wstring CSensorFTest::ConfigInXml = 
	L"<?xml version=\"1.0\" encoding=\"ISO-8859-1\" ?>"
	L"<Sensatronics id=\"EM9G2F0T105\">"
	L" <Unit hint=\"th,c3\">"
	L"  <Name hint=\"h\">EM1</Name>"
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
	L"   <Units>°C</Units>"
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
	L"   <Units>°C</Units>"
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
	L"   <Units>°C</Units>"
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

CPPUNIT_TEST_SUITE_REGISTRATION(CSensorFTest);

CSensorFTest::CSensorFTest()
{
}

CSensorFTest::~CSensorFTest()
{
}

void CSensorFTest::setUp()
{
	CoInitialize(NULL);

	m_Sensor.reset(new CProxySensatronicsModelF);
}

void CSensorFTest::tearDown()
{
	m_Sensor.reset();
	CoUninitialize();
}

void CSensorFTest::setInvalidNetworkProperties(const std::wstring& modelName)
{
	const std::wstring comPort(L"COM1");
	CPPUNIT_ASSERT_THROW(m_Sensor->SetComPort(comPort), bad_argument_error);
}

void CSensorFTest::testNameDefault()
{
	// Keep the compiler happy by comparing the same type
	const size_t ExpectedValue = 0;

	// The default name should be empty
	CPPUNIT_ASSERT_EQUAL(ExpectedValue, m_Sensor->GetName().length());
}

void CSensorFTest::testName()
{
	const std::wstring NewName(L"Jim");
	m_Sensor->SetName(NewName);

	const std::wstring& NewNameRetrieved = m_Sensor->GetName();

	// The new name should match the name that was set
	CPPUNIT_ASSERT(NewNameRetrieved == NewName);
}

void CSensorFTest::testNameSameName()
{
	const std::wstring NewName(L"Jim");
	m_Sensor->SetName(NewName);
	CPPUNIT_ASSERT_THROW(m_Sensor->SetName(NewName), bad_argument_error);

	const std::wstring& NewNameRetrieved = m_Sensor->GetName();

	// The new name should match the name that was set
	CPPUNIT_ASSERT(NewNameRetrieved == NewName);
}

void CSensorFTest::testEmptyName()
{
	const std::wstring ValidName(L"Jim");
	m_Sensor->SetName(ValidName);

	CPPUNIT_ASSERT_THROW(m_Sensor->SetName(L""), bad_argument_error);

	// Make sure that setting a bad value didn't change the existing value
	CPPUNIT_ASSERT(m_Sensor->GetName() == ValidName);
}

void CSensorFTest::testNameMaxSize()
{
	std::wstring newName;

	// 32 char name - max size
	std::fill_n(back_inserter(newName), 32, L'A');
	m_Sensor->SetName(newName);

	// The new name should match the name that was set
	CPPUNIT_ASSERT(m_Sensor->GetName() == newName);
}

void CSensorFTest::testNameMaxSizePlusOne()
{
	const std::wstring originalName = m_Sensor->GetName();
	std::wstring maxSizePlusOneName;

	// 32+1 char name - max size + 1
	std::fill_n(back_inserter(maxSizePlusOneName), 32+1, L'A');

	CPPUNIT_ASSERT_THROW(m_Sensor->SetName(maxSizePlusOneName), bad_argument_error);
	// Make sure that the original name is still ok
	CPPUNIT_ASSERT(m_Sensor->GetName() == originalName);
}

void CSensorFTest::testModel()
{
	const std::wstring model(L"ModelF");

	CPPUNIT_ASSERT(m_Sensor->GetModel() == model);
}

void CSensorFTest::testModelEmpty()
{
	const std::wstring originalModel = m_Sensor->GetModel();

	const std::wstring emptyModel(L"");

	CPPUNIT_ASSERT(originalModel == m_Sensor->GetModel());
}

void CSensorFTest::testModelInvalid()
{
	const std::wstring originalModel = m_Sensor->GetModel();

	const std::wstring invalidModel(L"zzz");

	CPPUNIT_ASSERT(originalModel == m_Sensor->GetModel());
}

void CSensorFTest::testComPortOne()
{
	const std::wstring validComPort(L"1");
	m_Sensor->SetComPort(validComPort);

	CPPUNIT_ASSERT(validComPort == m_Sensor->GetComPort());
}

void CSensorFTest::testComPortZero()
{
	const std::wstring model(L"ModelF");

	const std::wstring originalComPort = m_Sensor->GetComPort();

	const std::wstring invalidComPort(L"0");

	CPPUNIT_ASSERT_THROW(m_Sensor->SetComPort(invalidComPort), bad_argument_error);
	CPPUNIT_ASSERT(originalComPort == m_Sensor->GetComPort());
}

void CSensorFTest::testComPortNegative()
{
	const std::wstring model(L"ModelF");

	const std::wstring originalComPort = m_Sensor->GetComPort();

	const std::wstring invalidComPort(L"-1");

	CPPUNIT_ASSERT_THROW(m_Sensor->SetComPort(invalidComPort), bad_argument_error);
	CPPUNIT_ASSERT(originalComPort == m_Sensor->GetComPort());
}

void CSensorFTest::testComPortInvalid()
{
	const std::wstring model(L"ModelF");

	const std::wstring originalPort = m_Sensor->GetComPort();

	const std::wstring invalidPort(L"zzz1");

	CPPUNIT_ASSERT_THROW(m_Sensor->SetComPort(invalidPort), bad_argument_error);
	CPPUNIT_ASSERT(originalPort == m_Sensor->GetComPort());
}

void CSensorFTest::testModelF()
{
	const std::wstring model(L"ModelF");

	const std::wstring comPortOriginal = m_Sensor->GetComPort();

	CPPUNIT_ASSERT(comPortOriginal.length() == 0);

	const std::wstring comPort(L"1");
	m_Sensor->SetComPort(comPort);

	const std::wstring comPortRetrieved = m_Sensor->GetComPort();

	CPPUNIT_ASSERT(comPortRetrieved == comPort);
}

void CSensorFTest::testBatteryStatus()
{
	const std::wstring model(L"ModelF");

	const std::wstring batteryStatus = m_Sensor->GetBatteryStatus();

	CPPUNIT_ASSERT(batteryStatus == std::wstring(L"not available"));
}

/*void CSensorFTest::testEnable()
{
	CPPUNIT_ASSERT_EQUAL(true, m_Sensor->GetEnabled());

	m_Sensor->SetEnabled(false);

	CPPUNIT_ASSERT_EQUAL(false, m_Sensor->GetEnabled());
	CPPUNIT_ASSERT_EQUAL(1, m_CounterObserver->GetEnabledChangeCounter());
	CPPUNIT_ASSERT_EQUAL(true, m_CounterObserver->GetEnabledPreviousValue());
}*/