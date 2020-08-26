#include "GUI_Wrapper/ListView.hpp"

#include "GUI_Wrapper/UTF8_conversion.hpp"

#ifdef _WIN32
	#include "WinAPI/ListView.hpp"
#elif defined(linux)
	#include "GTK_Wrapper/ListView.hpp"
#endif

namespace GUI
{
ListView::ListView(const Element& parent, Rect a)
{
	setRaw(std::dynamic_pointer_cast<UI::Element>(UI::ListView::create(
		parent.getRaw<UI::Element>(), {a.left, a.top, a.right, a.bottom})));
}

void ListView::addColumn(const std::string& name,
						 std::size_t index,
						 std::uint32_t width)
{
	getRaw<UI::ListView>()->addColumn(Convert::toSystemString(name), index,
									  width);
}

void ListView::addItem(const std::string& name,
					   std::size_t index,
					   std::size_t column)
{
	getRaw<UI::ListView>()->addItem(Convert::toSystemString(name), index,
									column);
}

void ListView::removeItem(const std::string& name)
{
	getRaw<UI::ListView>()->removeItem(Convert::toSystemString(name));
}

void ListView::removeAllItems()
{
	getRaw<UI::ListView>()->removeAllItems();
}
}