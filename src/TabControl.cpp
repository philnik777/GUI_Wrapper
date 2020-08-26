#include "GUI_Wrapper/TabControl.hpp"

#include "GUI_Wrapper/UTF8_conversion.hpp"

#ifdef _WIN32
	#include "WinAPI/TabControl.hpp"
#elif defined(linux)
	#include "GTK_Wrapper/TabControl.hpp"
#endif

namespace GUI
{
TabControl::TabControl(const Element& parent, Rect a)
{
	setRaw(std::dynamic_pointer_cast<UI::Element>(UI::TabControl::create(
		parent.getRaw<UI::Element>(), {a.left, a.top, a.right, a.bottom})));
}

void TabControl::addItem(const std::string& name,
						 std::size_t index,
						 std::function<void()> onClickCallback,
						 std::function<void()> onOtherTab)
{
	getRaw<UI::TabControl>()->addItem(Convert::toSystemString(name), index,
									  onClickCallback, onOtherTab);
}
}
