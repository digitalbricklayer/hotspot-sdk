#pragma once

class ISubject;
class IHint;

class IObserver
{
public:
	// The given subject has changed, exactly what changed is in the hint
	virtual void Update(ISubject*, IHint*) = 0;

};
