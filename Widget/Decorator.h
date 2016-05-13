#pragma once
#include "Widget.h"
class Decorator :
	public Widget
{
protected:
	Widget *wid;
public:
	virtual void Draw(COORD CursorPosition, const HANDLE& console);
	virtual void Draw_Color(COORD CursorPosition, const HANDLE& console);
	Decorator(Widget* w);
	virtual int MouseEvent(MOUSE_EVENT_RECORD& mer);
	virtual int KeyboardEvent(const KEY_EVENT_RECORD& ker, COORD& currentLocation);
	virtual bool CheckPosition(COORD clickedPosition) const;
	~Decorator();
};

