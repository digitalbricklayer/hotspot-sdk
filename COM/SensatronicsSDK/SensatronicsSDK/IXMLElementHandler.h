#pragma once

#include <string>
#include <map>

class CXMLElement
{
public:
	typedef std::map<std::wstring, std::wstring> XMLAttributesContainer;
public:
    CXMLElement()
        : m_bStartElement(true), m_sElementName(_T("")) {}
    ~CXMLElement() {}

    bool IsStartElement() const               { return m_bStartElement; }
    void SetStartElement(bool bStartElement) { m_bStartElement = bStartElement; }

    LPCTSTR GetElementName() const           { return m_sElementName; }
    void SetElementName(LPCTSTR elementName) { m_sElementName = elementName; }

    void AddAttribute(LPCTSTR attributeName, LPCTSTR attributeValue);

    LPCTSTR GetAttributeValue(LPCTSTR attributeName, CString* attributeValue) const;

    const XMLAttributesContainer& GetAttributes() const { return m_attributes; }

private:
    bool m_bStartElement;
    CString m_sElementName;

    XMLAttributesContainer m_attributes;
};

class IXMLElementHandler
{
public:
	virtual void OnXMLStartElement(const CXMLElement& xmlElement) {};
public:
	virtual void OnXMLElementData(LPCTSTR elementData) {};
public:
	virtual void OnXMLEndElement(const CXMLElement& xmlElement) {};
public:    
	virtual void OnXMLError(int line, int column, LPCTSTR errorText, unsigned long errorCode) {};
public:
	virtual bool OnXMLAbortParse(const CXMLElement& xmlElement) { return false; };
};
