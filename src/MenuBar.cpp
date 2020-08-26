#include "GUI_Wrapper/MenuBar.hpp"

#include "GUI_Wrapper/Menu.hpp"
#include "GUI_Wrapper/UTF8_conversion.hpp"

#ifdef _WIN32
	#include "WinAPI/MenuBar.hpp"
#elif defined(linux)
	#include "GTK_Wrapper/MenuBar.hpp"
#endif

namespace GUI
{
USING_UI_NAMESPACE;
MenuBar::MenuBar() : mb(UI::MenuBar::create()) {}

void MenuBar::addMenu(const std::string& name, const GUI::Menu& menu)
{
	mb->addMenu(Convert::toSystemString(name), menu.getRaw());
}
}
