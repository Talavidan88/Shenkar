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



#include "TextBox.h"


TextBox::TextBox() : _frame('@'), Widget() 
{ 
	//ConsoleSingleton::GetInstance()->Sign(this);
	//SetColor(BACKGROUND_BLUE | FOREGROUND_RED);
} 

TextBox::TextBox(int x, int y, int width,char frame) : _frame(frame), Widget(x, y, width + 2, 3, true)
{
	//ConsoleSingleton::GetInstance()->Sign(this);
	//SetColor(BACKGROUND_BLUE  | FOREGROUND_RED);
}
TextBox::TextBox(int x, int y, int width) : _frame('@'), Widget(x, y, width + 2, 3, true) 
{
	//ConsoleSingleton::GetInstance()->Sign(this);
	//SetColor(BACKGROUND_BLUE | FOREGROUND_RED);
}
void TextBox::Draw(COORD CursorPosition, const HANDLE& console)
{
	CONSOLE_SCREEN_BUFFER_INFO cbi;
	GetConsoleScreenBufferInfo(console, &cbi);
	DWORD wAttr = GetColor();
	SetConsoleTextAttribute(console, wAttr);
	CursorPosition = GetCoord();
	for (int i = 0; i < GetHeight(); ++i)
	{
		SetConsoleCursorPosition(console, CursorPosition);
		CursorPosition.Y += 1;
		for (int j = 0; j < GetWidth(); ++j)
		{
			if (i == 0 || i == GetHeight() - 1)
			{
				//std::cout << _frame;
			}
			else if (j == 0 || j == GetWidth() - 1)
			{
				//std::cout << _frame;
			}
			else
			{
				if (j <= _content.size())
				{
					std::cout << _content.at(j - 1);
				}
				else
					std::cout << " ";
			}
		}
	}


}

int TextBox::MouseEvent(MOUSE_EVENT_RECORD& mer)
{
	if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
		if (CheckPosition(mer.dwMousePosition))
		{
			int position = GetDefaultPosition().X + _content.size();
			if (mer.dwMousePosition.X > position)
				mer.dwMousePosition.X = position;
			return MOVE_CURSOR;
		}
		return NONE;
	}
}

COORD TextBox::GetDefaultPosition() const
{
	COORD defaultPosition;
	defaultPosition.X = GetX() + 1;
	defaultPosition.Y = GetY() + 1;
	return defaultPosition;
}

bool TextBox::CheckPosition(COORD clickedPosition) const
{
	COORD defaultPosition = GetDefaultPosition();
	int x = defaultPosition.X + GetWidth() - 1;
	int y = defaultPosition.Y + GetHeight() - 2;
	if (clickedPosition.X >= x || clickedPosition.X < defaultPosition.X)
		return false;
	if (clickedPosition.Y >= y || clickedPosition.Y < defaultPosition.Y)
		return false;

	return true;
}

int TextBox::KeyboardEvent(const KEY_EVENT_RECORD& ker, COORD& currentLocation)
{
	if (!GetEditFlag())
		return NONE;
	int position;
	if (ker.bKeyDown)
	{
		switch (ker.wVirtualKeyCode)
		{
		case VK_UP:
			currentLocation.Y -= 1;
			if (CheckPosition(currentLocation))
				return MOVE_CURSOR;
			return NONE;
		case VK_DOWN:
			currentLocation.Y += 1;
			if (CheckPosition(currentLocation))
				return MOVE_CURSOR;
			return NONE;
		case VK_LEFT:
			currentLocation.X -= 1;
			if (CheckPosition(currentLocation))
				return MOVE_CURSOR;
			return NONE;
		case VK_RIGHT:
			currentLocation.X += 1;
			position = currentLocation.X - 1 - GetDefaultPosition().X;
			if (CheckPosition(currentLocation) && position < _content.size())
				return MOVE_CURSOR;
			return NONE;
		case VK_RETURN:
			currentLocation.Y += 1;
			currentLocation.X = GetX() + 1;
			if (CheckPosition(currentLocation))
				return MOVE_CURSOR;
			return NONE;
		case VK_TAB:
			currentLocation.X += 4;
			if (CheckPosition(currentLocation))
			{
				_content += "    ";
				return MOVE_CURSOR;
			}
			return NONE;
		case VK_BACK:
			currentLocation.X -= 1;
			position = currentLocation.X - GetDefaultPosition().X;
			if (CheckPosition(currentLocation))
			{
				DeleteChar(position);
				return DRAW;
			}
			return NONE;
		case VK_DELETE:
			position = currentLocation.X - 1 - GetDefaultPosition().X;
			DeleteChar(position + 1);
			return DRAW;
		default:
			currentLocation.X += 1;
			if (CheckPosition(currentLocation) && _content.size() < GetWidth() - 2)
			{
				position = currentLocation.X - 1 - GetDefaultPosition().X;
				if (ker.uChar.AsciiChar < 126 && ker.uChar.AsciiChar >= 32)
				{
					if (position >= _content.size())
					{
						_content += ker.uChar.AsciiChar;
						return PRINT_KEY;
					}
					else
					{
						_content.at(AddCharToMiddle(position)) = ker.uChar.AsciiChar;
						return DRAW;
					}
				}

				return NONE;
			}
		}
	}

}

int TextBox::AddCharToMiddle(int position)
{
	int i = 0;
	while (i < _content.size())
	{
		if (i == position)
		{
			std::string tmp = _content.substr(0, i);
			tmp += " ";
			tmp += _content.substr(i, _content.size());
			_content = tmp;
			break;
		}
		++i;
	}
	return i;
}

int TextBox::DeleteChar(int position)
{
	int i = 0;
	while (i < _content.size())
	{
		if (i == position)
		{
			std::string tmp = _content.substr(0, i);
			tmp += _content.substr(i + 1, _content.size());
			_content = tmp;
			break;
		}
		++i;
	}
	return i;
}

std::string TextBox::GetContent()const
{
	return _content;
}
TextBox::~TextBox() {}



