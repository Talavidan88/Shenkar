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



#include "CheckList.h"
#include "../Widget/Widget.h"


CheckList::CheckList(int x, int y, char frame) : Widget(x, y, 40, 40, false), _numberOfItems(0), _head(NULL), _current(NULL), _frame(frame)
{}
CheckList::CheckList(int x, int y) : Widget(x, y, 40, 40, false), _numberOfItems(0), _head(NULL), _current(NULL), _frame('@')
{}

void CheckList::Draw(COORD CursorPosition, const HANDLE& console)
{
	clearWidget(CursorPosition, console, GetWidth(), GetHeight());
	if (!_numberOfItems)
		return;
	CursorPosition = GetCoord();
	node* iterator = _head;

	while (iterator)
	{
		if (iterator->index == _current->index)
			DrawItem(CursorPosition, console, iterator, true, iterator->checked);
		else
 			DrawItem(CursorPosition, console, iterator, false, iterator->checked);
		CursorPosition.Y += 2;

		iterator = iterator->next;
	}
}

void CheckList::DrawItem(COORD CursorPosition, HANDLE console, node* item, bool focusFlag, bool checkedFlag)
{
	int width = GetLongestString() + 6;
	int height = HEIGHT_OF_CELL;
	int k = 0;
	CONSOLE_SCREEN_BUFFER_INFO cbi;
	GetConsoleScreenBufferInfo(console, &cbi);
	DWORD wAttr = cbi.wAttributes;
	DWORD wAttr1 = cbi.wAttributes;
	if (focusFlag)
		wAttr1 = BACKGROUND_BLUE | BACKGROUND_INTENSITY;
	else
		wAttr1 = GetColor();
	for (int i = 0; i < height; ++i)
	{
		SetConsoleCursorPosition(console, CursorPosition);
		CursorPosition.Y += 1;
		for (int j = 0; j < width; ++j)
		{
			if (i == 0 || i % HEIGHT_OF_CELL == 0 || i == height - 1)
			{
				//std::cout << _frame;
			}
			else if (j == 0 || j == width - 1)
			{
				//std::cout << _frame;
			}
			else if (j == 2)
			{
				SetConsoleTextAttribute(console, wAttr1);
				//std::cout << _frame;
			}
			else if (j > 3 && k < item->text.size())
			{
				SetConsoleTextAttribute(console, wAttr1);
				std::cout << item->text.at(k);
				++k;
			}
			else
			{
				SetConsoleTextAttribute(console, wAttr1);
				if (j == 1 && checkedFlag)
					std::cout << 'X';
				else
					std::cout << " ";
			}
			SetConsoleTextAttribute(console, wAttr);
		}
	}
}


int CheckList::GetLongestString() const
{
	node* iterator = _head;
	int maxSize = 0;
	while (iterator)
	{
		if (iterator->text.size() > maxSize)
			maxSize = iterator->text.size();
		iterator = iterator->next;
	}
	return maxSize;
}

void CheckList::Add(std::string text)
{
	if (!_head)
	{
		_head = new node;
		_head->next = NULL;
		_head->text = text;
		_head->index = 0;
		_head->checked = false;
		++_numberOfItems;
		_current = _head;
	}
	else
	{
		while (_current->next)
		{
			_current = _current->next;
		}
		_current->next = new node;
		_current->next->index = _current->index + 1;
		_current = _current->next;
		_current->next = NULL;
		_current->text = text;
		_current->checked = false;
		++_numberOfItems;

	}
	_current = _head;
	SetWidth(GetLongestString() + 4);
	SetHeight((_numberOfItems - 1)*HEIGHT_OF_CELL);
}

bool CheckList::CheckPosition(COORD clickedPosition) const
{
	COORD tmp = GetCoord();
	int y = tmp.Y + (_numberOfItems * HEIGHT_OF_CELL);
	int x = tmp.X + GetLongestString() + 6;
	if (y < clickedPosition.Y || tmp.Y > clickedPosition.Y)
		return false;
	if (x < clickedPosition.X || tmp.X > clickedPosition.X)
		return false;
	return true;
}

int CheckList::MouseEvent(MOUSE_EVENT_RECORD& mer)
{
	if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
		COORD x = mer.dwMousePosition;
		if (CheckPosition(x))
		{
			int tmp = x.Y - GetY();
			tmp = (int)tmp / (HEIGHT_OF_CELL - 1);

			node* iterator = _head;
			while (iterator)
			{
				if (iterator->index == tmp)
				{
					_current = iterator;
					_current->checked = !_current->checked;
					return DRAW;
				}
				iterator = iterator->next;
			}

		}
	}
}





int CheckList::KeyboardEvent(const KEY_EVENT_RECORD& ker, COORD& currentLocation)
{

	if (ker.wVirtualKeyCode == VK_UP || ker.wVirtualKeyCode == 104)
	{
		if (_current != _head)
		{
			node* iterator = _head;
			while (iterator)
			{
				if (iterator->next->index == _current->index)
				{
					_current = iterator;
					return DRAW;
				}
				iterator = iterator->next;
			}
		}
		else return NONE;
	}
	else if (ker.wVirtualKeyCode == VK_DOWN || ker.wVirtualKeyCode == 98)
	{
		if (_current->next)
		{
			_current = _current->next;
			return DRAW;
		}
		else return NONE;
	}
	else if (ker.wVirtualKeyCode == VK_RETURN)
	{
		_current->checked = !_current->checked;
		return DRAW;
	}
}

CheckList::~CheckList()
{
	node* iterator = _head;
	while (iterator->next)
	{
		_head = iterator->next;
		delete iterator;
		iterator = _head;

	}
}


