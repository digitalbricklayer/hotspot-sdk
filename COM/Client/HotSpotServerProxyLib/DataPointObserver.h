#pragma once
#include "observer.h"
#include <string>

/*
 * A base class for all data point observers. The class decodes the notifications
 * and calls the appropriate notification handler.
 */

class CDataPointObserver : public IObserver
{
public:
	virtual ~CDataPointObserver(void);

	// The notification function, decode the notification and call the appropriate handler
	virtual void Update(ISubject*, IHint*);

protected:
	// This is an abstract class, so hide the constructor
	CDataPointObserver(void);

	// The unit type has changed
	virtual void OnUnitChange(ISubject* Source, std::wstring NewUnitType) {}

};
