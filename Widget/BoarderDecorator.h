#pragma once
#include "Decorator.h"
typedef enum {
	NOBOARDER,
	ONELINE,
	TWOLINE
}BoarderType;
class BoarderDecorator :
	public Decorator
{
protected:
	BoarderType type;
public:
	virtual void Draw(COORD CursorPosition, const HANDLE& console);
	virtual void Draw_Color(COORD CursorPosition, const HANDLE& console);
	BoarderDecorator(Widget* w,BoarderType type = NOBOARDER,int color = FOREGROUND_RED| FOREGROUND_GREEN|FOREGROUND_BLUE);
	~BoarderDecorator();
};

