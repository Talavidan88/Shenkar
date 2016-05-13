/*
******************************************************************
******************************************************************
******************************************************************
*******													   *******
*******													   *******
*******			Methods in software engineering			   *******
*******			     Writen By - Golan Sabo				   *******
*******				   Date - 13/3/2016					   *******
*******					   *******						   *******
*******													   *******
******************************************************************
******************************************************************
******************************************************************
*/



#pragma once
#include "../Widget/Widget.h"
#include "../ComboBox/ComboBox.h"

typedef enum
{
	NONE = 0,
	MOVE_CURSOR = 1,
	PRINT_KEY = 2,
	DRAW = 3,
	DRAW_COLOR = 4
}Action;

typedef struct {
	int index;
	Widget* widget;
}WidgetHash;

class ConsoleEventHandler
{
	HANDLE console;
	HANDLE hStdin;
	COORD cursorPosition;
	DWORD wAttr;
	WidgetHash* widgetHash;
	Widget* currentWidgetInFocus;
	int numberOfWidgets;
	int totalSize;
	CONSOLE_CURSOR_INFO cci;
	CONSOLE_SCREEN_BUFFER_INFO cbi;
	//Private Methods
	COORD GetWidgetDefaultCursorPosition(Widget* wid);
public:

	ConsoleEventHandler();
	ConsoleEventHandler(DWORD attributes);
	int CheckWidget(COORD click);
	void Sign(Widget* wid);
	COORD GetCurrentLocation();
	VOID KeyEventProc(KEY_EVENT_RECORD);
	VOID MouseEventProc(MOUSE_EVENT_RECORD);
	//void ChangeCurrentWidgetColor(DWORD color);
	//void ResetColor();
	void Listen();

	~ConsoleEventHandler();
};

