#include "StdAfx.h"
#include "ProxySensatronicsModelE.h"
#include "ProxyProbe.h"
#include "Observer.h"
#include "SubjectImpl.h"
#include "SensatronicsModelESink.h"
#include "deleter.h"

#include "server_comms_error.h"
#include "bad_argument_error.h"

#include <comutils/comdate.h>
#include <comutils/combool.h>
#include <algorithm>

CProxySensatronicsModelE::CProxySensatronicsModelE(void)
: m_SubjectImpl(new CSubjectImpl)
{
	m_SubjectImpl->SetSubject(this);
	try
	{
		m_Sensor.CreateInstance(ox::CLSID_SensatronicsModelE);
		m_EventMapper.reset(new CSensatronicsModelEToProxyMapperSink(this));
		m_EventMapper->DispEventAdvise(m_Sensor);
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

CProxySensatronicsModelE::CProxySensatronicsModelE(ox::ISensatronicsModelE* SensorToProxy)
: m_SubjectImpl(new CSubjectImpl), m_Sensor(SensorToProxy)
{
	m_SubjectImpl->SetSubject(this);
	try
	{
		FixupProxyProbes();
		m_EventMapper.reset(new CSensatronicsModelEToProxyMapperSink(this));
		m_EventMapper->DispEventAdvise(m_Sensor);
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

CProxySensatronicsModelE::~CProxySensatronicsModelE(void)
{
	m_EventMapper->DispEventUnadvise(m_Sensor);
	CleanupProbes();
	m_Sensor.Release();
}

void CProxySensatronicsModelE::Attach(IObserver* Observer)
{
	m_SubjectImpl->Attach(Observer);
}

void CProxySensatronicsModelE::Detach(IObserver* Observer)
{
	m_SubjectImpl->Detach(Observer);
}

void CProxySensatronicsModelE::Notify(IHint* aHint)
{
	m_SubjectImpl->Notify(aHint);
}

void CProxySensatronicsModelE::AddProbe(CProxyProbe* NewProbe)
{
	StoreProbe(NewProbe);
}

void CProxySensatronicsModelE::SetName(const std::wstring& NewName)
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

const std::wstring& CProxySensatronicsModelE::GetName(void) const
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

const CProxySensatronicsModelE::ProbeContainer& CProxySensatronicsModelE::GetProbes() const
{
	return m_Probes;
}

void CProxySensatronicsModelE::SetModel(const std::wstring& NewModel)
{
	try
	{
		_bstr_t tmp = NewModel.c_str();
		m_Sensor->PutModel(tmp);
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

const std::wstring& CProxySensatronicsModelE::GetModel(void)
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

void CProxySensatronicsModelE::SetIpAddress(const std::wstring& NewIpAddress)
{
	try
	{
		_bstr_t tmp = NewIpAddress.c_str();
		m_Sensor->PutIpAddress(tmp);
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

const std::wstring& CProxySensatronicsModelE::GetIpAddress(void)
{
	try
	{
		_bstr_t tmp = m_Sensor->GetIpAddress();
		m_IpAddress = tmp;
		return m_IpAddress;
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

const std::wstring& CProxySensatronicsModelE::GetMask(void)
{
	try
	{
		_bstr_t tmp = m_Sensor->GetMask();
		m_Mask = tmp;
		return m_Mask;
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

void CProxySensatronicsModelE::SetSnmpWriteCommunityName(const std::wstring& NewCommunityName)
{
	try
	{
		_bstr_t tmp = NewCommunityName.c_str();
		m_Sensor->PutSnmpWriteCommunityString(tmp);
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

const std::wstring& CProxySensatronicsModelE::GetSnmpWriteCommunityName(void)
{
	try
	{
		_bstr_t tmp = m_Sensor->GetSnmpWriteCommunityString();
		m_SnmpWriteCommunityName = tmp;
		return m_SnmpWriteCommunityName;
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

void CProxySensatronicsModelE::SetSnmpReadCommunityName(const std::wstring& NewCommunityName)
{
	try
	{
		_bstr_t tmp = NewCommunityName.c_str();
		m_Sensor->PutSnmpReadCommunityString(tmp);
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

const std::wstring& CProxySensatronicsModelE::GetSnmpReadCommunityName(void)
{
	try
	{
		_bstr_t tmp = m_Sensor->GetSnmpReadCommunityString();
		m_SnmpReadCommunityName = tmp;
		return m_SnmpReadCommunityName;
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

const std::wstring& CProxySensatronicsModelE::GetSoftwareVersion(void)
{
	try
	{
		_bstr_t tmp = m_Sensor->GetSoftwareVersion();
		m_SoftwareVersion = tmp;
		return m_SoftwareVersion;
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

const std::wstring& CProxySensatronicsModelE::GetSoftwareReleaseDate(void)
{
	try
	{
		_bstr_t tmp = m_Sensor->GetSoftwareReleaseDate();
		m_SoftwareReleaseDate = tmp;
		return m_SoftwareReleaseDate;
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

const std::wstring& CProxySensatronicsModelE::GetSerialNumber(void)
{
	try
	{
		_bstr_t tmp = m_Sensor->GetSerialNumber();
		m_SerialNumber = tmp;
		return m_SerialNumber;
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

const std::wstring& CProxySensatronicsModelE::GetSnmpTrapIpAddress(void)
{
	try
	{
		_bstr_t tmp = m_Sensor->GetSnmpTrapIpAddress();
		m_SnmpTrapIpAddress = tmp;
		return m_SnmpTrapIpAddress;
	}
	catch (...)
	{
		throw service_comms_error();
	}
}

ox::ISensatronicsModelE* CProxySensatronicsModelE::GetComInterface()
{
	return m_Sensor;
}

void CProxySensatronicsModelE::FixupProxyProbes()
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

void CProxySensatronicsModelE::StoreProbe(CProxyProbe* NewProbe)
{
	ASSERT(NewProbe->GetComInterface());

	m_Probes.push_back(NewProbe);
}

CProxyProbe* CProxySensatronicsModelE::FindProbeByNumber(int ProbeNumber)
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

void CProxySensatronicsModelE::CleanupProbes()
{
	std::for_each(m_Probes.begin(), m_Probes.end(), deleter<CProxyProbe>());
	m_Probes.clear();
}

void CProxySensatronicsModelE::Poll(void)
{
	try
	{
		GetComInterface()->Poll();
	}
	catch (...)
	{
		throw service_comms_error();
	}
}