#pragma once
#include <string>

namespace Rhine
{
	class StringConverter
	{
	public:
		static std::wstring StringToWide(std::string str);
	};
}

