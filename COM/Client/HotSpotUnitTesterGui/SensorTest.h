#pragma once

#include <cppunit/extensions/HelperMacros.h>

#include <string>
#include <boost/scoped_ptr.hpp>

class CProxySensatronicsModelE;
class CProxyProbe;

class CSensorTest : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(CSensorTest);
		CPPUNIT_TEST(testName);
		CPPUNIT_TEST(testNameSameName);
		CPPUNIT_TEST(testNameDefault);
		CPPUNIT_TEST(testEmptyName);
		CPPUNIT_TEST(testNameMaxSize);
		CPPUNIT_TEST(testNameMaxSizePlusOne);
		//CPPUNIT_TEST(testComPortOne);
		//CPPUNIT_TEST(testComPortZero);
		//CPPUNIT_TEST(testComPortNegative);
		//CPPUNIT_TEST(testComPortInvalid);
		CPPUNIT_TEST(testModel);
		CPPUNIT_TEST(testModelEmpty);
		CPPUNIT_TEST(testModelInvalid);
		CPPUNIT_TEST(testModelE4);
		CPPUNIT_TEST(testModelE16);
		CPPUNIT_TEST(testModelEm1);
		//CPPUNIT_TEST(testModelF);
		CPPUNIT_TEST(testModelE4Fail);
		CPPUNIT_TEST(testModelE16Fail);
		CPPUNIT_TEST(testModelEm1Fail);
		//CPPUNIT_TEST(testModelFFail);
		//CPPUNIT_TEST(testBatteryStatus);
		//CPPUNIT_TEST(testEnable);
		CPPUNIT_TEST(testEmptyCommunityName);
		CPPUNIT_TEST(testMaxCommunityName);
		CPPUNIT_TEST(testMaxPlusOneCommunityName);
		CPPUNIT_TEST(testSerialNumber);
	CPPUNIT_TEST_SUITE_END();

public:
	CSensorTest();
	~CSensorTest();

	void setUp();
	void tearDown();

	void testName();
	void testNameSameName();
	void testNameDefault();
	void testEmptyName();
	void testNameMaxSize();
	void testNameMaxSizePlusOne();
	//void testComPortOne();
	//void testComPortZero();
	//void testComPortNegative();
	//void testComPortInvalid();
	void testModel();
	void testModelEmpty();
	void testModelInvalid();
	void testModelE4();
	void testModelE16();
	void testModelEm1();
	//void testModelF();
	void testModelE4Fail();
	void testModelE16Fail();
	void testModelEm1Fail();
	//void testModelFFail();
	//void testBatteryStatus();
	//void testEnable();
	void testEmptyCommunityName();
	void testMaxCommunityName();
	void testMaxPlusOneCommunityName();
	void testSerialNumber();

private:
	void setNetworkProperties(const std::wstring& modelName);
	void setInvalidNetworkProperties(const std::wstring& modelName);

	// The sensor to be tested
	boost::scoped_ptr<CProxySensatronicsModelE> m_Sensor;

	static const std::wstring ConfigInXml;

};
