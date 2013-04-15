#include "StdAfx.h"
#include "ProxyMockSensors.h"

#include "Observer.h"
#include "SubjectImpl.h"
#include "server_comms_error.h"
#include "bad_argument_error.h"

#include <comutils/comdate.h>
#include <comutils/combool.h>

CProxyMockSensors::CProxyMockSensors()
: m_SubjectImpl(new CSubjectImpl)
{
	m_SubjectImpl->SetSubject(this);
	try
	{
		m_MockSensors.CreateInstance(MockSensorsLib::CLSID_MockSensor);
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

CProxyMockSensors::CProxyMockSensors(MockSensorsLib::IMockSensor* ProxiedObject)
: m_SubjectImpl(new CSubjectImpl), m_MockSensors(ProxiedObject)
{
	m_SubjectImpl->SetSubject(this);
}

CProxyMockSensors::~CProxyMockSensors(void)
{
	m_MockSensors.Release();
}

void CProxyMockSensors::Attach(IObserver* Observer)
{
	m_SubjectImpl->Attach(Observer);
}

void CProxyMockSensors::Detach(IObserver* Observer)
{
	m_SubjectImpl->Detach(Observer);
}

void CProxyMockSensors::Notify(IHint* aHint)
{
	m_SubjectImpl->Notify(aHint);
}

void CProxyMockSensors::AddSensor(const std::wstring& SensorName, const std::wstring& ConfigInfo, const std::wstring& XmlData, const CTime& PollTime)
{
	try
	{
		_bstr_t SensorNameBstr(SensorName.c_str());
		_bstr_t ConfigInfoBstr(ConfigInfo.c_str());
		_bstr_t XmlDataBstr(XmlData.c_str());
		SYSTEMTIME SystemTime;
		PollTime.GetAsSystemTime(SystemTime);
		CComDATE PollTimeCom(SystemTime);

		m_MockSensors->AddSensor(SensorNameBstr, ConfigInfoBstr, XmlDataBstr, PollTimeCom);
	}
	catch (const _com_error& e)
	{
		if (e.Error() == E_INVALIDARG)
		{
			throw bad_argument_error("");
		}
		else
		{
			throw service_comms_error();
		}
	}
}

void CProxyMockSensors::AddSensorPollData(const std::wstring& SensorName, const CTime& PollTime, const std::wstring& PollData)
{
	try
	{
		_bstr_t SensorNameBstr = SensorName.c_str();
		_bstr_t PollDataBstr = PollData.c_str();
		SYSTEMTIME SystemTime;
		PollTime.GetAsSystemTime(SystemTime);
		CComDATE PollTimeCom(SystemTime);
		m_MockSensors->AddSensorPollData(SensorNameBstr, PollDataBstr, PollTimeCom);
	}
	catch (const _com_error& e)
	{
		if (e.Error() == E_INVALIDARG)
		{
			throw bad_argument_error("");
		}
		else
		{
			throw service_comms_error();
		}
	}
}
