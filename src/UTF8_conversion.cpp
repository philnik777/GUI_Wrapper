#include "GUI_Wrapper/UTF8_conversion.hpp"

#include <iostream>
#include <vector>

#ifdef _WIN32
	#include <Windows.h>
#endif

namespace GUI::Convert
{
#ifdef _WIN32
std::string toString(const std::wstring& c)
{
	if (c.size() == 0)
		return std::string();
	std::vector<char> buf(WideCharToMultiByte(CP_UTF8, 0, c.data(), c.size(),
											  nullptr, 0, nullptr, nullptr)
						  + 1);
	WideCharToMultiByte(CP_UTF8, 0, c.data(), c.size(), buf.data(), buf.size(),
						nullptr, nullptr);
	return buf.data();
}
#endif
}
