#pragma once
#include <memory>
#include <string>

#ifdef WIN32
namespace WinAPI
{
class Window;
}
#elif defined(linux)
namespace gtk
{
class Window;
}
#endif

namespace GUI
{
#ifdef WIN32
#elif defined(linux)
namespace UI = gtk;
#endif

class Window
{
  public:
	Window(const std::string& name);

  private:
	std::shared_ptr<UI::Window> window;
};
}
