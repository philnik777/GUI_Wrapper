#pragma once

#include "Settings.hpp"
#include "Element.hpp"

#include <string>

UI_FORWARD_DECLARE_CLASS(Edit)

namespace GUI
{
USING_UI_NAMESPACE;
class Edit : public Element
{
  public:
	Edit(const Element& parent, const std::string& text, Point pos, Area area);

	std::string getText();
};
}
