#pragma once

#include "Settings.hpp"
#include "Element.hpp"

#include <cstdint>
#include <functional>
#include <memory>
#include <string>

UI_FORWARD_DECLARE_CLASS(Button);

namespace GUI
{
USING_UI_NAMESPACE;
class Window;
class Button : public Element
{
  public:
	Button(const Element& parent, const std::string& name, Point pos);

	void setOnClick(std::function<void()>);
};
}
