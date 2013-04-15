#pragma once

#include "Subject.h"
#include "ProxyDataPoint.h"
#include "ServiceTlb.h"

#include <string>
#include <vector>
#include <map>

#include <boost/scoped_ptr.hpp>

class CProxyDataPoint;
class CSubjectImpl;
class CProbeToProxyMapperSink;

class CProxyProbe :	public ISubject
{
public:
	// Default constructor, construct a new COM sensor
	CProxyProbe(void);

	// Proxy the given COM probe
	CProxyProbe(ox::IProbe*);
	virtual ~CProxyProbe(void);

	// Register to be notified when changes occur to the subject
	virtual void Attach(IObserver*);

	// De-register from receiving change notifications
	virtual void Detach(IObserver*);

	// Notify all observers that the subject has changed
	virtual void Notify(IHint*);

	// The probe has changed into a switch
	virtual void TransitionToSwitch(void);

	// Set the probe name
	virtual void SetName(const std::wstring& NewName);

	// Return the probe name
	virtual const std::wstring& GetName(void) const;

	// Set the probe type
	virtual void SetType(const std::wstring& NewType);

	// Return the probe type
	virtual const std::wstring& GetType(void) const;

	// Return the probe number
	virtual int GetNumber(void) const;

	// Return the group number
	virtual int GetGroup(void) const;

	// Return the most recent data point
	virtual CProxyDataPoint* GetMostRecentDataPoint(void);

	// Return the proxied COM interface
	virtual ox::IProbe* GetComInterface();

private:
	// The subject implementation object
	boost::scoped_ptr<CSubjectImpl> m_SubjectImpl;

	// The sink used to convert COM events into Observer notifications
	boost::scoped_ptr<CProbeToProxyMapperSink> m_EventMapper;

	// The probe being proxied
	ox::IProbePtr m_Probe;

	// Buffer used by the name getter
	mutable std::wstring m_Name;

	// Buffer used by the type getter
	mutable std::wstring m_Type;

};
