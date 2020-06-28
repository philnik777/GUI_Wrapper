#include "Window.hpp"

#include "UTF8_conversion.hpp"

#ifdef WIN32
	#include <WinAPI/Window.hpp>
#elif defined(linux)
	#include <GTK_Wrapper/Window.hpp>
#endif

namespace GUI
{
#ifdef WIN32
Window::Window(const std::string& name)
	: window(WinAPI::Window::create(Convert::toWString(name)))
{}

void Window::loop()
{
	window->loop();
}

void Window::visible(bool s)
{
	window->setVisible(s);
}

bool Window::visible()
{
	return window->isVisible();
}

void Window::setCloseCallback(std::function<void()> f)
{
	window->setCloseCallback([=](WinAPI::HWND, WinAPI::LPARAM, WinAPI::WPARAM) {
		f();
		return 0;
	});
}

void Window::close() {
	window->close();
}

#elif defined(linux)

Window::Window(const std::string& name) : window(gtk::Window::create(name)) {}

#endif
}
