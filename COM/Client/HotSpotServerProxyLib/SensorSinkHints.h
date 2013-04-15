// Hints used by the Sensor proxy

#pragma once

#include "Hint.h"
#include <string>
//#include "ProxySensor.h"
#include "ProxyProbe.h"

class CSensorPollEndHint : public IHint
{
public:
	CSensorPollEndHint(const std::wstring& Status) { }
	virtual ~CSensorPollEndHint(void) { }

	virtual int GetTypeId(void) const { return sensor_poll_end; }

	virtual const std::wstring& GetStatus(void) const { return m_Status; }

private:
	std::wstring m_Status;

};

class CSensorEnableChangeHint : public IHint
{
public:
	CSensorEnableChangeHint(bool Value): m_Value(Value) { }
	virtual ~CSensorEnableChangeHint(void) { }

	virtual int GetTypeId(void) const { return sensor_enable_change; }

	virtual bool GetLastValue(void) { return m_Value; }

private:
	bool m_Value;

};

class CSensorAddProbeHint : public IHint
{
public:
	CSensorAddProbeHint(CProxyProbe* Value): m_NewProbe(Value) { }
	virtual ~CSensorAddProbeHint(void) { }

	virtual int GetTypeId(void) const { return sensor_probe_add; }

	virtual CProxyProbe* GetNewProbe(void) { return m_NewProbe; }

private:
	CProxyProbe* m_NewProbe;

};
