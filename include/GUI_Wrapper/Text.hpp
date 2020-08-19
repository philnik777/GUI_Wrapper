#pragma once

#include "Element.hpp"
#include "Settings.hpp"

#include <memory>
#include <string>

UI_FORWARD_DECLARE_CLASS(Text)

namespace GUI
{
	enum class BindPoint
{
	TOP_LEFT,
	TOP_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_RIGHT,
};

USING_UI_NAMESPACE;
class Text : public Element
{
  public:
	Text(const Element& parent,
		 const std::string& text,
		 Point pos,
		 BindPoint p = BindPoint::TOP_LEFT);

	static auto create(const Element& parent, const std::string& text, Point pos, BindPoint p = BindPoint::TOP_LEFT)
	{
		return std::make_shared<Text>(parent, text, pos, p);
	}
};
}
