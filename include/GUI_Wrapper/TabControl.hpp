#pragma once

#include "Element.hpp"

#include <functional>
#include <string>

namespace GUI
{
class TabControl : public Element
{
  public:
	TabControl(const Element& parent, Rect area);

	void addItem(const std::string&,
				 std::size_t index,
				 std::function<void()> onClickCallback,
				 std::function<void()> onOtherTab);
};
}
