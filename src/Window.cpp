#include "GUI_Wrapper/Window.hpp"

#include "GUI_Wrapper/MenuBar.hpp"
#include "GUI_Wrapper/UTF8_conversion.hpp"

#ifdef WIN32
	#include <WinAPI/Window.hpp>
	#include <WinAPI/WinAPI_Wrapper.hpp>
#elif defined(linux)
	#include <GTK_Wrapper/Window.hpp>
#endif

namespace GUI
{
Window::Window(const std::string& name)
{
	setRaw(std::dynamic_pointer_cast<UI::Element>(
		UI::Window::create(Convert::toSystemString(name))));
}

void Window::loop()
{
	getRaw<UI::Window>()->loop();
}

Rect Window::clientRect()
{
	auto tmp = getRaw<UI::Element>()->getClientRect();
	return *reinterpret_cast<Rect*>(&tmp);
}

void Window::menuBar(const GUI::MenuBar& mb)
{
	getRaw<UI::Window>()->setMenuBar(mb.getRaw());
}

void Window::close()
{
	getRaw<UI::Window>()->close();
}

#ifdef WIN32
void Window::closeCallback(std::function<void()> f)
{
	element->setCloseCallback(
		[=](WinAPI::HWND, WinAPI::LPARAM, WinAPI::WPARAM) {
			f();
			return 0;
		});
}

void Window::postQuitMessage()
{
	UI::postQuitMessage(0);
}

#elif defined(linux)
void Window::closeCallback(std::function<void()> cc)
{
	getRaw<UI::Window>()->setCloseCallback(cc);
}

void Window::postQuitMessage() {}
#endif
}
