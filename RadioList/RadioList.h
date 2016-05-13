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
#include "../ConsoleEventHandler/ConsoleEventHandler.h"
#include <string>

#define HEIGHT_OF_CELL 3
typedef struct Node {
	int index;
	bool checked;
	std::string text;
	Node* next;
}node;
class RadioList :public Widget
{
	node* _head;
	node* _current;
	int _numberOfItems;
	char _frame;

	//Private methods
	int GetLongestString() const;
	void DrawItem(COORD CursorPosition, HANDLE console, node* item, bool focusFlag, bool checkedFlag);

public:
	
	//Constructors
	RadioList(int x, int y, char frame);
	RadioList(int x, int y);

	//Functionalities
	void Add(std::string text);
	void Draw(COORD CursorPosition, const HANDLE& console);
	int MouseEvent(MOUSE_EVENT_RECORD& mer);
	int KeyboardEvent(const KEY_EVENT_RECORD& ker, COORD& currentLocation);
	bool CheckPosition(COORD clickedPosition) const;

	//Destructors
	~RadioList();
};
