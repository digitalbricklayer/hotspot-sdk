#pragma once

#include "TemperatureConversion.h"
#include <string>
#include <limits>
#include "..\..\Libs\Include\common.h"

#define NO_VALUE_1 -999.99
#define NO_VALUE_2 -99.99


namespace OPENXTRA
{
	namespace Constants
	{
		const CString sEthernetModelTypes(_T("E4 E8 E16 EM1"));
		const CString sSerialModelTypes(_T("ModelF"));
		const CString sUnitTemperatureTypes(_T("CFRK"));
		const CString sUnitOtherTypes(_T("PHW"));
		const CString sProbeValidTypes(_T("Temperature Humidity Wetness Switch"));
		const CString sModelFXMLConfig(_T("<Sensatronics><Unit><Model>ModelF</Model></Unit><Group id=\"1\"><Probe id=\"1\" type=\"Temperature\"><Name>Probe 1</Name><Units>°F</Units></Probe><Probe id=\"2\" type=\"Temperature\"><Name>Probe 2</Name><Units>°F</Units></Probe></Group></Sensatronics>"));
	};

	namespace Maths
	{
		static bool isEqual(double x, double y)
		{
			//const double epsilon = std::numeric_limits<double>::epsilon();
			//const double epsilon = /* some small number such as 1e-5 */;
			const double epsilon = 1e-2;
			return std::abs(x - y) <= epsilon * std::abs(x);
			// see Knuth section 4.2.2 pages 217-218
		}
	};

	namespace Utils
	{
		static void BackupFile(LPCTSTR szFile, int nBackups)
		{
			CString sFilename(szFile);
			CString sBackup(_T(""));

			for(int nCount = nBackups; nCount > 0; nCount--)
			{
				if(nCount == 1)
				{
					sBackup.Format(_T("%s.%.3d"), szFile, nCount);
					sFilename.Format(_T("%s"), szFile);
				}
				else
				{
					sBackup.Format(_T("%s.%.3d"), szFile, nCount);
					sFilename.Format(_T("%s.%.3d"), szFile, nCount - 1);
				}

				ATLASSERT(sFilename.GetLength() <= _MAX_PATH);
				TCHAR svFilename[_MAX_PATH];
				_tcscpy_s(svFilename, sFilename);

				try
				{
					/*if(OpenFile((LPCSTR)&svFilename, NULL, OF_EXIST) != HFILE_ERROR)*/
					{	
						MoveFileEx(sFilename, sBackup, MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH);
					}
				}
				catch(...)
				{
				}
			}
		}
	};

	namespace SensatronicsConvertToXML
	{
		static void ConvertModelEConfigAndData(BSTR Config, CString* psConfigXML, BSTR Data, CString* psDataXML)
		{
			CString sSep(_T("|"));
			CString sTemp(_T(""));
			CComBSTR bstrSerial(L"");

			CString sDataXML(_T(""));
			CString sConfigXML(_T(""));

			{
				CString sData(Data);

				CString sToken(_T(""));
				int curPos= 0;
				int nProbe = 1;

				sToken = sData.Tokenize(sSep, curPos);

				for(; curPos != -1 ;)
				{
					sTemp.Format(_T("<Probe id=\"%d\">"), nProbe);
					sDataXML += sTemp;

					sToken = sData.Tokenize(sSep, curPos);

					sTemp.Format(_T("<Value>%s</Value>"), sToken);
					sDataXML += sTemp;

					sTemp.Format(_T("</Probe>"));
					sDataXML += sTemp;

					sToken = sData.Tokenize(sSep, curPos);
					nProbe ++;
				}

				sDataXML += _T("</Sensatronics>");
			}

			{
				CString sConfig(Config);

				CString sToken(_T(""));
				int curPos= 0;

				bool bHead = true;
				int nHeadCounter = 0;

				sToken = sConfig.Tokenize(sSep, curPos);

				bstrSerial = sToken;

				sConfigXML.Format(_T("<Sensatronics id=\"%s\">"), bstrSerial);

				sToken = sConfig.Tokenize(sSep, curPos);

				for(; curPos != -1 ;)
				{
					if(bHead)
					{
						switch(nHeadCounter)
						{
						case 0:
							sTemp.Format(_T("<Unit>"));
							sConfigXML += sTemp;

							sTemp.Format(_T("<Name>%s</Name>"), sToken);
							sConfigXML += sTemp;
							break;
						case 1:
							sToken.TrimLeft(_T("Model"));
							sToken.TrimLeft();
							sTemp.Format(_T("<Model>%s</Model>"), sToken);
							sConfigXML += sTemp;
							break;							
						default:
							bHead = false;
							sTemp.Format(_T("<Serial_Number>%s</Serial_Number>"), bstrSerial);
							sConfigXML += sTemp;
							sTemp.Format(_T("<Firmware_Release_Date></Firmware_Release_Date>"));
							sConfigXML += sTemp;
							sTemp.Format(_T("<Firmware_Version></Firmware_Version>"));
							sConfigXML += sTemp;
							sTemp.Format(_T("<Website>http://www.sensatronics.com/</Website>"));
							sConfigXML += sTemp;
							sTemp.Format(_T("<Manufacturer>Sensatronics</Manufacturer>"));
							sConfigXML += sTemp;
							sTemp.Format(_T("</Unit>"));
							sConfigXML += sTemp;
							break;
						};
						nHeadCounter++;
					}
					else
					{
						sTemp.Format(_T("<Probe id=\"%s\" type=\"Temperature\">"), sToken);
						sConfigXML += sTemp;

						sToken = sConfig.Tokenize(sSep, curPos);

						sTemp.Format(_T("<Name>%s</Name>"), sToken);
						sConfigXML += sTemp;

						sTemp.Format(_T("<Units>F</Units>"));
						sConfigXML += sTemp;

						sTemp.Format(_T("</Probe>"));
						sConfigXML += sTemp;
					}

					sToken = sConfig.Tokenize(sSep, curPos);
				}

				sConfigXML += _T("</Sensatronics>");
			}

			sTemp.Format(_T("<Sensatronics id=\"%s\">"), bstrSerial);

			sDataXML = sTemp + sDataXML;

			*psDataXML = sDataXML;
			*psConfigXML = sConfigXML;
		};

		static void ConvertEMConfigAndData(BSTR Config, CString* psConfigXML, BSTR Data, CString* psDataXML)
		{
			CString sSep(_T("|"));
			CString sTemp(_T(""));
			CComBSTR bstrTempUnit(L"");
			CComBSTR bstrSerial(L"");

			CString sDataXML(_T(""));
			CString sConfigXML(_T(""));

			{
				CString sData(Data);

				CString sToken(_T(""));
				int curPos= 0;
				int nProbe = 1;
				int nGroup = 1;
				int nGroupCounter = 0;

				sToken = sData.Tokenize(sSep, curPos);

				// this is the first so its the temperature unit
				bstrTempUnit = sToken;

				sToken = sData.Tokenize(sSep, curPos);

				//sDataXML.Format(_T("<Sensatronics id=\"\">"));

				for(; curPos != -1 ;)
				{
					if(nGroupCounter == 0)
					{
						sTemp.Format(_T("<Group id=\"%d\">"), nGroup);
						sDataXML += sTemp;
					}

					sTemp.Format(_T("<Probe id=\"%d\">"), nProbe);
					sDataXML += sTemp;

					sTemp.Format(_T("<Value>%s</Value>"), sToken);
					sDataXML += sTemp;

					sTemp.Format(_T("</Probe>"));
					sDataXML += sTemp;

					sToken = sData.Tokenize(sSep, curPos);
					nProbe ++;

					nGroupCounter ++;

					if(nGroupCounter == 3)
					{
						nGroupCounter = 0;
						nGroup ++;
						sTemp.Format(_T("</Group>"));
						sDataXML += sTemp;
					}
				};

				sDataXML += _T("</Sensatronics>");
			}

			{
				CString sConfig(Config);

				CString sToken(_T(""));
				int curPos= 0;
				int nProbe = 1;

				int nGroupCounter = 0;
				int nGroup = 0;

				bool bHead = true;
				int nHeadCounter = 0;

				CString sUnit(_T(""));

				sToken = sConfig.Tokenize(sSep, curPos);

				bstrSerial = sToken;

				sConfigXML.Format(_T("<Sensatronics id=\"%s\">"), bstrSerial);

				sToken = sConfig.Tokenize(sSep, curPos);

				for(; curPos != -1 ;)
				{
					if(bHead)
					{
						switch(nHeadCounter)
						{
						case 0:
							sTemp.Format(_T("<Unit>"));
							sConfigXML += sTemp;

							sTemp.Format(_T("<Name>%s</Name>"), sToken);
							sConfigXML += sTemp;
							break;
						case 1:
							sToken.TrimLeft(_T("Model"));
							sToken.TrimLeft();
							sTemp.Format(_T("<Model>%s</Model>"), sToken);
							sConfigXML += sTemp;
							break;
						case 2:
							sTemp.Format(_T("<Serial_Number>%s</Serial_Number>"), bstrSerial);
							sConfigXML += sTemp;					
							// dont no what this is					
							break;
						default:
							bHead = false;
							sTemp.Format(_T("<Firmware_Release_Date></Firmware_Release_Date>"));
							sConfigXML += sTemp;
							sTemp.Format(_T("<Firmware_Version>%s</Firmware_Version>"), sToken);
							sConfigXML += sTemp;
							sTemp.Format(_T("<Website>http://www.sensatronics.com/</Website>"));
							sConfigXML += sTemp;
							sTemp.Format(_T("<Manufacturer>Sensatronics</Manufacturer>"));
							sConfigXML += sTemp;
							sTemp.Format(_T("</Unit>"));
							sConfigXML += sTemp;
							break;
						};
						nHeadCounter++;
					}
					else
					{
						if(nGroupCounter == 0)
						{
							sTemp.Format(_T("<Group id=\"%s\">"), sToken);
							sConfigXML += sTemp;

							sToken = sConfig.Tokenize(sSep, curPos);

							sTemp.Format(_T("<Name>%s</Name>"), sToken);
							sConfigXML += sTemp;

							sToken = sConfig.Tokenize(sSep, curPos);
						}

						if(CString(sToken) == L"T")
						{
							sToken = L"Temperature";
							sUnit = bstrTempUnit;
						}
						else if(CString(sToken) == L"H")
						{
							sToken = L"Humidity";
							sUnit = L"H";
						}
						else if(CString(sToken) == L"W")
						{
							sToken = L"Wetness";
							sUnit = L"W";
						}
						else
							sUnit = L"";

						sTemp.Format(_T("<Probe id=\"%d\" type=\"%s\">"), nProbe, sToken);
						sConfigXML += sTemp;

						sToken = sConfig.Tokenize(sSep, curPos);

						sTemp.Format(_T("<Name>%s</Name>"), sToken);
						sConfigXML += sTemp;

						sTemp.Format(_T("<Units>%s</Units>"), sUnit);
						sConfigXML += sTemp;

						sTemp.Format(_T("</Probe>"));
						sConfigXML += sTemp;

						nProbe ++;

						nGroupCounter ++;

						if(nGroupCounter == 3)
						{
							nGroupCounter = 0;
							sTemp.Format(_T("</Group>"));
							sConfigXML += sTemp;
						}
					}

					sToken = sConfig.Tokenize(sSep, curPos);
				}

				sConfigXML += _T("</Sensatronics>");
			}

			sTemp.Format(_T("<Sensatronics id=\"%s\">"), bstrSerial);

			sDataXML = sTemp + sDataXML;

			*psDataXML = sDataXML;
			*psConfigXML = sConfigXML;
		};

		static void ConvertModelFConfigAndData(CString* psConfigXML, CString* psDataXML)
		{
		};
	};

	namespace SensatronicsOids
	{
		namespace ModelE
		{
			// Config
			const CString sSensorNameOid(_T("1.3.6.1.4.1.16174.1.1.1.1.1.0"));
			const CString sSensorModelOid(_T("1.3.6.1.4.1.16174.1.1.1.1.2.0"));
			const CString sSensorSerialNumberOid(_T("1.3.6.1.4.1.16174.1.1.1.1.7.0"));
			const CString sSensorFirmWareVerOid(_T("1.3.6.1.4.1.16174.1.1.1.1.5.0"));
			const CString sSensorFirmWareDateOid(_T("1.3.6.1.4.1.16174.1.1.1.1.6.0"));
			const CString sSensorNetmaskOid(_T("1.3.6.1.4.1.16174.1.1.1.2.1.3.0"));
			const CString sSensorGatewayOid(_T("1.3.6.1.4.1.16174.1.1.1.2.1.4.0"));
			const CString sSensorTemperatureUnitOid(_T("1.3.6.1.4.1.16174.1.1.1.2.3.1.0"));
			const CString sSensorIpAddressOid(_T("1.3.6.1.4.1.16174.1.1.1.2.1.2.0"));

			// Probes
			const CString sProbe1Value(_T("1.3.6.1.4.1.16174.1.1.1.3.1.2.0"));
			const CString sProbe1Name(_T("1.3.6.1.4.1.16174.1.1.1.3.1.1.0"));
			const CString sProbe2Value(_T("1.3.6.1.4.1.16174.1.1.1.3.2.2.0"));
			const CString sProbe2Name(_T("1.3.6.1.4.1.16174.1.1.1.3.2.1.0"));
			const CString sProbe3Value(_T("1.3.6.1.4.1.16174.1.1.1.3.3.2.0"));
			const CString sProbe3Name(_T("1.3.6.1.4.1.16174.1.1.1.3.3.1.0"));
			const CString sProbe4Value(_T("1.3.6.1.4.1.16174.1.1.1.3.4.2.0"));
			const CString sProbe4Name(_T("1.3.6.1.4.1.16174.1.1.1.3.4.1.0"));
			const CString sProbe5Value(_T("1.3.6.1.4.1.16174.1.1.1.3.5.2.0"));
			const CString sProbe5Name(_T("1.3.6.1.4.1.16174.1.1.1.3.5.1.0"));
			const CString sProbe6Value(_T("1.3.6.1.4.1.16174.1.1.1.3.6.2.0"));
			const CString sProbe6Name(_T("1.3.6.1.4.1.16174.1.1.1.3.6.1.0"));
			const CString sProbe7Value(_T("1.3.6.1.4.1.16174.1.1.1.3.7.2.0"));
			const CString sProbe7Name(_T("1.3.6.1.4.1.16174.1.1.1.3.7.1.0"));
			const CString sProbe8Value(_T("1.3.6.1.4.1.16174.1.1.1.3.8.2.0"));
			const CString sProbe8Name(_T("1.3.6.1.4.1.16174.1.1.1.3.8.1.0"));
			const CString sProbe9Value(_T("1.3.6.1.4.1.16174.1.1.1.3.9.2.0"));
			const CString sProbe9Name(_T("1.3.6.1.4.1.16174.1.1.1.3.9.1.0"));
			const CString sProbe10Value(_T("1.3.6.1.4.1.16174.1.1.1.3.10.2.0"));
			const CString sProbe10Name(_T("1.3.6.1.4.1.16174.1.1.1.3.10.1.0"));
			const CString sProbe11Value(_T("1.3.6.1.4.1.16174.1.1.1.3.11.2.0"));
			const CString sProbe11Name(_T("1.3.6.1.4.1.16174.1.1.1.3.11.1.0"));
			const CString sProbe12Value(_T("1.3.6.1.4.1.16174.1.1.1.3.12.2.0"));
			const CString sProbe12Name(_T("1.3.6.1.4.1.16174.1.1.1.3.12.1.0"));
			const CString sProbe13Value(_T("1.3.6.1.4.1.16174.1.1.1.3.13.2.0"));
			const CString sProbe13Name(_T("1.3.6.1.4.1.16174.1.1.1.3.13.1.0"));
			const CString sProbe14Value(_T("1.3.6.1.4.1.16174.1.1.1.3.14.2.0"));
			const CString sProbe14Name(_T("1.3.6.1.4.1.16174.1.1.1.3.14.1.0"));
			const CString sProbe15Value(_T("1.3.6.1.4.1.16174.1.1.1.3.15.2.0"));
			const CString sProbe15Name(_T("1.3.6.1.4.1.16174.1.1.1.3.15.1.0"));
			const CString sProbe16Value(_T("1.3.6.1.4.1.16174.1.1.1.3.16.2.0"));
			const CString sProbe16Name(_T("1.3.6.1.4.1.16174.1.1.1.3.16.1.0"));
		};

		namespace EM1
		{
			// Config
			const CString sSensorNameOid(_T("1.3.6.1.4.1.16174.1.1.3.1.1.0"));
			const CString sSensorModelOid(_T("1.3.6.1.4.1.16174.1.1.3.1.2.0"));
			const CString sSensorSerialNumberOid(_T("1.3.6.1.4.1.16174.1.1.3.1.7.0"));
			const CString sSensorFirmWareVerOid(_T("1.3.6.1.4.1.16174.1.1.3.1.5.0"));
			const CString sSensorFirmWareDateOid(_T("1.3.6.1.4.1.16174.1.1.3.1.6.0"));
			const CString sSensorNetmaskOid(_T("1.3.6.1.4.1.16174.1.1.3.2.1.3.0"));
			const CString sSensorGatewayOid(_T("1.3.6.1.4.1.16174.1.1.3.2.1.4.0"));
			const CString sSensorTemperatureUnitOid(_T("1.3.6.1.4.1.16174.1.1.3.2.3.1.0"));
			const CString sSensorIpAddressOid(_T("1.3.6.1.4.1.16174.1.1.3.2.1.2.0"));

			// Probes
			const CString sProbe1Value(_T("1.3.6.1.4.1.16174.1.1.3.3.1.3.0"));
			const CString sProbe1Name(_T("1.3.6.1.4.1.16174.1.1.3.3.1.2.0"));
			const CString sProbe2Value(_T("1.3.6.1.4.1.16174.1.1.3.3.1.6.0"));
			const CString sProbe2Name(_T("1.3.6.1.4.1.16174.1.1.3.3.1.5.0"));
			const CString sProbe3Value(_T("1.3.6.1.4.1.16174.1.1.3.3.1.9.0"));
			const CString sProbe3Name(_T("1.3.6.1.4.1.16174.1.1.3.3.1.8.0"));
			const CString sProbe4Value(_T("1.3.6.1.4.1.16174.1.1.3.3.2.3.0"));
			const CString sProbe4Name(_T("1.3.6.1.4.1.16174.1.1.3.3.2.2.0"));
			const CString sProbe5Value(_T("1.3.6.1.4.1.16174.1.1.3.3.2.6.0"));
			const CString sProbe5Name(_T("1.3.6.1.4.1.16174.1.1.3.3.2.5.0"));
			const CString sProbe6Value(_T("1.3.6.1.4.1.16174.1.1.3.3.2.9.0"));
			const CString sProbe6Name(_T("1.3.6.1.4.1.16174.1.1.3.3.2.8.0"));
			const CString sProbe7Value(_T("1.3.6.1.4.1.16174.1.1.3.3.3.3.0"));
			const CString sProbe7Name(_T("1.3.6.1.4.1.16174.1.1.3.3.3.2.0"));
			const CString sProbe8Value(_T("1.3.6.1.4.1.16174.1.1.3.3.3.6.0"));
			const CString sProbe8Name(_T("1.3.6.1.4.1.16174.1.1.3.3.3.5.0"));
			const CString sProbe9Value(_T("1.3.6.1.4.1.16174.1.1.3.3.3.9.0"));
			const CString sProbe9Name(_T("1.3.6.1.4.1.16174.1.1.3.3.3.8.0"));
			const CString sProbe10Value(_T("1.3.6.1.4.1.16174.1.1.3.3.4.3.0"));
			const CString sProbe10Name(_T("1.3.6.1.4.1.16174.1.1.3.3.4.2.0"));
			const CString sProbe11Value(_T("1.3.6.1.4.1.16174.1.1.3.3.4.6.0"));
			const CString sProbe11Name(_T("1.3.6.1.4.1.16174.1.1.3.3.4.5.0"));
			const CString sProbe12Value(_T("1.3.6.1.4.1.16174.1.1.3.3.4.9.0"));
			const CString sProbe12Name(_T("1.3.6.1.4.1.16174.1.1.3.3.4.8.0"));

			const CString sGroup1Name(_T("1.3.6.1.4.1.16174.1.1.3.3.1.1.0"));
			const CString sGroup2Name(_T("1.3.6.1.4.1.16174.1.1.3.3.2.1.0"));
			const CString sGroup3Name(_T("1.3.6.1.4.1.16174.1.1.3.3.3.1.0"));
			const CString sGroup4Name(_T("1.3.6.1.4.1.16174.1.1.3.3.4.1.0"));
		};
	};
	
};	// OPENXTRA