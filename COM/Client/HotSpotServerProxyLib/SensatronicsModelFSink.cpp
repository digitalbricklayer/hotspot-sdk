#include "stdafx.h"
#include "SensatronicsModelFSink.h"
#include "ProxySensatronicsModelF.h"
#include "Subject.h"
#include "Hint.h"
#include "SensorSinkHints.h"

#include <memory>
#include <comutils/combool.h>

CSensatronicsModelFToProxyMapperSink::CSensatronicsModelFToProxyMapperSink(CProxySensatronicsModelF* theSensor)
: m_Sensor(theSensor)
{
}

CSensatronicsModelFToProxyMapperSink::~CSensatronicsModelFToProxyMapperSink()
{
}

HRESULT __stdcall CSensatronicsModelFToProxyMapperSink::OnPollBegin()
{
	std::auto_ptr<CHint> theHint(new CHint(IHint::sensor_poll_begin));
	m_Sensor->Notify(theHint.get());
	return S_OK;
}

HRESULT __stdcall CSensatronicsModelFToProxyMapperSink::OnPollEnd(BSTR StatusCom)
{
	const _bstr_t StatusBstr(StatusCom, false);
	std::wstring Status = StatusBstr;
	std::auto_ptr<CSensorPollEndHint> theHint(new CSensorPollEndHint(Status));
	m_Sensor->Notify(theHint.get());
	return S_OK;
}
