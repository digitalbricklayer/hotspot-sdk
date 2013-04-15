#pragma once

#include "SAXContentHandlerImpl.h"
#include "SAXErrorHandlerImpl.h"
#include "IXMLElementHandler.h"

#include <string>

class CXMLParser
{
public:
	CXMLParser(IXMLElementHandler* pElementHandler);
public:
	~CXMLParser(void);
private:
	ISAXXMLReader* m_pSAXXMLReader;
private:
	HRESULT CreateSAXXMLReader(void);
private:
	SAXContentHandlerImpl* m_pSAXContentHandlerImpl;
private:
	SAXErrorHandlerImpl* m_pSAXErrorHandlerImpl;
public:
	HRESULT Parse(const wchar_t* pXMLPath);
public:
	HRESULT Parse(const VARIANT varInput);
};
