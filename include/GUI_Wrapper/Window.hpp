#pragma once

#include "Element.hpp"
#include "Settings.hpp"

#include <functional>
#include <memory>
#include <string>

UI_FORWARD_DECLARE_CLASS(Window);

namespace GUI
{
USING_UI_NAMESPACE;
class MenuBar;
class Window : public Element
{
  public:
	Window(const std::string& name);
	static auto create(const std::string& name)
	{
		return std::make_shared<Window>(name);
	}

	void loop();
	void close();

	void closeCallback(std::function<void()>);
	void menuBar(const GUI::MenuBar&);
	Rect clientRect();

	void postQuitMessage();
};
}
