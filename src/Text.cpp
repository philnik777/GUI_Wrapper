#include "GUI_Wrapper/Text.hpp"

#include "GUI_Wrapper/UTF8_conversion.hpp"

#ifdef _WIN32
	#include "WinAPI/WinAPI_Wrapper.hpp"
	#define WIN_CONVERT Convert::toWstring
#elif defined(linux)
	#include "GTK_Wrapper/Text.hpp"
	#define WIN_CONVERT
#endif

namespace GUI
{
Text::Text(const Element& parent,
		   const std::string& text,
		   Point pos,
		   BindPoint p)
{
	using CastType = decltype(Point::x);
	setRaw(std::dynamic_pointer_cast<UI::Element>(UI::Text::create(
		parent.getRaw<UI::Element>(), WIN_CONVERT(text),
		{static_cast<CastType>(pos.x), static_cast<CastType>(pos.y)},
		static_cast<UI::BindPoint>(p))));
}
}
