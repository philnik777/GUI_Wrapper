#include "GUI_Wrapper/Element.hpp"

#include "WinAPI/Window.hpp"

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
	element->setSize({static_cast<long>(a.x), static_cast<long>(a.y)});
}

void Element::previousWindow(const Element& e)
{
	element->setPrevWindow(e.getRaw<UI::Window>());
}

void Element::height(int32_t h) {
	element->setHeight(h);
}

void Element::position(Point pos) {
	element->setPosition({static_cast<long>(pos.x), static_cast<long>(pos.y)});
}

void Element::focus() {
	element->focus();
}
}