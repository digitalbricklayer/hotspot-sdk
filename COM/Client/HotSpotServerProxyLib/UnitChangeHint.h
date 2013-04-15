#pragma once
#include "Hint.h"
#include <string>

class CUnitChangeHint : public IHint
{
public:
	CUnitChangeHint(const std::wstring& NewName): m_NewName(NewName) { }
	virtual ~CUnitChangeHint(void) { }

	virtual int GetTypeId(void) const { return data_point_unit_change; }

	virtual const std::wstring& GetNewName(void) const { return m_NewName; }

private:
	std::wstring m_NewName;

};
