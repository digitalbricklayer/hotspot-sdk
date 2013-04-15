// SAXContentHandlerImpl.cpp: implementation of the SAXContentHandlerImpl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SAXContentHandlerImpl.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


SAXContentHandlerImpl::SAXContentHandlerImpl()
: m_pElementHandler(NULL)
{
}

SAXContentHandlerImpl::~SAXContentHandlerImpl()
{
}



HRESULT STDMETHODCALLTYPE SAXContentHandlerImpl::putDocumentLocator( 
            /* [in] */ ISAXLocator __RPC_FAR *pLocator
            )
{
    return S_OK;
}
        
HRESULT STDMETHODCALLTYPE SAXContentHandlerImpl::startDocument()
{
    return S_OK;
}
        

        
HRESULT STDMETHODCALLTYPE SAXContentHandlerImpl::endDocument( void)
{
    return S_OK;
}
        
        
HRESULT STDMETHODCALLTYPE SAXContentHandlerImpl::startPrefixMapping( 
            /* [in] */ const wchar_t __RPC_FAR *pwchPrefix,
            /* [in] */ int cchPrefix,
            /* [in] */ const wchar_t __RPC_FAR *pwchUri,
            /* [in] */ int cchUri)
{
    return S_OK;
}
        
        
HRESULT STDMETHODCALLTYPE SAXContentHandlerImpl::endPrefixMapping( 
            /* [in] */ const wchar_t __RPC_FAR *pwchPrefix,
            /* [in] */ int cchPrefix)
{
    return S_OK;
}
        

        
HRESULT STDMETHODCALLTYPE SAXContentHandlerImpl::startElement( 
            /* [in] */ const wchar_t __RPC_FAR *pwchNamespaceUri,
            /* [in] */ int cchNamespaceUri,
            /* [in] */ const wchar_t __RPC_FAR *pwchLocalName,
            /* [in] */ int cchLocalName,
            /* [in] */ const wchar_t __RPC_FAR *pwchRawName,
            /* [in] */ int cchRawName,
            /* [in] */ ISAXAttributes __RPC_FAR *pAttributes)
{
	CString elementName(pwchLocalName, cchLocalName);

	CXMLElement xmlElement;

	xmlElement.SetElementName(elementName);

	int l = 0;
    // Add attributes to the start element.
    pAttributes->getLength(&l);
    for (int i = 0; i < l; ++i)
    {
        wchar_t* ln = NULL;
        wchar_t* vl = NULL;
        int lnl = 0, vll = 0;
        
        pAttributes->getLocalName(i, (const wchar_t**)&ln, &lnl);
		CString attributeName(ln, lnl);

        pAttributes->getValue(i, (const wchar_t**)&vl, &vll);
		CString attributeValue(vl, vll);

		xmlElement.AddAttribute(attributeName, attributeValue);
    }

	if(m_pElementHandler != NULL)
	{
		m_pElementHandler->OnXMLStartElement(xmlElement);
	}

    return S_OK;
}
        
       
HRESULT STDMETHODCALLTYPE SAXContentHandlerImpl::endElement( 
            /* [in] */ const wchar_t __RPC_FAR *pwchNamespaceUri,
            /* [in] */ int cchNamespaceUri,
            /* [in] */ const wchar_t __RPC_FAR *pwchLocalName,
            /* [in] */ int cchLocalName,
            /* [in] */ const wchar_t __RPC_FAR *pwchRawName,
            /* [in] */ int cchRawName)
{
	CString elementName(pwchLocalName, cchLocalName);

	CXMLElement xmlElement;

	xmlElement.SetElementName(elementName);

	if(m_pElementHandler != NULL)
	{
		m_pElementHandler->OnXMLEndElement(xmlElement);
	}

    return S_OK;
}
        
HRESULT STDMETHODCALLTYPE SAXContentHandlerImpl::characters( 
            /* [in] */ const wchar_t __RPC_FAR *pwchChars,
            /* [in] */ int cchChars)
{
	CString characters(pwchChars, cchChars);
	characters.TrimRight();

	if(!characters.IsEmpty())
	{
		if(m_pElementHandler != NULL)
		{
			m_pElementHandler->OnXMLElementData(characters);
		}
	}

    return S_OK;
}
        

HRESULT STDMETHODCALLTYPE SAXContentHandlerImpl::ignorableWhitespace( 
            /* [in] */ const wchar_t __RPC_FAR *pwchChars,
            /* [in] */ int cchChars)
{
    return S_OK;
}
        

HRESULT STDMETHODCALLTYPE SAXContentHandlerImpl::processingInstruction( 
            /* [in] */ const wchar_t __RPC_FAR *pwchTarget,
            /* [in] */ int cchTarget,
            /* [in] */ const wchar_t __RPC_FAR *pwchData,
            /* [in] */ int cchData)
{
    return S_OK;
}
        
        
HRESULT STDMETHODCALLTYPE SAXContentHandlerImpl::skippedEntity( 
            /* [in] */ const wchar_t __RPC_FAR *pwchVal,
            /* [in] */ int cchVal)
{
    return S_OK;
}


long __stdcall SAXContentHandlerImpl::QueryInterface(const struct _GUID &riid,void ** ppvObject)
{
    return 0;
}

unsigned long __stdcall SAXContentHandlerImpl::AddRef()
{
    return 0;
}

unsigned long __stdcall SAXContentHandlerImpl::Release()
{
    return 0;
}