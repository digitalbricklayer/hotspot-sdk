#pragma once

#include "subject.h"
#include "ServiceTlb.h"

#include <string>
#include <boost/scoped_ptr.hpp>

class CSubjectImpl;

class CProxyMockSensors : public ISubject
{
public:
	CProxyMockSensors();
	CProxyMockSensors(MockSensorsLib::IMockSensor* ProxiedObject);
	virtual ~CProxyMockSensors(void);

	// Register to be notified when changes occur to the subject
	virtual void Attach(IObserver*);

	// De-register from receiving change notifications
	virtual void Detach(IObserver*);

	// Notify all observers that the subject has changed
	virtual void Notify(IHint*);

	// Add a mock sensor
	virtual void AddSensor(const std::wstring& SensorName, const std::wstring& ConfigData, const std::wstring& XmlData, const CTime& PollTime);

	// Add poll data to the mock
	virtual void AddSensorPollData(const std::wstring& SensorName, const CTime& PollTime, const std::wstring& PollData);

private:
	// The subject implementation object
	boost::scoped_ptr<CSubjectImpl> m_SubjectImpl;

	// The data point being proxied
	MockSensorsLib::IMockSensorPtr m_MockSensors;

};
