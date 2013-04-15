// _ClientTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#import "..\SensatronicsSDK\Debug\SensatronicsSDK.tlb"
using namespace SensatronicsSDKLib;

int _tmain(int argc, _TCHAR* argv[])
{
	CoInitialize(NULL);

	try
	{
		ISensatronicsModelEPtr spSensatronicsModelE(__uuidof(SensatronicsModelE));

		spSensatronicsModelE->PutModel(L"E8");
		spSensatronicsModelE->PutIpAddress(L"10.0.0.105");
		spSensatronicsModelE->PutSnmpReadCommunityString(L"public");

		spSensatronicsModelE->Poll();

		_bstr_t bstrIpAddress = spSensatronicsModelE->GetIpAddress();
		_bstr_t bstrName = spSensatronicsModelE->GetName();

		std::cout << "Sensor " << static_cast<const char*>(bstrName) << "(" << static_cast<const char*>(bstrIpAddress) << ") has the following Probe Reading";

		/*IProbeCollectionPtr spProbeCollection = spSensatronicsModelE->GetProbeCollection();

		VARIANT Index;		
		
		for(LONG Count = 1; Count <= spProbeCollection->GetCount(); Count++)
		{
			Index.lVal = Count;
			Index.vt = VT_I4;
			IProbePtr spProbe = static_cast<IProbePtr>(spProbeCollection->Item(Index));
			

			std::cout << "\nProbe (" << spProbe->GetNumber() << ") " << static_cast<const char*>(spProbe->GetName()) << " currently reads " << spProbe->GetMostRecentDataPoint()->GetValue().dblVal << static_cast<const char*>(spProbe->GetMostRecentDataPoint()->GetUnit());
		}*/

		/*ISensatronicsModelFPtr spSensatronicsModelF(__uuidof(SensatronicsModelF));

		spSensatronicsModelF->PutComPort(L"1");

		spSensatronicsModelF->Poll();*/
	}
	catch (const _com_error& Err)
	{
		std::cout << "\nError: " << Err.ErrorMessage() << "\n";
	}
	catch (...)
	{
		std::cout << "Unexpected Error\n";
	}

	CoUninitialize();
	return 0;
}

