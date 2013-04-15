#pragma once

namespace OPENXTRA
{
	namespace Temperature_Conversion
	{	
		static double Kelvin2Celsius(const double nKelvin)
		{
			double dReturn = 0;

			dReturn = nKelvin - 273.15;

			//ATLTRACE2(L"K2C %lf\n", dReturn);

			return dReturn;
		};

		static double Kelvin2Fahrenheit(const double nKelvin)
		{
			double dReturn = 0;
			
			dReturn = 1.8 * (nKelvin -273.15) + 32;

			//ATLTRACE2(L"K2F %lf\n", dReturn);

			return dReturn;
		};

		static double Kelvin2Rankine(const double nKelvin)
		{
			double dReturn = 0;

			dReturn = 1.8 * nKelvin;

			//ATLTRACE2(L"K2R %lf\n", dReturn);

			return dReturn;
		};

		static double Rankine2Kelvin(const double nRankine)
		{
			double dReturn = 0;

			dReturn = nRankine / 1.8;

			//ATLTRACE2(L"R2K %lf\n", dReturn);

			return dReturn;
		};

		static double Rankine2Celsius(const double nRankine)
		{
			double dReturn = 0;

			dReturn = Kelvin2Celsius(Rankine2Kelvin(nRankine));

			//ATLTRACE2(L"R2C %lf\n", dReturn);

			return dReturn;
		};

		static double Rankine2Fahrenheit(const double nRankine)
		{
			double dReturn = 0;

			dReturn = Kelvin2Fahrenheit(Rankine2Kelvin(nRankine));

			//ATLTRACE2(L"R2F %lf\n", dReturn);

			return dReturn;
		};

		static double Celsius2Kelvin(const double nCelsius)
		{
			double dReturn = 0;

			dReturn = nCelsius + 273.15;

			//ATLTRACE2(L"C2K %lf\n", dReturn);

			return dReturn;
		};

		static double Celsius2Fahrenheit(const double nCelsius)
		{
			double dReturn = 0;

			dReturn = Kelvin2Fahrenheit(Celsius2Kelvin(nCelsius));

			//ATLTRACE2(L"C2F %lf\n", dReturn);

			return dReturn;
		};

		static double Celsius2Rankine(const double nCelsius)
		{
			double dReturn = 0;

			dReturn = Kelvin2Rankine(Celsius2Kelvin(nCelsius));

			//ATLTRACE2(L"C2R %lf\n", dReturn);

			return dReturn;
		};

		static double Fahrenheit2Kelvin(const double nFahrenheit)
		{
			double dReturn = 0;

			dReturn = ((nFahrenheit - 32)/ 1.8) + 273.15;

			//ATLTRACE2(L"F2K %lf\n", dReturn);

			return dReturn;
		};

		static double Fahrenheit2Celsius(const double nFahrenheit)
		{
			double dReturn = 0;

			dReturn = Kelvin2Celsius(Fahrenheit2Kelvin(nFahrenheit));

			//ATLTRACE2(L"F2C %lf\n", dReturn);

			return dReturn;
		};

		static double Fahrenheit2Rankine(const double nFahrenheit)
		{
			double dReturn = 0;

			dReturn = Kelvin2Rankine(Fahrenheit2Kelvin(nFahrenheit));

			//ATLTRACE2(L"F2R %lf\n", dReturn);

			return dReturn;
		};

		static HRESULT ConvertTemperature(const VARIANT varCurrent, const BSTR curUnit, const BSTR targetUnit, VARIANT* varTarget)
		{
			if(varCurrent.vt != VT_R8)
				return E_INVALIDARG;

			/*if(!varTarget)
				return E_INVALIDARG;*/

			VariantClear(varTarget);
			VariantInit(varTarget);
			CComBSTR bstrCurrent(curUnit);
			CComBSTR bstrTarget(targetUnit);
			double dReturned = 0.0;

			//ATLTRACE2(L"ConvertTemperature Current = %ls Target = %ls\n", bstrCurrent, bstrTarget);

			if(bstrCurrent == L"C")
			{
				if(bstrTarget == L"F")
				{
					dReturned = Celsius2Fahrenheit(varCurrent.dblVal);
				}
				else if(bstrTarget == L"R")
				{
					dReturned = Celsius2Rankine(varCurrent.dblVal);
				}
				else if(bstrTarget == L"K")
				{
					dReturned = Celsius2Kelvin(varCurrent.dblVal);
				}
				else
				{
					ATLTRACE2(L"FAIL\n");
					return E_INVALIDARG;
				}
			}
			else if(bstrCurrent == L"F")
			{
				if(bstrTarget == L"C")
				{
					dReturned = Fahrenheit2Celsius(varCurrent.dblVal);
				}
				else if(bstrTarget == L"R")
				{
					dReturned = Fahrenheit2Rankine(varCurrent.dblVal);
				}
				else if(bstrTarget == L"K")
				{
					dReturned = Fahrenheit2Kelvin(varCurrent.dblVal);
				}
				else
				{
					ATLTRACE2(L"FAIL\n");
					return E_INVALIDARG;
				}
			}
			else if(bstrCurrent == L"R")
			{
				if(bstrTarget == L"F")
				{
					dReturned = Rankine2Fahrenheit(varCurrent.dblVal);
				}
				else if(bstrTarget == L"C")
				{
					dReturned = Rankine2Celsius(varCurrent.dblVal);
				}
				else if(bstrTarget == L"K")
				{
					dReturned = Rankine2Kelvin(varCurrent.dblVal);
				}
				else
				{
					ATLTRACE2(L"FAIL\n");
					return E_INVALIDARG;
				}
			}
			else if(bstrCurrent == L"K")
			{
				if(bstrTarget == L"F")
				{
					dReturned = Kelvin2Fahrenheit(varCurrent.dblVal);
				}
				else if(bstrTarget == L"R")
				{
					dReturned = Kelvin2Rankine(varCurrent.dblVal);
				}
				else if(bstrTarget == L"C")
				{
					dReturned = Kelvin2Celsius(varCurrent.dblVal);
				}
				else
				{
					ATLTRACE2(L"FAIL\n");
					return E_INVALIDARG;
				}
			}
			else
			{
				ATLTRACE2(L"FAIL\n");
				return S_OK;
			}

			varTarget->vt = VT_R8;
			varTarget->dblVal = dReturned;

			return S_OK;
		};

	};	// TemperatureConversion
};		// OPENXTRA