#pragma once

#include <cstdint>

#if defined(WIN32)
#define UI_NAMESPACE WinAPI
#define USING_UI_NAMESPACE namespace UI = WinAPI
#elif defined(linux)
	#define UI_NAMESPACE gtk
#endif

#define UI_FORWARD_DECLARE(el) \
namespace UI_NAMESPACE \
{ \
el \
}

#define UI_FORWARD_DECLARE_CLASS(clazz) \
UI_FORWARD_DECLARE(class clazz;)

namespace GUI
{
struct Point
{
	uint32_t x;
	uint32_t y;
};
using Area = Point;

struct Rect
{
	long left;
	long top;
	long right;
	long bottom;
};
}
