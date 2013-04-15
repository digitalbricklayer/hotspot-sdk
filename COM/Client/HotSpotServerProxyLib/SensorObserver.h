#pragma once

#include "observer.h"

#include <string>

class CProxyProbe;

/*
 * A base class for all sensor observers. The class decodes the notifications
 * and calls the appropriate notification handler.
 */

class CSensorObserver : public IObserver
{
public:
	virtual ~CSensorObserver(void) {}

	// The notification function, decode the notification and call the appropriate handler
	virtual void Update(ISubject*, IHint*);

protected:
	// This is an abstract class, so hide the constructor
	CSensorObserver(void) {}

	// The poll has started
	virtual void OnPollBegin(ISubject*);

	// The poll has finished
	virtual void OnPollEnd(ISubject*, const std::wstring& Status);

	// The name has changed
	virtual void OnNameChange(ISubject*);

	// The enabled state has changed
	virtual void OnEnableChange(ISubject*, bool);

	// A new probe has been added
	virtual void OnProbeAdd(ISubject*, CProxyProbe*);

};
