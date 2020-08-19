#include "GUI_Wrapper/Text.hpp"

#include "GUI_Wrapper/UTF8_conversion.hpp"
#include "WinAPI/WinAPI_Wrapper.hpp"

namespace GUI
{
Text::Text(const Element& parent,
		   const std::string& text,
		   Point pos,
		   BindPoint p)
{
	element = WinAPI::Text::create(
		parent.getRaw<UI::Window>(), Convert::toWString(text),
		{static_cast<long>(pos.x), static_cast<long>(pos.y)},
		static_cast<WinAPI::BindPoint>(p));
}
}
