#include "StdAfx.h"
#include "DataPointObserver.h"
#include "UnitChangeHint.h"
#include "Hint.h"

CDataPointObserver::CDataPointObserver(void)
{
}

CDataPointObserver::~CDataPointObserver(void)
{
}

void CDataPointObserver::Update(ISubject* theSubject, IHint* theHint)
{
	// Data points only have one notification type
	ASSERT(theHint->GetTypeId() == IHint::data_point_unit_change);
	CUnitChangeHint* theSpecificHint = static_cast<CUnitChangeHint*>(theHint);
	OnUnitChange(theSubject, theSpecificHint->GetNewName());
}
