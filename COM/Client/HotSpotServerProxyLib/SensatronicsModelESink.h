// ProbeSink.h: interface for the CProbeToProxyMapperSink class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "ServiceTlb.h"

class CProxySensatronicsModelE;
class CProxyProbe;

// Probe event sink for converting probe com events into proxy probe observer events
class CSensatronicsModelEToProxyMapperSink : public IDispEventImpl<0, CSensatronicsModelEToProxyMapperSink, &ox::DIID__ISensatronicsModelEEvents, &ox::LIBID_ox, 1, 0>
{
public:

	CSensatronicsModelEToProxyMapperSink(CProxySensatronicsModelE* theSensor);
	~CSensatronicsModelEToProxyMapperSink();

// Where we pass 0x01 - is the ID of our event function,
// can be anything, depending on the server implementation.
BEGIN_SINK_MAP(CSensatronicsModelEToProxyMapperSink)
	SINK_ENTRY_EX(0, ox::DIID__ISensatronicsModelEEvents, 0x01, OnPollBegin)
	SINK_ENTRY_EX(0, ox::DIID__ISensatronicsModelEEvents, 0x02, OnPollEnd)
END_SINK_MAP()

	HRESULT __stdcall OnPollBegin();
	HRESULT __stdcall OnPollEnd(BSTR Status);

private:
	// Notify the sensor of a new probe
	void NotifyProbeAdd(CProxyProbe* NewProbe);

	// The object to be informed of changes
	CProxySensatronicsModelE* m_Sensor;

};
