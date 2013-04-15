#include "StdAfx.h"
#include "ProbeObserver.h"
#include "Hint.h"

void CProbeObserver::Update(ISubject* theSubject, IHint* theHint)
{
	switch (theHint->GetTypeId())
	{
	case IHint::probe_poll_begin:
		OnPollBegin(theSubject);
		break;

	case IHint::probe_poll_end:
		{
			OnPollEnd(theSubject);
		}
		break;

	default:
		ASSERT(false);
		break;
	}
}

void CProbeObserver::OnPollBegin(ISubject*)
{
}

void CProbeObserver::OnPollEnd(ISubject*)
{
}