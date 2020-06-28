#pragma once
#include <string>
#include <memory>

#ifdef WIN32
namespace WinAPI
{
class Window;
}
#endif

namespace GUI {
	class Window {
	  public:
		Window(const std::string& name);

	  private:
		std::shared_ptr<WinAPI::Window> window;
	};
}
