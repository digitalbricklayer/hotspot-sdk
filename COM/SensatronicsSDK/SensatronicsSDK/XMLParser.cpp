#include "StdAfx.h"
#include "XMLParser.h"

CXMLParser::CXMLParser(IXMLElementHandler* pElementHandler)
: m_pSAXXMLReader(NULL)
, m_pSAXContentHandlerImpl(NULL)
, m_pSAXErrorHandlerImpl(NULL)
{
	// Initialize COM.
    CoInitialize(NULL);

	m_pSAXContentHandlerImpl = new SAXContentHandlerImpl;

	if(pElementHandler != NULL)
		m_pSAXContentHandlerImpl->m_pElementHandler = pElementHandler;
	
	m_pSAXErrorHandlerImpl = new SAXErrorHandlerImpl;

	CreateSAXXMLReader();
}

CXMLParser::~CXMLParser(void)
{
	if ( m_pSAXXMLReader != NULL )
	{
		m_pSAXXMLReader->Release();
		m_pSAXXMLReader = NULL;
	}

	if(m_pSAXContentHandlerImpl)
		delete m_pSAXContentHandlerImpl;
    m_pSAXContentHandlerImpl = NULL;

	if(m_pSAXErrorHandlerImpl)
		delete m_pSAXErrorHandlerImpl;
    m_pSAXErrorHandlerImpl = NULL;

	// Shutdown COM.
	CoUninitialize();
}

HRESULT CXMLParser::CreateSAXXMLReader(void)
{
	HRESULT hr = CoCreateInstance(
                    __uuidof(SAXXMLReader), 
                    NULL, 
                    CLSCTX_ALL, 
                    __uuidof(ISAXXMLReader), 
                    (void **)&m_pSAXXMLReader);

	if(!FAILED(hr))
	{
		if(m_pSAXContentHandlerImpl)
			hr = m_pSAXXMLReader->putContentHandler(m_pSAXContentHandlerImpl);

		if(m_pSAXErrorHandlerImpl)
			hr = m_pSAXXMLReader->putErrorHandler(m_pSAXErrorHandlerImpl);
	}

	return hr;
}

HRESULT CXMLParser::Parse(const wchar_t* pXMLPath)
{
	HRESULT hr = m_pSAXXMLReader->parseURL(pXMLPath);
	return hr;
}

HRESULT CXMLParser::Parse(const VARIANT varInput)
{
	HRESULT hr = m_pSAXXMLReader->parse(varInput);
	return hr;
}
