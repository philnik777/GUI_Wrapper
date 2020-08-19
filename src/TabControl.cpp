#include "GUI_Wrapper/TabControl.hpp"

#include "GUI_Wrapper/UTF8_conversion.hpp"
#include "WinAPI/TabControl.hpp"

namespace GUI
{
TabControl::TabControl(const Element& parent, Rect a)
{
	element = std::dynamic_pointer_cast<UI::Window>(UI::TabControl::create(
		parent.getRaw<UI::Window>(), {a.left, a.top, a.right, a.bottom}));
}

void TabControl::addItem(const std::string& name,
						 std::size_t index,
						 std::function<void()> onClickCallback,
						 std::function<void()> onOtherTab)
{
	getRaw<WinAPI::TabControl>()->addItem(Convert::toWString(name), index,
										  onClickCallback, onOtherTab);
}
}
