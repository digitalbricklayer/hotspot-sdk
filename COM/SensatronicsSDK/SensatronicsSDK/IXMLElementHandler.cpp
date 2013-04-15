#include "StdAfx.h"
#include "IXMLElementHandler.h"

void CXMLElement::AddAttribute(LPCTSTR attributeName, LPCTSTR attributeValue)
{
	std::wstring sAttributeName(attributeName);
	std::wstring sAttributeValue(attributeValue);
    
	if(sAttributeName.length() != 0)
	{
		m_attributes[sAttributeName] = std::wstring(sAttributeValue);
	}
}

LPCTSTR CXMLElement::GetAttributeValue(LPCTSTR attributeName, CString* attributeValue) const
{
	CString sAttributeName(attributeName);

	attributeValue->Format(_T(""));

	if(!sAttributeName.IsEmpty())
	{
		XMLAttributesContainer::const_iterator it = m_attributes.find(attributeName);

		if(it != m_attributes.end())
		{
			attributeValue->Format(_T("%s"), CString(it->second.c_str()));
		}
	}

    return *attributeValue;
}
