#include "StdAfx.h"
#include "HTTPParser.h"
#include <string>

CHTTPParser::CHTTPParser(void)
: m_bIsConnected(false)
, m_hSession(NULL)
{
	openInternet();
}

CHTTPParser::~CHTTPParser(void)
{
	closeInternet();
}

bool CHTTPParser::openInternet(void)
{
	closeInternet();

	m_hSession = InternetOpen(_T("SensatronicsSDK"), PRE_CONFIG_INTERNET_ACCESS, NULL, NULL, 0);

	if(m_hSession != NULL)
		return true;
	else
		return false;
}

void CHTTPParser::closeInternet(void)
{
	if(m_hSession != NULL)
		InternetCloseHandle(m_hSession);

	m_hSession = NULL;
}

bool CHTTPParser::IsInternetAvailable()
{
	if(m_hSession != NULL)
		return true;
	else
		return false;
}

bool CHTTPParser::HTTPGet(LPCTSTR pstrServer, LPCTSTR pstrObjectName, CString& rString)
{
	bool bReturn = false;

	// are we already connected
	bReturn = IsInternetAvailable();

	if(!bReturn)
	{
		// no, then try and connect
		bReturn = openInternet();
	}

	if(bReturn == true)
	{
		HINTERNET hConnect = InternetConnect(m_hSession, pstrServer, 80, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 1);

		if(hConnect != NULL)
		{
			HINTERNET hFile = NULL;
			hFile = HttpOpenRequest(hConnect, _T("GET"), pstrObjectName, HTTP_VERSION, NULL, NULL, INTERNET_FLAG_EXISTING_CONNECT, 1);

			if(hFile != NULL)
			{
				if(HttpSendRequest(hFile, NULL, 0, NULL, 0))
				{
					readString(rString, hFile);
				}
				else
				{
					bReturn = false;
				}

				InternetCloseHandle(hFile);
			}
			else
			{
				bReturn = false;
			}
			InternetCloseHandle(hConnect);
		}
		else
		{
			bReturn = false;
		}
	}

	return bReturn;
}

bool CHTTPParser::readString(CString& rString, HINTERNET hFile)
{
	const DWORD dwBufferSize = 1024;
	DWORD dwRead = 0;
	CHAR svBuffer[dwBufferSize];

	rString = _T("");

	ZeroMemory(svBuffer, dwBufferSize);
	
	while(InternetReadFile(hFile, svBuffer, dwBufferSize, &dwRead) && dwRead != 0)
	{
		CA2T pszBuffer((LPCSTR)svBuffer);
		
		rString.Append(pszBuffer);
	}

	return true;
}