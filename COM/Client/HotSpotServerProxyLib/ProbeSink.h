// ProbeSink.h: interface for the CProbeToProxyMapperSink class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "ServiceTlb.h"

class CProxyProbe;
class CProxyDataPoint;

// Probe event sink for converting probe com events into proxy probe observer events
class CProbeToProxyMapperSink : public IDispEventImpl<0, CProbeToProxyMapperSink, &ox::DIID__IProbeEvents, &ox::LIBID_ox, 1, 0>
{
public:

	CProbeToProxyMapperSink(CProxyProbe* theProbe);
	~CProbeToProxyMapperSink();

// Where we pass 0x01 - is the ID of our event function,
// can be anything, depending on the server implementation.
BEGIN_SINK_MAP(CProbeToProxyMapperSink)
	SINK_ENTRY_EX(0, ox::DIID__IProbeEvents, 0x01, OnPollBegin)
	SINK_ENTRY_EX(0, ox::DIID__IProbeEvents, 0x02, OnPollEnd)
END_SINK_MAP()

	HRESULT __stdcall OnPollBegin();
	HRESULT __stdcall OnPollEnd();

private:
	// The object to be informed of changes
	CProxyProbe* m_Probe;

};
