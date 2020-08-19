#include "GUI_Wrapper/MenuBar.hpp"

#include "WinAPI/MenuBar.hpp"

#include "GUI_Wrapper/UTF8_conversion.hpp"
#include "GUI_Wrapper/Menu.hpp"

namespace GUI
{
MenuBar::MenuBar() : mb(WinAPI::MenuBar::create()) {}

void MenuBar::addMenu(const std::string& name, const GUI::Menu& menu) {
	mb->addMenu(Convert::toWString(name), menu.getRaw());
}
}