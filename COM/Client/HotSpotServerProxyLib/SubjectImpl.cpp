#include "StdAfx.h"
#include "SubjectImpl.h"
#include "Observer.h"
#include <algorithm>

CSubjectImpl::CSubjectImpl()
: m_Subject(0), m_IsNotifying(false)
{
}

CSubjectImpl::~CSubjectImpl(void)
{
}

void CSubjectImpl::Attach(IObserver* Observer)
{
	ASSERT(!m_IsNotifying);
	ASSERT(std::find(m_Observers.begin(), m_Observers.end(), Observer) == m_Observers.end());

	m_Observers.push_back(Observer);

	ASSERT(std::find(m_Observers.begin(), m_Observers.end(), Observer) != m_Observers.end());
}

void CSubjectImpl::Detach(IObserver* Observer)
{
	ASSERT(!m_IsNotifying);
	ASSERT(std::find(m_Observers.begin(), m_Observers.end(), Observer) != m_Observers.end());

	m_Observers.remove(Observer);

	ASSERT(std::find(m_Observers.begin(), m_Observers.end(), Observer) == m_Observers.end());
}

void CSubjectImpl::Notify(IHint* aHint)
{
	ASSERT(m_Subject);
	m_IsNotifying = true;

	ObserverContainer::iterator it;
	for (it = m_Observers.begin(); it != m_Observers.end(); ++it)
	{
		(*it)->Update(m_Subject, aHint);
	}
	m_IsNotifying = false;
}
