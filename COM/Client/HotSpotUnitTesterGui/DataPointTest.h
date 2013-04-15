#pragma once

#include <cppunit/extensions/HelperMacros.h>
#include <boost/scoped_ptr.hpp>

class CProxyHotSpotServer;
class CProxySensatronicsModelE;
class CProxyProbe;
class CProxyDataPoint;
class CProxyMockSensors;

class CDataPointTest : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(CDataPointTest);
		CPPUNIT_TEST(testGetTime);
		CPPUNIT_TEST(testGetValue);
		CPPUNIT_TEST(testUnitEmpty);
		CPPUNIT_TEST(testUnitJunk);
	CPPUNIT_TEST_SUITE_END();

public:
	CDataPointTest();
	~CDataPointTest();

	void setUp();
	void tearDown();

	void testGetTime();
	void testGetValue();
	void testUnitEmpty();
	void testUnitJunk();

private:
	boost::scoped_ptr<CProxySensatronicsModelE> m_Sensor;

	boost::scoped_ptr<CProxyProbe> m_Probe;

	// The data point to be tested
	boost::scoped_ptr<CProxyDataPoint> m_DataPoint;

	boost::scoped_ptr<CProxyMockSensors> m_MockSensors;

	// The time the poll happened
	CTime m_PollTime;

	static const std::wstring ConfigInXml;
	static const std::wstring XmlData;
	static const std::wstring XmlPoll;

};
