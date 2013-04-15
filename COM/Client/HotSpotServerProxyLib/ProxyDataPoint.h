#pragma once

#include "subject.h"
#include "ServiceTlb.h"

#include <string>
#include <boost/scoped_ptr.hpp>

class CSubjectImpl;
class CDataPointToProxyMapperSink;

class CProxyDataPoint : public ISubject
{
public:
	// Default constructor, construct a new COM data point
	CProxyDataPoint(void);

	// Proxy the given COM data point
	CProxyDataPoint(ox::IDataPoint*);
	virtual ~CProxyDataPoint(void);

	// Register to be notified when changes occur to the subject
	virtual void Attach(IObserver*);

	// De-register from receiving change notifications
	virtual void Detach(IObserver*);

	// Notify all observers that the subject has changed
	virtual void Notify(IHint*);

	// Return the time
	virtual CTime GetTime() const;

	// Return the value
	virtual double GetValue() const;

	// Return the unit type
	virtual const std::wstring& GetUnit() const;

	// Set the unit type
	virtual void SetUnit(const std::wstring newUnitType);

private:
	// The subject implementation object
	boost::scoped_ptr<CSubjectImpl> m_SubjectImpl;

	// The sink used to convert COM events into Observer notifications
	boost::scoped_ptr<CDataPointToProxyMapperSink> m_EventMapper;

	// The data point being proxied
	ox::IDataPointPtr m_DataPoint;

	// Buffer for GetUnit()
	mutable std::wstring m_Unit;

};
