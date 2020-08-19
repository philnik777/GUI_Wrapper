#pragma once

#include "Settings.hpp"

#include <memory>

UI_FORWARD_DECLARE_CLASS(Window)

namespace GUI
{
USING_UI_NAMESPACE;
class Element
{
  public:
	void visible(bool b);
	bool visible();
	void resizable(bool b);
	void size(const Area& a);
	void previousWindow(const Element& e);
	void height(int32_t);
	void position(Point);
	void focus();

	template<class T>
	std::shared_ptr<T> getRaw() const
	{
		return std::dynamic_pointer_cast<T>(element);
	}

  protected:
	std::shared_ptr<UI::Window> element;
};
}
