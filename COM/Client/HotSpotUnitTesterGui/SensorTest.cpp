// CSensorTest.cpp

#include "StdAfx.h"
#include "SensorTest.h"

#include <ProxySensatronicsModelE.h>
#include <ProxyProbe.h>
#include <bad_argument_error.h>
#include <memory>

const std::wstring CSensorTest::ConfigInXml = 
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

CPPUNIT_TEST_SUITE_REGISTRATION(CSensorTest);

CSensorTest::CSensorTest()
{
}

CSensorTest::~CSensorTest()
{
}

void CSensorTest::setUp()
{
	CoInitialize(NULL);

	m_Sensor.reset(new CProxySensatronicsModelE);
}

void CSensorTest::tearDown()
{
	m_Sensor.reset();
	CoUninitialize();
}

void CSensorTest::setNetworkProperties(const std::wstring& modelName)
{
	const std::wstring model(modelName.c_str());
	m_Sensor->SetModel(model);

	const std::wstring ipAddress(L"192.168.2.1");
	m_Sensor->SetIpAddress(ipAddress);

	const std::wstring ipAddressRetrieved = m_Sensor->GetIpAddress();

	CPPUNIT_ASSERT(ipAddressRetrieved == ipAddress);

	const std::wstring readCommunity(L"squigglywig");
	m_Sensor->SetSnmpReadCommunityName(readCommunity);

	const std::wstring readCommunityRetrieved = m_Sensor->GetSnmpReadCommunityName();

	CPPUNIT_ASSERT(readCommunityRetrieved == readCommunity);

	const std::wstring writeCommunity(L"Jim");
	m_Sensor->SetSnmpWriteCommunityName(writeCommunity);

	const std::wstring writeCommunityRetrieved = m_Sensor->GetSnmpWriteCommunityName();

	CPPUNIT_ASSERT(writeCommunityRetrieved == writeCommunity);
}

void CSensorTest::setInvalidNetworkProperties(const std::wstring& modelName)
{
	const std::wstring model(modelName.c_str());
	m_Sensor->SetModel(model);

	/*const std::wstring comPort(L"COM1");
	CPPUNIT_ASSERT_THROW(m_Sensor->SetComPort(comPort), bad_argument_error);*/
}

void CSensorTest::testNameDefault()
{
	// Keep the compiler happy by comparing the same type
	const size_t ExpectedValue = 0;

	// The default name should be empty
	CPPUNIT_ASSERT_EQUAL(ExpectedValue, m_Sensor->GetName().length());
}

void CSensorTest::testName()
{
	const std::wstring NewName(L"Jim");
	m_Sensor->SetName(NewName);

	const std::wstring& NewNameRetrieved = m_Sensor->GetName();

	// The new name should match the name that was set
	CPPUNIT_ASSERT(NewNameRetrieved == NewName);
}

void CSensorTest::testNameSameName()
{
	const std::wstring NewName(L"Jim");
	m_Sensor->SetName(NewName);
	CPPUNIT_ASSERT_THROW(m_Sensor->SetName(NewName), bad_argument_error);

	const std::wstring& NewNameRetrieved = m_Sensor->GetName();

	// The new name should match the name that was set
	CPPUNIT_ASSERT(NewNameRetrieved == NewName);
}

void CSensorTest::testEmptyName()
{
	const std::wstring ValidName(L"Jim");
	m_Sensor->SetName(ValidName);

	CPPUNIT_ASSERT_THROW(m_Sensor->SetName(L""), bad_argument_error);

	// Make sure that setting a bad value didn't change the existing value
	CPPUNIT_ASSERT(m_Sensor->GetName() == ValidName);
}

void CSensorTest::testNameMaxSize()
{
	std::wstring newName;

	// 32 char name - max size
	std::fill_n(back_inserter(newName), 32, L'A');
	m_Sensor->SetName(newName);

	// The new name should match the name that was set
	CPPUNIT_ASSERT(m_Sensor->GetName() == newName);
}

void CSensorTest::testNameMaxSizePlusOne()
{
	const std::wstring originalName = m_Sensor->GetName();
	std::wstring maxSizePlusOneName;

	// 32+1 char name - max size + 1
	std::fill_n(back_inserter(maxSizePlusOneName), 32+1, L'A');

	CPPUNIT_ASSERT_THROW(m_Sensor->SetName(maxSizePlusOneName), bad_argument_error);
	// Make sure that the original name is still ok
	CPPUNIT_ASSERT(m_Sensor->GetName() == originalName);
}

void CSensorTest::testModel()
{
	const std::wstring model(L"E4");
	m_Sensor->SetModel(model);

	CPPUNIT_ASSERT(m_Sensor->GetModel() == model);
}

void CSensorTest::testModelEmpty()
{
	const std::wstring originalModel = m_Sensor->GetModel();

	const std::wstring emptyModel(L"");

	CPPUNIT_ASSERT_THROW(m_Sensor->SetModel(emptyModel), bad_argument_error);
	CPPUNIT_ASSERT(originalModel == m_Sensor->GetModel());
}

void CSensorTest::testModelInvalid()
{
	const std::wstring originalModel = m_Sensor->GetModel();

	const std::wstring invalidModel(L"zzz");

	CPPUNIT_ASSERT_THROW(m_Sensor->SetModel(invalidModel), bad_argument_error);
	CPPUNIT_ASSERT(originalModel == m_Sensor->GetModel());
}

/*void CSensorTest::testComPortOne()
{
	const std::wstring model(L"ModelF");
	m_Sensor->SetModel(model);

	const std::wstring validComPort(L"1");
	m_Sensor->SetComPort(validComPort);

	CPPUNIT_ASSERT(validComPort == m_Sensor->GetComPort());
}

void CSensorTest::testComPortZero()
{
	const std::wstring model(L"ModelF");
	m_Sensor->SetModel(model);

	const std::wstring originalComPort = m_Sensor->GetComPort();

	const std::wstring invalidComPort(L"0");

	CPPUNIT_ASSERT_THROW(m_Sensor->SetComPort(invalidComPort), bad_argument_error);
	CPPUNIT_ASSERT(originalComPort == m_Sensor->GetComPort());
}

void CSensorTest::testComPortNegative()
{
	const std::wstring model(L"ModelF");
	m_Sensor->SetModel(model);

	const std::wstring originalComPort = m_Sensor->GetComPort();

	const std::wstring invalidComPort(L"-1");

	CPPUNIT_ASSERT_THROW(m_Sensor->SetComPort(invalidComPort), bad_argument_error);
	CPPUNIT_ASSERT(originalComPort == m_Sensor->GetComPort());
}

void CSensorTest::testComPortInvalid()
{
	const std::wstring model(L"ModelF");
	m_Sensor->SetModel(model);

	const std::wstring originalPort = m_Sensor->GetComPort();

	const std::wstring invalidPort(L"zzz1");

	CPPUNIT_ASSERT_THROW(m_Sensor->SetComPort(invalidPort), bad_argument_error);
	CPPUNIT_ASSERT(originalPort == m_Sensor->GetComPort());
}*/

void CSensorTest::testModelE4()
{
	setNetworkProperties(L"E4");
}

void CSensorTest::testModelE16()
{
	setNetworkProperties(L"E16");
}

void CSensorTest::testModelEm1()
{
	setNetworkProperties(L"EM1");
}

/*void CSensorTest::testModelF()
{
	const std::wstring model(L"ModelF");
	m_Sensor->SetModel(model);

	const std::wstring comPortOriginal = m_Sensor->GetComPort();

	CPPUNIT_ASSERT(comPortOriginal.length() == 0);

	const std::wstring comPort(L"1");
	m_Sensor->SetComPort(comPort);

	const std::wstring comPortRetrieved = m_Sensor->GetComPort();

	CPPUNIT_ASSERT(comPortRetrieved == comPort);
}*/

void CSensorTest::testModelE4Fail()
{
	setInvalidNetworkProperties(L"E4");
}

void CSensorTest::testModelE16Fail()
{
	setInvalidNetworkProperties(L"E16");
}

void CSensorTest::testModelEm1Fail()
{
	setInvalidNetworkProperties(L"EM1");
}

/*void CSensorTest::testModelFFail()
{
	const std::wstring model(L"ModelF");
	m_Sensor->SetModel(model);

	const std::wstring ipAddress(L"192.168.2.1");
	CPPUNIT_ASSERT_THROW(m_Sensor->SetIpAddress(ipAddress), bad_argument_error);

	const std::wstring readCommunity(L"squigglywig");
	CPPUNIT_ASSERT_THROW(m_Sensor->SetSnmpReadCommunityName(readCommunity), bad_argument_error);

	const std::wstring writeCommunity(L"Jim");
	CPPUNIT_ASSERT_THROW(m_Sensor->SetSnmpWriteCommunityName(writeCommunity), bad_argument_error);
}*/

/*void CSensorTest::testBatteryStatus()
{
	const std::wstring model(L"ModelF");
	m_Sensor->SetModel(model);

	const std::wstring batteryStatus = m_Sensor->GetBatteryStatus();

	CPPUNIT_ASSERT(batteryStatus == std::wstring(L"not available"));
}

void CSensorTest::testEnable()
{
	CPPUNIT_ASSERT_EQUAL(true, m_Sensor->GetEnabled());

	m_Sensor->SetEnabled(false);

	CPPUNIT_ASSERT_EQUAL(false, m_Sensor->GetEnabled());
	CPPUNIT_ASSERT_EQUAL(1, m_CounterObserver->GetEnabledChangeCounter());
	CPPUNIT_ASSERT_EQUAL(true, m_CounterObserver->GetEnabledPreviousValue());
}*/

void CSensorTest::testEmptyCommunityName()
{
	const std::wstring model(L"E4");
	m_Sensor->SetModel(model);

	const std::wstring readCommunity(L"");
	m_Sensor->SetSnmpReadCommunityName(readCommunity);
	CPPUNIT_ASSERT(readCommunity == m_Sensor->GetSnmpReadCommunityName());

	const std::wstring writeCommunity(L"");
	m_Sensor->SetSnmpWriteCommunityName(writeCommunity);
	CPPUNIT_ASSERT(writeCommunity == m_Sensor->GetSnmpWriteCommunityName());
}

void CSensorTest::testMaxCommunityName()
{
	const std::wstring model(L"E4");
	m_Sensor->SetModel(model);

	// Max is 32 chars (a figure I just kinda guessed at)
	std::wstring readCommunity;
	std::fill_n(back_inserter(readCommunity), 32, L'A');
	m_Sensor->SetSnmpReadCommunityName(readCommunity);
	CPPUNIT_ASSERT(readCommunity == m_Sensor->GetSnmpReadCommunityName());

	// Max is 32 chars (a figure I just kinda guessed at)
	std::wstring writeCommunity;
	std::fill_n(back_inserter(writeCommunity), 32, L'A');
	m_Sensor->SetSnmpWriteCommunityName(writeCommunity);
	CPPUNIT_ASSERT(writeCommunity == m_Sensor->GetSnmpWriteCommunityName());
}

void CSensorTest::testMaxPlusOneCommunityName()
{
	const std::wstring model(L"E4");
	m_Sensor->SetModel(model);

	const std::wstring originalReadCommunity = m_Sensor->GetSnmpReadCommunityName();
	const std::wstring originalWriteCommunity = m_Sensor->GetSnmpWriteCommunityName();

	// 32+1 chars
	std::wstring readCommunity;
	std::fill_n(back_inserter(readCommunity), 32+1, L'A');
	CPPUNIT_ASSERT_THROW(m_Sensor->SetSnmpReadCommunityName(readCommunity), bad_argument_error);

	// 32+1 chars
	std::wstring writeCommunity;
	std::fill_n(back_inserter(writeCommunity), 32+1, L'A');
	CPPUNIT_ASSERT_THROW(m_Sensor->SetSnmpWriteCommunityName(writeCommunity), bad_argument_error);

	CPPUNIT_ASSERT(originalReadCommunity == m_Sensor->GetSnmpReadCommunityName());
	CPPUNIT_ASSERT(originalWriteCommunity == m_Sensor->GetSnmpWriteCommunityName());
}

void CSensorTest::testSerialNumber()
{
	const std::wstring model(L"EM1");
	m_Sensor->SetModel(model);

	CPPUNIT_ASSERT(m_Sensor->GetSerialNumber() == std::wstring(L"not available"));
}
