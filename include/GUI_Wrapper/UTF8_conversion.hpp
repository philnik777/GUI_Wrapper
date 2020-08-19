#pragma once
#include <codecvt>
#include <locale>
#include <string>

namespace GUI::Convert
{
inline std::wstring toWString(std::string c)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	return converter.from_bytes(c);
}

std::string toString(const std::wstring& c);
}
