#include "Label.h"



Label::Label(const int& x,const int& y,const std::string& str) : Widget(x, y, 10, 10, 0 ) , _str(str)
{
	SetWidth(str.length()+4);
	SetHeight(HEIGHT_OF_CELL);
}


Label::~Label()
{

}

void Label::Draw(COORD CursorPosition, const HANDLE & console)
{
	CursorPosition = GetCoord();
	int width = _str.length() + 6;
	int height = HEIGHT_OF_CELL;
	int k = 0;
	CONSOLE_SCREEN_BUFFER_INFO cbi;
	GetConsoleScreenBufferInfo(console, &cbi);
	DWORD wAttr = cbi.wAttributes;
	DWORD wAttr1 = GetColor();

	for (int i = 0; i < height; ++i)
	{
		SetConsoleCursorPosition(console, CursorPosition);
		CursorPosition.Y += 1;
		for (int j = 0; j < width; ++j)
		{
			if (i == 0 || i % HEIGHT_OF_CELL == 0 || i == height - 1)
			{
				//std::cout << '*';
			}
			else if (j == 0 || j == width - 1)
			{
				//std::cout << '*';
			}

			else if (j > 2 && k < _str.size())
			{
				SetConsoleTextAttribute(console, wAttr1);
				std::cout << _str.at(k);
				++k;
			}
			else
			{
				SetConsoleTextAttribute(console, wAttr1);
				std::cout << " ";
			}
			SetConsoleTextAttribute(console, wAttr);
		}
	}
}

int Label::MouseEvent(MOUSE_EVENT_RECORD & mer)
{
	return 0;
}

int Label::KeyboardEvent(const KEY_EVENT_RECORD & ker, COORD & currentLocation)
{
	return 0;
}

bool Label::CheckPosition(COORD clickedPosition) const
{
	return false;
}
