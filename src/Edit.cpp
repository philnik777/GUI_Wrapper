#include "GUI_Wrapper/Edit.hpp"

#include "GUI_Wrapper/UTF8_conversion.hpp"

#ifdef _WIN32
	#include "WinAPI/WinAPI_Wrapper.hpp"
	#define WIN_CONVERT Convert::toWstring
#elif defined(linux)
	#include "GTK_Wrapper/Edit.hpp"
	#define WIN_CONVERT
#endif

namespace GUI
{
Edit::Edit(const Element& parent, const std::string& text, Point pos, Area area)
{
	setRaw(UI::Edit::create(parent.getRaw<UI::Element>(), WIN_CONVERT(text),
							{static_cast<long>(pos.x), static_cast<long>(pos.y),
							 static_cast<long>(area.x),
							 static_cast<long>(area.y)}));
}

std::string Edit::getText()
{
	return Convert::toUserString(getRaw<UI::Edit>()->getText());
}
}
