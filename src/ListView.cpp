#include "GUI_Wrapper/ListView.hpp"

#include "WinAPI/ListView.hpp"

#include "GUI_Wrapper/UTF8_conversion.hpp"

namespace GUI
{
ListView::ListView(const Element& parent, Rect a)
{
	element = std::dynamic_pointer_cast<UI::Window>(WinAPI::ListView::create(
		parent.getRaw<UI::Window>(), {a.left, a.top, a.right, a.bottom}));
}

void ListView::addColumn(const std::string& name,
						 std::size_t index,
						 std::uint32_t width)
{
	getRaw<UI::ListView>()->addColumn(Convert::toWString(name), index, width);
}

void ListView::addItem(const std::string& name, std::size_t index, std::size_t column)
{
	getRaw<UI::ListView>()->addItem(Convert::toWString(name), index, column);
}

void ListView::removeItem(const std::string& name) {
	getRaw<UI::ListView>()->removeItem(Convert::toWString(name));
}

void ListView::removeAllItems() {
	getRaw<UI::ListView>()->removeAllItems();
}
}