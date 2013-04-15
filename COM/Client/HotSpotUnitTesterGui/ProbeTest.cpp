// CProbeTest.cpp

#include "StdAfx.h"
#include "ProbeTest.h"
#include "ProxyProbe.h"

#include <bad_argument_error.h>

#include <comutils/comdate.h>
#include <comutils/combool.h>

CPPUNIT_TEST_SUITE_REGISTRATION(CProbeTest);

CProbeTest::CProbeTest()
{
}

CProbeTest::~CProbeTest()
{
}

void CProbeTest::setUp()
{
	CoInitialize(NULL);
	m_Probe.reset(new CProxyProbe);
}

void CProbeTest::tearDown()
{
	m_Probe.reset();
	CoUninitialize();
}

void CProbeTest::testNameDefault()
{
	// The probe name should never be empty
	CPPUNIT_ASSERT(m_Probe->GetName().length() > 0);
}

void CProbeTest::testNameEmpty()
{
	const std::wstring OriginalName = m_Probe->GetName();

	CPPUNIT_ASSERT_THROW(m_Probe->SetName(L""), bad_argument_error);
	CPPUNIT_ASSERT(OriginalName == m_Probe->GetName());
}

void CProbeTest::testName()
{
	std::wstring NewName(L"Jim");

	m_Probe->SetName(NewName);

	CPPUNIT_ASSERT(NewName == m_Probe->GetName());
}

void CProbeTest::testNameSameName()
{
	std::wstring NewName(L"Jim");

	m_Probe->SetName(NewName);
	CPPUNIT_ASSERT_THROW(m_Probe->SetName(NewName), bad_argument_error);

	CPPUNIT_ASSERT(NewName == m_Probe->GetName());
}

void CProbeTest::testNameMax()
{
	// 16 chars
	std::wstring NewProbeName;
	std::fill_n(back_inserter(NewProbeName), 16, L'A');

	m_Probe->SetName(NewProbeName);

	CPPUNIT_ASSERT(NewProbeName == m_Probe->GetName());
}

void CProbeTest::testNameMaxPlusOne()
{
	const std::wstring OriginalName = m_Probe->GetName();

	// 16+1 chars
	std::wstring NewProbeName;
	std::fill_n(back_inserter(NewProbeName), 16+1, L'A');

	CPPUNIT_ASSERT_THROW(m_Probe->SetName(NewProbeName), bad_argument_error);
	CPPUNIT_ASSERT(OriginalName == m_Probe->GetName());
}

void CProbeTest::testTypeDefault()
{
	const std::wstring DefaultProbeType(L"not set");

	CPPUNIT_ASSERT(DefaultProbeType == m_Probe->GetType());
}

void CProbeTest::testTypeSameType()
{
	const std::wstring NewProbeType(L"Temperature");
	m_Probe->SetType(NewProbeType);
	CPPUNIT_ASSERT_THROW(m_Probe->SetType(NewProbeType), bad_argument_error);

	CPPUNIT_ASSERT(NewProbeType == m_Probe->GetType());
}

void CProbeTest::testTypeTemperature()
{
	const std::wstring DefaultProbeType(L"not set");

	const std::wstring NewProbeType(L"Temperature");
	m_Probe->SetType(NewProbeType);

	CPPUNIT_ASSERT(NewProbeType == m_Probe->GetType());
}

void CProbeTest::testTypeHumidity()
{
	const std::wstring DefaultProbeType(L"not set");

	const std::wstring NewProbeType(L"Humidity");
	m_Probe->SetType(NewProbeType);

	CPPUNIT_ASSERT(NewProbeType == m_Probe->GetType());
}

void CProbeTest::testTypeWetness()
{
	const std::wstring DefaultProbeType(L"not set");
	const std::wstring NewProbeType(L"Wetness");
	m_Probe->SetType(NewProbeType);

	CPPUNIT_ASSERT(NewProbeType == m_Probe->GetType());
}

void CProbeTest::testTypeSwitch()
{
	const std::wstring DefaultProbeType(L"not set");

	const std::wstring NewProbeType(L"Switch");
	m_Probe->SetType(NewProbeType);

	CPPUNIT_ASSERT(NewProbeType == m_Probe->GetType());
}

void CProbeTest::testTypeJunk()
{
	const std::wstring OriginalProbeType = m_Probe->GetType();

	CPPUNIT_ASSERT_THROW(m_Probe->SetType(L"zzz"), bad_argument_error);
	CPPUNIT_ASSERT(OriginalProbeType == m_Probe->GetType());
}
