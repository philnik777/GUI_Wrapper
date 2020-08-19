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
#ifdef WIN32
Window::Window(const std::string& name)
{
	element = WinAPI::Window::create(Convert::toWString(name));
}

void Window::loop()
{
	element->loop();
}

void Window::closeCallback(std::function<void()> f)
{
	element->setCloseCallback(
		[=](WinAPI::HWND, WinAPI::LPARAM, WinAPI::WPARAM) {
			f();
			return 0;
		});
}

void Window::close()
{
	element->close();
}

void Window::menuBar(const GUI::MenuBar& mb)
{
	element->setMenuBar(mb.getRaw());
}

Rect Window::clientRect()
{
	return element->getClientRect();
}

void Window::postQuitMessage()
{
	UI::postQuitMessage(0);
}

#elif defined(linux)

Window::Window(const std::string& name) : element(gtk::Window::create(name)) {}

#endif
}
