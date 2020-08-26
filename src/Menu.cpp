#include "GUI_Wrapper/Menu.hpp"

#include "GUI_Wrapper/UTF8_conversion.hpp"

#ifdef _WIN32
	#include "WinAPI/Menu.hpp"
#elif defined(linux)
	#include "GTK_Wrapper/Menu.hpp"
#endif

namespace GUI
{
USING_UI_NAMESPACE;
Menu::Menu() : m(UI::Menu::create()) {}

void Menu::addSubMenu(const std::string& name, std::function<void()> cb)
{
	m->addSubMenu(Convert::toSystemString(name), cb);
}
}
