#include "Window.hpp"
#include <WinAPI/Window.hpp>
#include "UTF8_conversion.hpp"

namespace GUI
{
Window::Window(const std::string& name)
	: window(WinAPI::Window::create(Convert::toWString(name)))
{}
}
