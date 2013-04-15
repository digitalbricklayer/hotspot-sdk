#pragma once
#include "Subject.h"
#include "ProxyDataPoint.h"
#include "ServiceTlb.h"

#include <string>
#include <list>
#include <map>

#include <boost/scoped_ptr.hpp>

class CProxyProbe;
class CSubjectImpl;
class CSensatronicsModelEToProxyMapperSink;

class CProxySensatronicsModelE : public ISubject
{
public:
	// Default constructor, construct a new COM sensor
	CProxySensatronicsModelE(void);

	// Proxy the given COM sensor
	CProxySensatronicsModelE(ox::ISensatronicsModelE*);
	virtual ~CProxySensatronicsModelE(void);

	// Register to be notified when changes occur to the subject
	virtual void Attach(IObserver*);

	// De-register from receiving change notifications
	virtual void Detach(IObserver*);

	// Notify all observers that the subject has changed
	virtual void Notify(IHint*);

	// Add a new probe to the sensor
	virtual void AddProbe(CProxyProbe* NewProbe);

	// Set the sensor name
	virtual void SetName(const std::wstring& NewName);

	// Return the sensor name
	virtual const std::wstring& GetName(void) const;

	typedef std::list<CProxyProbe*> ProbeContainer;

	// Return the probes
	virtual const ProbeContainer& GetProbes() const;

	// Set the Model
	virtual void SetModel(const std::wstring& NewModel);

	// Return the model name
	virtual const std::wstring& GetModel(void);

	// Set the IP address
	virtual void SetIpAddress(const std::wstring& NewIpAddress);

	// Return the IP address
	virtual const std::wstring& GetIpAddress(void);

	// Return the mask
	virtual const std::wstring& GetMask(void);

	// Get the software version
	virtual const std::wstring& GetSoftwareVersion(void);

	// Get the software release date
	virtual const std::wstring& GetSoftwareReleaseDate(void);

	// Get the serial number
	virtual const std::wstring& GetSerialNumber(void);

	// Set the SNMP read commmunity name
	virtual void SetSnmpWriteCommunityName(const std::wstring& NewMask);

	// Get the SNMP read commmunity name
	virtual const std::wstring& GetSnmpWriteCommunityName(void);

	// Set the SNMP write commmunity name
	virtual void SetSnmpReadCommunityName(const std::wstring& NewMask);

	// Get the SNMP write commmunity name
	virtual const std::wstring& GetSnmpReadCommunityName(void);

	// Get the SNMP trap IP address
	virtual const std::wstring& GetSnmpTrapIpAddress(void);

	// Return the proxied COM interface
	virtual ox::ISensatronicsModelE* GetComInterface();

	// Return the probe with the given number
	virtual CProxyProbe* FindProbeByNumber(int ProbeNumber);

	// Make the sensor poll
	virtual void Poll(void);

private:
	// Fixup the probes already existing in the COM sensor
	void FixupProxyProbes();

	// Store the proxy probe
	void StoreProbe(CProxyProbe*);

	// Remove the proxy probe
	void RemoveProbe(CProxyProbe* ProbeToRemove);

	// Delete all probes
	void CleanupProbes();

	// The subject implementation object
	boost::scoped_ptr<CSubjectImpl> m_SubjectImpl;

	// The sensor being proxied
	ox::ISensatronicsModelEPtr m_Sensor;

	// The probes attached to the sensor
	ProbeContainer m_Probes;

	// The sink used to convert COM events into Observer notifications
	boost::scoped_ptr<CSensatronicsModelEToProxyMapperSink> m_EventMapper;

	// Buffer used by the name getter
	mutable std::wstring m_Name;

	// Buffer for the model name
	mutable std::wstring m_Model;

	// Buffer for the IP address
	mutable std::wstring m_IpAddress;

	// Buffer for the mask
	mutable std::wstring m_Mask;

	// Buffer for the battery status
	mutable std::wstring m_BatteryStatus;

	// Buffer for SNMP read/write community names
	mutable std::wstring m_SnmpWriteCommunityName;
	mutable std::wstring m_SnmpReadCommunityName;

	// Buffer for software version
	mutable std::wstring m_SoftwareVersion;

	// Buffer for serial number
	mutable std::wstring m_SerialNumber;

	// Buffer for SNMP trap IP address
	mutable std::wstring m_SnmpTrapIpAddress;

	// Buffer for the COM port
	mutable std::wstring m_ComPort;

	// Buffer for the software release date
	mutable std::wstring m_SoftwareReleaseDate;

};
