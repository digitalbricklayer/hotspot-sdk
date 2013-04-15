#include "StdAfx.h"

#include "ProxyProbe.h"
#include "Observer.h"
#include "SubjectImpl.h"
#include "ProbeSink.h"
#include "server_comms_error.h"
#include "bad_argument_error.h"
#include "deleter.h"

#include <comutils/comdate.h>
#include <comutils/combool.h>
#include <algorithm>

CProxyProbe::CProxyProbe(void)
: m_SubjectImpl(new CSubjectImpl)
{
	m_SubjectImpl->SetSubject(this);
	try
	{
		m_Probe.CreateInstance(ox::CLSID_Probe);
		m_EventMapper.reset(new CProbeToProxyMapperSink(this));
		m_EventMapper->DispEventAdvise(m_Probe);
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

CProxyProbe::CProxyProbe(ox::IProbe* ProbeToProxy)
: m_SubjectImpl(new CSubjectImpl), m_Probe(ProbeToProxy)
{
	m_SubjectImpl->SetSubject(this);
	try
	{
		m_EventMapper.reset(new CProbeToProxyMapperSink(this));
		m_EventMapper->DispEventAdvise(m_Probe);
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

CProxyProbe::~CProxyProbe(void)
{
	m_EventMapper->DispEventUnadvise(m_Probe);
	m_Probe.Release();
}

void CProxyProbe::Attach(IObserver* Observer)
{
	m_SubjectImpl->Attach(Observer);
}

void CProxyProbe::Detach(IObserver* Observer)
{
	m_SubjectImpl->Detach(Observer);
}

void CProxyProbe::Notify(IHint* aHint)
{
	m_SubjectImpl->Notify(aHint);
}

void CProxyProbe::TransitionToSwitch(void)
{
}

void CProxyProbe::SetName(const std::wstring& NewName)
{
	try
	{
		const _bstr_t tmp = NewName.c_str();
		m_Probe->PutName(tmp);
	}
	catch (const _com_error& e)
	{
		if (e.Error() == E_INVALIDARG)
		{
			throw bad_argument_error("");
		}
		else
		{
			throw service_comms_error();
		}
	}
}

const std::wstring& CProxyProbe::GetName(void) const
{
	try
	{
		const std::wstring tmp(m_Probe->GetName());
		m_Name = tmp;
		return m_Name;
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

void CProxyProbe::SetType(const std::wstring& NewType)
{
	try
	{
		const _bstr_t tmp = NewType.c_str();
		m_Probe->PutType(tmp);
	}
	catch (const _com_error& e)
	{
		if (e.Error() == E_INVALIDARG)
		{
			throw bad_argument_error("");
		}
		else
		{
			throw service_comms_error();
		}
	}
}

const std::wstring& CProxyProbe::GetType(void) const
{
	try
	{
		const std::wstring tmp(m_Probe->GetType());
		m_Type = tmp;
		return m_Type;
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

int CProxyProbe::GetNumber(void) const
{
	try
	{
		return m_Probe->GetNumber();
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

int CProxyProbe::GetGroup(void) const
{
	try
	{
		return m_Probe->GetGroup();
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

CProxyDataPoint* CProxyProbe::GetMostRecentDataPoint(void)
{
	try
	{
		return new CProxyDataPoint(m_Probe->GetMostRecentDataPoint());
	}
	catch (const _com_error& e)
	{
		if (e.Error() == E_INVALIDARG)
		{
			throw bad_argument_error("");
		}
		else
		{
			throw service_comms_error();
		}
	}

	return NULL;
}

ox::IProbe* CProxyProbe::GetComInterface()
{
	return m_Probe;
}