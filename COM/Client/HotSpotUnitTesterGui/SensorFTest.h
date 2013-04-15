#pragma once

#include <cppunit/extensions/HelperMacros.h>

#include <string>
#include <boost/scoped_ptr.hpp>

class CProxySensatronicsModelF;
class CProxyProbe;

class CSensorFTest : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(CSensorFTest);
		CPPUNIT_TEST(testName);
		CPPUNIT_TEST(testNameSameName);
		CPPUNIT_TEST(testNameDefault);
		CPPUNIT_TEST(testEmptyName);
		CPPUNIT_TEST(testNameMaxSize);
		CPPUNIT_TEST(testNameMaxSizePlusOne);
		CPPUNIT_TEST(testComPortOne);
		CPPUNIT_TEST(testComPortZero);
		CPPUNIT_TEST(testComPortNegative);
		CPPUNIT_TEST(testComPortInvalid);
		CPPUNIT_TEST(testModel);
		CPPUNIT_TEST(testModelF);
		//CPPUNIT_TEST(testEnable);
	CPPUNIT_TEST_SUITE_END();

public:
	CSensorFTest();
	~CSensorFTest();

	void setUp();
	void tearDown();

	void testName();
	void testNameSameName();
	void testNameDefault();
	void testEmptyName();
	void testNameMaxSize();
	void testNameMaxSizePlusOne();
	void testComPortOne();
	void testComPortZero();
	void testComPortNegative();
	void testComPortInvalid();
	void testModel();
	void testModelEmpty();
	void testModelInvalid();
	void testModelF();
	void testBatteryStatus();
	//void testEnable();

private:
	void setInvalidNetworkProperties(const std::wstring& modelName);

	// The sensor to be tested
	boost::scoped_ptr<CProxySensatronicsModelF> m_Sensor;

	static const std::wstring ConfigInXml;

};
