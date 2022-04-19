#include "StringConverter.h"

namespace Rhine
{
	std::wstring StringConverter::StringToWide(std::string str)
	{
		std::wstring wide_string(str.begin(), str.end());
		return wide_string;
	}
}