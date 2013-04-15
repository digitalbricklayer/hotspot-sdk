#include "StdAfx.h"
#include "ProxyDataPoint.h"

#include "Observer.h"
#include "SubjectImpl.h"
#include "DataPointSink.h"
#include "server_comms_error.h"
#include "bad_argument_error.h"

#include <comutils/comdate.h>
#include <comutils/combool.h>

CProxyDataPoint::CProxyDataPoint(void)
: m_SubjectImpl(new CSubjectImpl)
{
	m_SubjectImpl->SetSubject(this);
	try
	{
		m_DataPoint.CreateInstance(ox::CLSID_DataPoint);
		m_EventMapper.reset(new CDataPointToProxyMapperSink(this));
		m_EventMapper->DispEventAdvise(m_DataPoint);
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

CProxyDataPoint::CProxyDataPoint(ox::IDataPoint* DataPointToProxy)
: m_SubjectImpl(new CSubjectImpl), m_DataPoint(DataPointToProxy)
{
	m_SubjectImpl->SetSubject(this);
	try
	{
		m_EventMapper.reset(new CDataPointToProxyMapperSink(this));
		m_EventMapper->DispEventAdvise(m_DataPoint);
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

CProxyDataPoint::~CProxyDataPoint(void)
{
	m_EventMapper->DispEventUnadvise(m_DataPoint);
	m_DataPoint.Release();
}

void CProxyDataPoint::Attach(IObserver* Observer)
{
	m_SubjectImpl->Attach(Observer);
}

void CProxyDataPoint::Detach(IObserver* Observer)
{
	m_SubjectImpl->Detach(Observer);
}

void CProxyDataPoint::Notify(IHint* aHint)
{
	m_SubjectImpl->Notify(aHint);
}

CTime CProxyDataPoint::GetTime() const
{
	try
	{
		const CComDATE ServiceDate = m_DataPoint->GetTime();
		return CTime(
			ServiceDate.Year(), ServiceDate.Month(), ServiceDate.Day(), 
			ServiceDate.Hour(), ServiceDate.Minute(), ServiceDate.Second()
			); 
	}
	catch (...)
	{
		throw new service_comms_error;
	}
}

double CProxyDataPoint::GetValue() const
{
	try
	{
		return m_DataPoint->GetValue();
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

const std::wstring& CProxyDataPoint::GetUnit() const
{
	try
	{
		const std::wstring tmp(m_DataPoint->GetUnit());
		m_Unit = tmp;
		return m_Unit;
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

void CProxyDataPoint::SetUnit(const std::wstring newUnitType)
{
	try
	{
		const _bstr_t tmp = newUnitType.c_str();
		m_DataPoint->PutUnit(tmp);
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
