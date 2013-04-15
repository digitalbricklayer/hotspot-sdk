#include "stdafx.h"

#include "ProbeSink.h"
#include "ProxyProbe.h"
#include "Subject.h"
#include "Hint.h"

#include <memory>
#include <comutils/combool.h>
#include <comutils/comdate.h>

CProbeToProxyMapperSink::CProbeToProxyMapperSink(CProxyProbe* theProbe)
: m_Probe(theProbe)
{
}

CProbeToProxyMapperSink::~CProbeToProxyMapperSink()
{
}

HRESULT __stdcall CProbeToProxyMapperSink::OnPollBegin()
{
	std::auto_ptr<CHint> theHint(new CHint(IHint::probe_poll_begin));
	m_Probe->Notify(theHint.get());
	return S_OK;
}

HRESULT __stdcall CProbeToProxyMapperSink::OnPollEnd()
{
	std::auto_ptr<CHint> theHint(new CHint(IHint::probe_poll_end));
	m_Probe->Notify(theHint.get());
	return S_OK;
}