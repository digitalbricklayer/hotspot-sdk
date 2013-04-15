#pragma once

#include "Subject.h"
#include <list>

class IObserver;
class IHint;

class CSubjectImpl : public ISubject
{
public:
	CSubjectImpl(void);
	virtual ~CSubjectImpl(void);

	virtual void SetSubject(ISubject* theSubject) { ASSERT(theSubject != NULL); m_Subject = theSubject; }

	virtual void Attach(IObserver*);

	virtual void Detach(IObserver*);

	virtual void Notify(IHint*);

private:
	// The subject for whom this implementation is for
	ISubject* m_Subject;

	bool m_IsNotifying;

	typedef std::list<IObserver*> ObserverContainer;

	ObserverContainer m_Observers;

};
