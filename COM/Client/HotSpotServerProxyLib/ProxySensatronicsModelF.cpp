#include "StdAfx.h"
#include "ProxySensatronicsModelF.h"
#include "ProxyProbe.h"
#include "Observer.h"
#include "SubjectImpl.h"
#include "SensatronicsModelFSink.h"
#include "deleter.h"

#include "server_comms_error.h"
#include "bad_argument_error.h"

#include <comutils/comdate.h>
#include <comutils/combool.h>
#include <algorithm>

CProxySensatronicsModelF::CProxySensatronicsModelF(void)
: m_SubjectImpl(new CSubjectImpl)
{
	m_SubjectImpl->SetSubject(this);
	try
	{
		m_Sensor.CreateInstance(ox::CLSID_SensatronicsModelF);
		m_EventMapper.reset(new CSensatronicsModelFToProxyMapperSink(this));
		m_EventMapper->DispEventAdvise(m_Sensor);
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

CProxySensatronicsModelF::CProxySensatronicsModelF(ox::ISensatronicsModelF* SensorToProxy)
: m_SubjectImpl(new CSubjectImpl), m_Sensor(SensorToProxy)
{
	m_SubjectImpl->SetSubject(this);
	try
	{
		FixupProxyProbes();
		m_EventMapper.reset(new CSensatronicsModelFToProxyMapperSink(this));
		m_EventMapper->DispEventAdvise(m_Sensor);
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

CProxySensatronicsModelF::~CProxySensatronicsModelF(void)
{
	m_EventMapper->DispEventUnadvise(m_Sensor);
	CleanupProbes();
	m_Sensor.Release();
}

void CProxySensatronicsModelF::Attach(IObserver* Observer)
{
	m_SubjectImpl->Attach(Observer);
}

void CProxySensatronicsModelF::Detach(IObserver* Observer)
{
	m_SubjectImpl->Detach(Observer);
}

void CProxySensatronicsModelF::Notify(IHint* aHint)
{
	m_SubjectImpl->Notify(aHint);
}

void CProxySensatronicsModelF::AddProbe(CProxyProbe* NewProbe)
{
	StoreProbe(NewProbe);
}

void CProxySensatronicsModelF::SetName(const std::wstring& NewName)
{
	try
	{
		_bstr_t tmp = NewName.c_str();
		m_Sensor->PutName(tmp);
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

const std::wstring& CProxySensatronicsModelF::GetName(void) const
{
	try
	{
		std::wstring tmp(m_Sensor->GetName());
		m_Name = tmp;
		return m_Name;
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

const CProxySensatronicsModelF::ProbeContainer& CProxySensatronicsModelF::GetProbes() const
{
	return m_Probes;
}

const std::wstring& CProxySensatronicsModelF::GetModel(void)
{
	try
	{
		_bstr_t tmp = m_Sensor->GetModel();
		m_Model = tmp;
		return m_Model;
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

void CProxySensatronicsModelF::SetComPort(const std::wstring& NewComPort)
{
	try
	{
		_bstr_t tmp = NewComPort.c_str();
		m_Sensor->PutComPort(tmp);
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

const std::wstring& CProxySensatronicsModelF::GetComPort(void)
{
	try
	{
		_bstr_t tmp = m_Sensor->GetComPort();
		m_ComPort = tmp;
		return m_ComPort;
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

const std::wstring& CProxySensatronicsModelF::GetBatteryStatus(void)
{
	try
	{
		_bstr_t tmp = m_Sensor->GetBatteryStatus();
		m_BatteryStatus = tmp;
		return m_BatteryStatus;
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

ox::ISensatronicsModelF* CProxySensatronicsModelF::GetComInterface()
{
	return m_Sensor;
}

void CProxySensatronicsModelF::FixupProxyProbes()
{
	CComQIPtr<ox::IProbeCollection> Probes = GetComInterface()->GetProbeCollection();

	const long NumProbes = Probes->GetCount();

	for (int i = 1; i <= NumProbes; ++i)
	{
		CComQIPtr<ox::IProbe> Probe = Probes->Item(CComVariant(i));
		CProxyProbe* ProxyProbe = new CProxyProbe(Probe);
		StoreProbe(ProxyProbe);
	}
}

void CProxySensatronicsModelF::StoreProbe(CProxyProbe* NewProbe)
{
	ASSERT(NewProbe->GetComInterface());

	m_Probes.push_back(NewProbe);
}

CProxyProbe* CProxySensatronicsModelF::FindProbeByNumber(int ProbeNumber)
{
	ASSERT(ProbeNumber > 0);

	CProxyProbe* FoundProbe = NULL;

	CComQIPtr<ox::IProbe> Probe = GetComInterface()->GetProbe(ProbeNumber);

	FoundProbe = new CProxyProbe(Probe);

	/*ProbeContainer::iterator it;


	for (it = m_Probes.begin(); it != m_Probes.end(); ++it)
	{
		if ((*it)->GetNumber() == ProbeNumber)
		{
			FoundProbe = *it;
			break;
		}
	}*/

	return FoundProbe;
}

void CProxySensatronicsModelF::CleanupProbes()
{
	std::for_each(m_Probes.begin(), m_Probes.end(), deleter<CProxyProbe>());
	m_Probes.clear();
}
