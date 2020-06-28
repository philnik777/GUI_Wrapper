#pragma once
#include <functional>
#include <memory>
#include <string>

namespace
#ifdef WIN32
WinAPI
#elif defined(linux)
gtk
#endif
{
class Window;
}

namespace GUI
{
#ifdef WIN32
namespace UI = WinAPI;
#elif defined(linux)
namespace UI = gtk;
#endif

class Window
{
  public:
	Window(const std::string& name);
	static auto create(const std::string& name)
	{
		return std::make_shared<Window>(name);
	}

	void loop();
	void visible(bool);
	bool visible();
	void setCloseCallback(std::function<void()>);
	void close();

  private:
	std::shared_ptr<UI::Window> window;
};
}
