#pragma once
#include <Windows.h>
#include "StringConverter.h"

namespace Rhine
{
	class ErrorLogger
	{
	public:
		ErrorLogger();
		~ErrorLogger();

		static void LogError(HRESULT hres, std::wstring msg);
	};
}

