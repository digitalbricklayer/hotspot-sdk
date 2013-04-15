// HotSpotUnitTesterGui.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "HotSpotUnitTesterGui.h"

#include <cppunit/ui/mfc/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <initguid.h>
#include "HotSpotServerProxyLibraryUnitTester_i.c"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHotSpotUnitTesterGuiApp

class CHotSpotUnitTesterGuiModule : public CAtlMfcModule
{
public:
	DECLARE_LIBID(LIBID_HotSpotUnitTesterGuiLib);
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_HOTSPOTUNITTESTERGUI, "{B970405C-D6FF-435A-9EA0-FF86D7DB474C}");
};

CHotSpotUnitTesterGuiModule _AtlModule;

BEGIN_MESSAGE_MAP(CHotSpotUnitTesterGuiApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

// CHotSpotUnitTesterGuiApp construction

CHotSpotUnitTesterGuiApp::CHotSpotUnitTesterGuiApp()
{
}

// The one and only CHotSpotUnitTesterGuiApp object

CHotSpotUnitTesterGuiApp theApp;

// CHotSpotUnitTesterGuiApp initialization

BOOL CHotSpotUnitTesterGuiApp::InitInstance()
{
	CWinApp::InitInstance();

	CoInitialize(NULL);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

#if !defined(_WIN32_WCE) || defined(_CE_DCOM)
	// Register class factories via CoRegisterClassObject().
	if (FAILED(_AtlModule.RegisterClassObjects(CLSCTX_LOCAL_SERVER, REGCLS_MULTIPLEUSE)))
		return FALSE;
#endif // !defined(_WIN32_WCE) || defined(_CE_DCOM)
	// App was launched with /Embedding or /Automation switch.
	// Run app as automation server.
	if (cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated)
	{
		// Don't show the main window
		return TRUE;
	}

	// App was launched with /Unregserver or /Unregister switch.
	if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppUnregister)
	{
		_AtlModule.UpdateRegistryAppId(FALSE);
		_AtlModule.UnregisterServer(TRUE);
		return FALSE;
	}
	// App was launched with /Register or /Regserver switch.
	if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppRegister)
	{
		_AtlModule.UpdateRegistryAppId(TRUE);
		_AtlModule.RegisterServer(TRUE);
		return FALSE;
	}

	SetRegistryKey(_T("HotSpotUnitTesterGui"));

	CppUnit::MfcUi::TestRunner runner;

    runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest());

    runner.run();

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CHotSpotUnitTesterGuiApp::ExitInstance()
{
#if !defined(_WIN32_WCE) || defined(_CE_DCOM)
	_AtlModule.RevokeClassObjects();
#endif

	CoUninitialize();

	return CWinApp::ExitInstance();
}
