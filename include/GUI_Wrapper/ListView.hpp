#pragma once

#include "Element.hpp"
#include "Settings.hpp"

#include <string>
#include <vector>

namespace GUI
{
class ListView : public Element
{
  public:
	ListView(const Element& parent, Rect area);

	void addColumn(const std::string& name,
				   std::size_t index,
				   uint32_t width = 100);

	void addItem(const std::string& name, std::size_t index, std::size_t column);
	void removeItem(const std::string& name);
	void removeAllItems();
};
}
