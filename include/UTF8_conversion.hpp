#pragma once
#include <string>
#include <codecvt>

namespace GUI::Convert
{
std::wstring toWString(std::string c)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	return converter.from_bytes(c);
}
}