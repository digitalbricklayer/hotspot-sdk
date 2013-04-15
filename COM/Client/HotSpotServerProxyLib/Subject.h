#pragma once

class IObserver;
class IHint;

class ISubject
{
public:
	// Register to be notified when changes occur to the subject
	virtual void Attach(IObserver*) = 0;

	// De-register from receiving change notifications
	virtual void Detach(IObserver*) = 0;

	// Notify all observers that the subject has changed
	virtual void Notify(IHint*) = 0;

};
