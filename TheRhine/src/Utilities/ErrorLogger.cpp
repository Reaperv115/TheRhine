#include "ErrorLogger.h"
namespace Rhine
{
	ErrorLogger::ErrorLogger()
	{

	}
	ErrorLogger::~ErrorLogger()
	{

	}
	void Rhine::ErrorLogger::LogError(HRESULT hres, std::wstring msg)
	{
		std::wstring errormsg = L"Error: " + msg;
		MessageBoxW(NULL, errormsg.c_str(), L"Error", MB_ICONERROR);
	}
}
