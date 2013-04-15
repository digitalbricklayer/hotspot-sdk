#pragma once

class CHTTPParser
{
public:
	CHTTPParser(void);
public:
	~CHTTPParser(void);
public:
	bool HTTPGet(LPCTSTR pstrServer, LPCTSTR pstrObjectName, CString& rString);
public:
	bool IsInternetAvailable();
protected:
	bool openInternet(void);
protected:
	void closeInternet(void);
protected:
	bool readString(CString& rString, HINTERNET hFile);
private:
	bool m_bIsConnected;
	HINTERNET m_hSession;
};
