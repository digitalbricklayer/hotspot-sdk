#include "StdAfx.h"
#include "SensorObserver.h"
#include "SensorSinkHints.h"
#include "Hint.h"

void CSensorObserver::Update(ISubject* theSubject, IHint* theHint)
{
	switch (theHint->GetTypeId())
	{
	case IHint::sensor_poll_begin:
		OnPollBegin(theSubject);
		break;

	case IHint::sensor_poll_end:
		{
			CSensorPollEndHint* theSpecificHint = static_cast<CSensorPollEndHint*>(theHint);
			OnPollEnd(theSubject, theSpecificHint->GetStatus());
		}
		break;

	case IHint::sensor_name_change:
		OnNameChange(theSubject);
		break;

	case IHint::sensor_enable_change:
		{
			CSensorEnableChangeHint* theSpecificHint = static_cast<CSensorEnableChangeHint*>(theHint);
			OnEnableChange(theSubject, theSpecificHint->GetLastValue());
		}
		break;

	case IHint::sensor_probe_add:
		{
			CSensorAddProbeHint* theSpecificHint = static_cast<CSensorAddProbeHint*>(theHint);
			OnProbeAdd(theSubject, theSpecificHint->GetNewProbe());
		}
		break;

	default:
		ASSERT(false);
		break;
	}
}

void CSensorObserver::OnPollBegin(ISubject*)
{
}

void CSensorObserver::OnPollEnd(ISubject*, const std::wstring&)
{
}

void CSensorObserver::OnNameChange(ISubject*)
{
}

void CSensorObserver::OnEnableChange(ISubject*, bool)
{
}

void CSensorObserver::OnProbeAdd(ISubject*, CProxyProbe*)
{
}
