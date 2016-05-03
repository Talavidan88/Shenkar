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



#include "Widget.h"



Widget::Widget(const int& x, const int& y, const int& width, const int& height, const bool& editFlag) :_width(width), _height(height), _editFlag(editFlag), _lightFlag(false), color(0)
{
	_location.X = x;
	_location.Y = y;
}

Widget::Widget() : _width(10), _height(5), _editFlag(false), _lightFlag(false), color(0)
{
	_location.X = 15;
	_location.Y = 15;
}

int Widget::GetX() const
{
	return _location.X;
}

int Widget::GetY() const
{
	return _location.Y;
}

COORD Widget::GetCoord() const
{
	return _location;
}
int Widget::GetWidth() const
{
	return _width;
}

int Widget::GetHeight() const
{
	return _height;
}

void Widget::EnableEdit(bool flag)
{
	if (flag)
	{

	}
	_editFlag = flag;
}

void Widget::SetLightFlag(bool flag)
{
	_lightFlag = flag;
}

bool Widget::GetLightFlag() const
{
	return _lightFlag;
}

bool Widget::GetOpenState() const
{
	return true;
}

int Widget::GetLongestString() const
{
	return 0;
}

bool Widget::GetEditFlag() const
{
	return _editFlag;
}

void Widget::SetColor(DWORD c)
{
	color = c;
}

void Widget::SetWidth(int w)
{
	_width = w;
}

void Widget::SetHeight(int h)
{
	_height = h;
}


void Widget::clearWidget(COORD CursorPosition, const HANDLE & console, const int & width, const int & height) const
{
	CONSOLE_SCREEN_BUFFER_INFO cbi;
	GetConsoleScreenBufferInfo(console, &cbi);
	DWORD wAttr = cbi.wAttributes;
	SetConsoleCursorPosition(console, CursorPosition);
	for (int i = 0; i < height; ++i)
	{
		SetConsoleCursorPosition(console, CursorPosition);
		CursorPosition.Y += 1;
		for (int j = 0; j < width; ++j) {
			std::cout << " ";
		}
		SetConsoleTextAttribute(console, wAttr);
	}
}

void Widget::Draw_Color(COORD CursorPosition, const HANDLE& console)
{
}

DWORD Widget::GetColor() const
{
	return color;
}


Widget::~Widget()
{
}
