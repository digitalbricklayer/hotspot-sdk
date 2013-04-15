#include "stdafx.h"

#include "DataPointSink.h"
#include "Subject.h"
#include "UnitChangeHint.h"

#include <memory>
#include <string>

CDataPointToProxyMapperSink::CDataPointToProxyMapperSink(ISubject* theSubject)
: m_Subject(theSubject)
{
}

CDataPointToProxyMapperSink::~CDataPointToProxyMapperSink()
{
}

HRESULT __stdcall CDataPointToProxyMapperSink::OnUnitChange(BSTR NewUnit)
{
	const _bstr_t NewUnitBstr(NewUnit, false);

	const std::wstring NewUnitName = NewUnitBstr;

	std::auto_ptr<CUnitChangeHint> theHint(new CUnitChangeHint(NewUnitName));
	m_Subject->Notify(theHint.get());
	return S_OK;
}
