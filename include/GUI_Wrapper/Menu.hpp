#pragma once

#include "Settings.hpp"

#include <functional>
#include <memory>
#include <string>

UI_FORWARD_DECLARE_CLASS(Menu)

namespace GUI
{
USING_UI_NAMESPACE;
class Menu
{
  public:
	Menu();
	void addSubMenu(
		const std::string& name, std::function<void()> callback = []() {});

	auto getRaw() const
	{
		return m;
	}

  private:
	std::shared_ptr<UI::Menu> m;
};
}
