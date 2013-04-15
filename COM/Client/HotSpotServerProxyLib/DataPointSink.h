// DataPointEventCounter.h: interface for the CDataPointCounterEventSink class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "ServiceTlb.h"
class ISubject;

// Map data point events to a proxy
class CDataPointToProxyMapperSink : public IDispEventImpl<0, CDataPointToProxyMapperSink, &ox::DIID__IDataPointEvents, &ox::LIBID_ox, 1, 0>
{
public:

	CDataPointToProxyMapperSink(ISubject* theSubject);
	~CDataPointToProxyMapperSink();

// Where we pass 0x01 - is the ID of our event function,
// can be anything, depending on the server implementation.
BEGIN_SINK_MAP(CDataPointToProxyMapperSink)
	SINK_ENTRY_EX(0, ox::DIID__IDataPointEvents, 0x01, OnUnitChange)
END_SINK_MAP()

	HRESULT __stdcall OnUnitChange(BSTR NewUnit);

private:
	// The object to be informed of changes
	ISubject* m_Subject;

};
