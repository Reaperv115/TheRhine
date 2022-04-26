#pragma once

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

