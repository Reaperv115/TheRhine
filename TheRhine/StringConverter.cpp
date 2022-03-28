#include "StringConverter.h"

std::wstring StringConverter::StringtoWide(std::string str)
{
    std::wstring wideString(str.begin(), str.end());
    return wideString;
}
