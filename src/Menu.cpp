#include "GUI_Wrapper/Menu.hpp"

#include "WinAPI/Menu.hpp"
#include "GUI_Wrapper/UTF8_conversion.hpp"

namespace GUI
{
Menu::Menu() : m(UI::Menu::create()) {}

void Menu::addSubMenu(const std::string& name, std::function<void()> cb)
{
	m->addSubMenu(Convert::toWString(name), cb);
}
}