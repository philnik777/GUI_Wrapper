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
#elif defined(linux)
Window::Window(const std::string& name) : window(gtk::Window::create(name)) {}
#endif
}
