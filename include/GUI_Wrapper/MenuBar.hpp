#pragma once

#include "Settings.hpp"

#include <memory>
#include <string>

UI_FORWARD_DECLARE_CLASS(MenuBar)

namespace GUI
{
USING_UI_NAMESPACE;
class Menu;
class MenuBar
{
  public:
	MenuBar();

	void addMenu(const std::string& name, const GUI::Menu& menu);

	auto getRaw() const
	{
		return mb;
	}

  private:
	std::shared_ptr<UI::MenuBar> mb;
};
}
