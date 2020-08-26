#pragma once
#include <codecvt>
#include <locale>
#include <string>

namespace GUI::Convert
{
#ifdef _WIN32
inline std::wstring toSystemString(std::string c)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	return converter.from_bytes(c);
}

std::string toUserString(const std::wstring& c);
#elif defined(linux)
inline std::string toSystemString(const std::string& s)
{
	return s;
}

inline std::string toUserString(const std::string& s)
{
	return s;
}
#endif
}
