#include "GUI_Wrapper/Button.hpp"

#include "GUI_Wrapper/UTF8_conversion.hpp"
#include "GUI_Wrapper/Window.hpp"
#include "WinAPI/Button.hpp"

namespace GUI
{
Button::Button(const Element& parent, const std::string& name, Point pos)
{
	element = UI::Button::create(
		parent.getRaw<UI::Window>(), Convert::toWString(name),
		{static_cast<long>(pos.x), static_cast<long>(pos.y)});
}

void Button::setOnClick(std::function<void()> fun)
{
	getRaw<UI::Button>()->setOnClick(fun);
}
}
