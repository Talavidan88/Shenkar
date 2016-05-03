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




#include "ConsoleEventHandler.h"


ConsoleEventHandler::ConsoleEventHandler()
{

	console = GetStdHandle(STD_OUTPUT_HANDLE);
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &cbi);
	wAttr = cbi.wAttributes;
	numberOfWidgets = 0;
	totalSize = 0;
	currentWidgetInFocus = NULL;
}

ConsoleEventHandler::ConsoleEventHandler(DWORD attributes)
{
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &cbi);
	wAttr = attributes;
	numberOfWidgets = 0;
	totalSize = 0;
	SetConsoleTextAttribute(console, wAttr);
	currentWidgetInFocus = NULL;
}

void ConsoleEventHandler::Sign(Widget* wid)
{
	if (!numberOfWidgets)
	{
		widgetHash = new WidgetHash[5];
		totalSize = 5;
	}
	else if (numberOfWidgets == totalSize)
	{
		WidgetHash* tmp = new WidgetHash[totalSize * 2];
		for (int i = 0; i < totalSize; ++i)
		{
			tmp[i] = widgetHash[i];
		}
		delete[] widgetHash;
		widgetHash = tmp;
	}
	widgetHash[numberOfWidgets].widget = wid;
	widgetHash[numberOfWidgets].index = numberOfWidgets + 1;

	++numberOfWidgets;
	currentWidgetInFocus = wid;
	if (wid->GetEditFlag())
	{
		cursorPosition.X = wid->GetX() + 1;
		cursorPosition.Y = wid->GetY() + 1;
		CONSOLE_CURSOR_INFO cci = { 10, TRUE };
		SetConsoleCursorInfo(console, &cci);
	}
	else
	{
		CONSOLE_CURSOR_INFO cci = { 10, FALSE };
		SetConsoleCursorInfo(console, &cci);
	}

	wid->Draw(cursorPosition, console);
	SetConsoleCursorPosition(console, GetWidgetDefaultCursorPosition(wid));
	//Listen();

}

void ConsoleEventHandler::Listen()
{
	DWORD fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	DWORD cNumRead;
	INPUT_RECORD irInBuf[128];
	if (!SetConsoleMode(hStdin, fdwMode))
		exit(1);

	while (true)
	{
		// Wait for the events. 

		if (!ReadConsoleInput(
			hStdin,      // input buffer handle 
			irInBuf,     // buffer to read into 
			128,         // size of read buffer 
			&cNumRead)) // number of records read 
			exit(1);

		// Dispatch the events to the appropriate handler. 

		for (int i = 0; i < cNumRead; i++)
		{
			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT: // keyboard input 
				if (irInBuf[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) {
					COORD tmp;
					tmp.X = 0;
					tmp.Y = 0;
					SetConsoleCursorPosition(console, tmp);
					return;
				}
				KeyEventProc(irInBuf[i].Event.KeyEvent);
				break;

			case MOUSE_EVENT: // mouse input 
				MouseEventProc(irInBuf[i].Event.MouseEvent);
				break;

			default:
				break;
			}
		}
	}
}

VOID ConsoleEventHandler::KeyEventProc(KEY_EVENT_RECORD ker)
{
	if (!ker.bKeyDown)
		return;

	COORD tmp = GetCurrentLocation();

	switch (currentWidgetInFocus->KeyboardEvent(ker, tmp))
	{
	case NONE:
		break;
	case MOVE_CURSOR:
		SetConsoleCursorPosition(console, tmp);
		cursorPosition = tmp;
		break;
	case PRINT_KEY:
		std::cout << ker.uChar.AsciiChar;
		cursorPosition = tmp;
		break;
	case DRAW:
		//ResetColor();
		//ChangeCurrentWidgetColor(currentWidgetInFocus->GetColor());
		currentWidgetInFocus->Draw(currentWidgetInFocus->GetCoord(), console);
		//SetConsoleCursorPosition(console, tmp);
		//cursorPosition = tmp;
		break;
	case DRAW_COLOR:
		currentWidgetInFocus->Draw_Color(currentWidgetInFocus->GetCoord(), console);
		break;
	}


}

VOID ConsoleEventHandler::MouseEventProc(MOUSE_EVENT_RECORD mer)
{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif
	int ret;
	COORD tmp = mer.dwMousePosition;
	int x = CheckWidget(tmp);
	if (x == -1) {
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {

			for (int i = 0; i < numberOfWidgets; ++i) {
				Widget* wid = widgetHash[i].widget;
				if (!wid->GetOpenState())
					wid->Draw(wid->GetCoord(), console);
			}
			/*ComboBox* cb = dynamic_cast<ComboBox*> (wid);
			if (cb != NULL)
			if (!cb->GetOpenState())
			cb->Draw(cb->GetCoord(), console);
			*/


		}
		return;
	}

	Widget* wid = widgetHash[x].widget;
	ret = wid->MouseEvent(mer);
	switch (ret) {
	case DRAW_COLOR:
		currentWidgetInFocus->Draw_Color(currentWidgetInFocus->GetCoord(), console);
		break;
	}
	if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
	{
		COORD tmp = mer.dwMousePosition;
		int x = CheckWidget(tmp);
		if (x == -1)
			return;
		Widget* wid = widgetHash[x].widget;

		switch (ret)
		{
		case NONE:
			currentWidgetInFocus = widgetHash[x].widget;
			break;
		case MOVE_CURSOR:
			tmp = mer.dwMousePosition;
			SetConsoleCursorPosition(console, tmp);
			cursorPosition = tmp;
			if (currentWidgetInFocus != widgetHash[x].widget)
			{
				currentWidgetInFocus = widgetHash[x].widget;
				//ResetColor();
				//ChangeCurrentWidgetColor(currentWidgetInFocus->GetColor());
			}
			break;
		case DRAW:
			currentWidgetInFocus = widgetHash[x].widget;
			//ResetColor();
			//ChangeCurrentWidgetColor(currentWidgetInFocus->GetColor());
			currentWidgetInFocus->Draw(currentWidgetInFocus->GetCoord(), console);
			break;
		}
		if (currentWidgetInFocus->GetEditFlag())
		{
			CONSOLE_CURSOR_INFO cci = { 10, TRUE };
			SetConsoleCursorInfo(console, &cci);
		}
		else
		{
			CONSOLE_CURSOR_INFO cci = { 10, FALSE };
			SetConsoleCursorInfo(console, &cci);
		}
	}
	return;
}

int ConsoleEventHandler::CheckWidget(COORD click)
{
	for (int i = 0; i < numberOfWidgets; ++i)
	{
		Widget* tmp = widgetHash[i].widget;
		if (tmp->CheckPosition(click))
		{
			return i;
		}
	}
	return -1;
}

COORD ConsoleEventHandler::GetCurrentLocation()
{
	return cursorPosition;
}


COORD ConsoleEventHandler::GetWidgetDefaultCursorPosition(Widget* wid)
{
	COORD tmp = wid->GetCoord();
	++tmp.X;
	++tmp.Y;
	return tmp;
}

//void ConsoleEventHandler::ChangeCurrentWidgetColor(DWORD color)
//{
//	currentWidgetInFocus->SetColor(BACKGROUND_RED);
//	SetConsoleTextAttribute(console, currentWidgetInFocus->GetColor());
//	currentWidgetInFocus->Draw(currentWidgetInFocus->GetCoord(), console);
//	SetConsoleCursorPosition(console, GetWidgetDefaultCursorPosition(currentWidgetInFocus));
//}
//
//void ConsoleEventHandler::ResetColor()
//{
//	SetConsoleTextAttribute(console, 0);
//
//}

ConsoleEventHandler::~ConsoleEventHandler()
{
	for (int i = 0; i < numberOfWidgets; ++i)
	{
		delete widgetHash[i].widget;
	}
	delete widgetHash;
}
