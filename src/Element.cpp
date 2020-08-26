#include "GUI_Wrapper/Element.hpp"

#ifdef _WIN32
	#include "WinAPI/Window.hpp"
#elif defined(linux)
	#include "GTK_Wrapper/Element.hpp"
#endif

namespace GUI
{
void Element::visible(bool b)
{
	element->setVisible(b);
}

bool Element::visible()
{
	return element->isVisible();
}

void Element::resizable(bool b)
{
	element->resizable(b);
}

void Element::size(const Area& a)
{
	using castType = decltype(Area::x);
	element->setSize({static_cast<castType>(a.x), static_cast<castType>(a.y)});
}

void Element::previousWindow(const Element& e)
{
	element->setPrevWindow(e.getRaw<BaseType>());
}

void Element::height(int32_t h)
{
	element->setHeight(h);
}

void Element::position(Point pos)
{
	using CastType = decltype(Point::x);
	element->setPosition(
		{static_cast<CastType>(pos.x), static_cast<CastType>(pos.y)});
}

void Element::focus()
{
	element->focus();
}
}