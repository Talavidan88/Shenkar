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
#include "../ConsoleSingleton/ConsoleSingleton.h"
#include "../Widget/Widget.h"

class TextBox :public Widget
{
	char _frame;
	std::string _content;
	//Private methods
	int AddCharToMiddle(int position);
	int DeleteChar(int position);
	COORD GetDefaultPosition() const;

public:

	//Constructors
	TextBox(int x, int y, int width, char frame);
	TextBox(int x, int y, int width);
	TextBox();

	//Functionalities
	void Draw(COORD CursorPosition, const HANDLE& console);
	int MouseEvent(MOUSE_EVENT_RECORD& mer);
	int KeyboardEvent(const KEY_EVENT_RECORD& ker, COORD& currentLocation);
	bool CheckPosition(COORD clickedPosition) const;

	std::string GetContent()const;

	~TextBox();
};

