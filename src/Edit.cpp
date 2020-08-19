#include "GUI_Wrapper/Edit.hpp"

#include "GUI_Wrapper/UTF8_conversion.hpp"
#include "WinAPI/WinAPI_Wrapper.hpp"

namespace GUI
{
Edit::Edit(const Element& parent, const std::string& text, Point pos, Area area)
{
	element = WinAPI::Edit::create(
		parent.getRaw<UI::Window>(), Convert::toWString(text),
		{static_cast<long>(pos.x), static_cast<long>(pos.y),
		 static_cast<long>(area.x), static_cast<long>(area.y)});
}

std::string Edit::getText() {
	return Convert::toString(getRaw<UI::Edit>()->getText());
}
}
