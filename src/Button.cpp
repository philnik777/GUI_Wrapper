#include "GUI_Wrapper/Button.hpp"

#include "GUI_Wrapper/UTF8_conversion.hpp"
#include "GUI_Wrapper/Window.hpp"

#ifdef _WIN32
	#include "WinAPI/Button.hpp"
#elif defined(linux)
	#include "GTK_Wrapper/Button.hpp"
#endif

namespace GUI
{
Button::Button(const Element& parent, const std::string& name, Point pos)
{
	using CastType = decltype(UI::Point::x);
	setRaw(UI::Button::create(
		parent.getRaw<UI::Element>(), Convert::toSystemString(name),
		{static_cast<CastType>(pos.x), static_cast<CastType>(pos.y)}));
}

void Button::setOnClick(std::function<void()> fun)
{
	getRaw<UI::Button>()->setOnClick(fun);
}
}
