#pragma once
#include "observer.h"
#include <string>

class CProxyDataPoint;

/*
 * A base class for all probe observers. The class decodes the notifications
 * and calls the appropriate notification handler.
 */

class CProbeObserver : public IObserver
{
public:
	virtual ~CProbeObserver(void) {}

	// The notification function, decode the notification and call the appropriate handler
	virtual void Update(ISubject*, IHint*);

protected:
	// This is an abstract class, so hide the constructor
	CProbeObserver(void) {}

	// The poll has started
	virtual void OnPollBegin(ISubject*);

	// The poll has finished
	virtual void OnPollEnd(ISubject*);

};
