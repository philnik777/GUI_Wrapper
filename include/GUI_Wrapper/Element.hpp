#pragma once

#include "Settings.hpp"

#include <memory>

#ifdef _WIN32
UI_FORWARD_DECLARE_CLASS(Window)
#elif defined(linux)
UI_FORWARD_DECLARE_CLASS(Element)
#endif

namespace GUI
{
USING_UI_NAMESPACE;
#ifdef _WIN32
using BaseType = UI::Window;
#elif defined(linux)
using BaseType = UI::Element;
#endif
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
	inline std::shared_ptr<T> getRaw() const
	{
		return std::dynamic_pointer_cast<T>(element);
	}

  protected:
	template<class T>
	inline void setRaw(std::shared_ptr<T> raw)
	{
		element = std::dynamic_pointer_cast<UI::Element>(raw);
	}

  private:
	std::shared_ptr<BaseType> element;
};
}
