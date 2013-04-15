#pragma once

#include <cppunit/extensions/HelperMacros.h>

#include <boost/scoped_ptr.hpp>

class CProxyProbe;

class CProbeTest : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(CProbeTest);
		CPPUNIT_TEST(testName);
		CPPUNIT_TEST(testNameSameName);
		CPPUNIT_TEST(testNameEmpty);
		CPPUNIT_TEST(testNameDefault);
		CPPUNIT_TEST(testNameMax);
		CPPUNIT_TEST(testNameMaxPlusOne);
		CPPUNIT_TEST(testTypeDefault);
		CPPUNIT_TEST(testTypeSameType);
		CPPUNIT_TEST(testTypeTemperature);
		CPPUNIT_TEST(testTypeHumidity);
		CPPUNIT_TEST(testTypeWetness);
		CPPUNIT_TEST(testTypeSwitch);
		CPPUNIT_TEST(testTypeJunk);
	CPPUNIT_TEST_SUITE_END();

public:

	CProbeTest();
	~CProbeTest();

	void setUp();
	void tearDown();

	void testName();
	void testNameSameName();
	void testNameEmpty();
	void testNameDefault();
	void testNameMax();
	void testNameMaxPlusOne();
	void testTypeDefault();
	void testTypeSameType();
	void testTypeTemperature();
	void testTypeHumidity();
	void testTypeWetness();
	void testTypeSwitch();
	void testEnableDefault();
	void testEnableDisable();
	void testTypeJunk();

private:
	// The probe to be tested
	boost::scoped_ptr<CProxyProbe> m_Probe;
};
