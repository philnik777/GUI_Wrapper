#include "GUI_Wrapper/UTF8_conversion.hpp"

#include <Windows.h>
#include <vector>
#include <iostream>

namespace GUI::Convert
{
std::string toString(const std::wstring& c)
{
	if (c.size() == 0)
		return std::string();
	std::vector<char> buf(WideCharToMultiByte(CP_UTF8, 0, c.data(), c.size(),
											  nullptr, 0, nullptr, nullptr) + 1);
	WideCharToMultiByte(CP_UTF8, 0, c.data(), c.size(), buf.data(), buf.size(),
						nullptr, nullptr);
	return buf.data();
}
}
