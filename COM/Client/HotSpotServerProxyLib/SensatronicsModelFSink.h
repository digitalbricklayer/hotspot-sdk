// ProbeSink.h: interface for the CProbeToProxyMapperSink class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "ServiceTlb.h"

class CProxySensatronicsModelF;
class CProxyProbe;

// Probe event sink for converting probe com events into proxy probe observer events
class CSensatronicsModelFToProxyMapperSink : public IDispEventImpl<0, CSensatronicsModelFToProxyMapperSink, &ox::DIID__ISensatronicsModelFEvents, &ox::LIBID_ox, 1, 0>
{
public:

	CSensatronicsModelFToProxyMapperSink(CProxySensatronicsModelF* theSensor);
	~CSensatronicsModelFToProxyMapperSink();

// Where we pass 0x01 - is the ID of our event function,
// can be anything, depending on the server implementation.
BEGIN_SINK_MAP(CSensatronicsModelFToProxyMapperSink)
	SINK_ENTRY_EX(0, ox::DIID__ISensatronicsModelFEvents, 0x01, OnPollBegin)
	SINK_ENTRY_EX(0, ox::DIID__ISensatronicsModelFEvents, 0x02, OnPollEnd)
END_SINK_MAP()

	HRESULT __stdcall OnPollBegin();
	HRESULT __stdcall OnPollEnd(BSTR Status);

private:
	// Notify the sensor of a new probe
	void NotifyProbeAdd(CProxyProbe* NewProbe);

	// The object to be informed of changes
	CProxySensatronicsModelF* m_Sensor;

};
