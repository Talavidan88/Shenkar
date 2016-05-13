#include "BoarderDecorator.h"


void gotoXY(const HANDLE& console, COORD CursorPosition, int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void DrawFrame(const HANDLE& console, COORD CursorPosition,int style, int col, int row, int length, int amount)
{
	int a;
	char box[12];
	style = (style - 1) * 6;
	box[0] = '\xDA';//  ┌
	box[1] = '\xBF';//  ┐
	box[2] = '\xC0';//  └
	box[3] = '\xD9';//  ┘
	box[4] = '\xB3';//  │ 
	box[5] = '\xC4';//  ─
	box[6] = '\xC9';//  ╔ 
	box[7] = '\xBB';//  ╗
	box[8] = '\xC8';//  ╚
	box[9] = '\xBC';//  ╝
	box[10] = '\xBA';// ║
	box[11] = '\xCD';// ═


	char tl, tr, bl, br, side, edge, shadow;
	tl = box[style];
	tr = box[style + 1];
	bl = box[style + 2];
	br = box[style + 3];
	side = box[style + 4];
	edge = box[style + 5];

	std::string Line(length - 1, edge);
	CursorPosition.X -= 1;
	SetConsoleCursorPosition(console, CursorPosition);
	col = CursorPosition.X;
	row = CursorPosition.Y;
	std::cout << tl << Line << tr;
	for (a = 1; a <amount - 1; a++)
	{
		gotoXY(console, CursorPosition, col, row + a);
		std::cout << side;
		gotoXY(console, CursorPosition, col + length, row + a);
		std::cout << side;
	}
	gotoXY(console, CursorPosition, col, (amount + row) - 1);
	std::cout << bl << Line << br;

}


void BoarderDecorator::Draw(COORD CursorPosition, const HANDLE& console)
{
	//clearWidget(CursorPosition, console, this->GetWidth() + 2, this->GetHeight());
	Decorator::Draw(CursorPosition,console);
	CursorPosition = wid->GetCoord();
	switch (type)
	{
	case NOBOARDER:
		break;
	case ONELINE:
	{
		DrawFrame(console,CursorPosition,ONELINE, CursorPosition.X, CursorPosition.Y, wid->GetWidth(), wid->GetHeight());
		break;
	}
		
	case TWOLINE:
		DrawFrame(console, CursorPosition, TWOLINE, CursorPosition.X, CursorPosition.Y, wid->GetWidth(), wid->GetHeight());

		break;
	default:
		break;
	}

}

void BoarderDecorator::Draw_Color(COORD CursorPosition, const HANDLE & console)
{
	//clearWidget(CursorPosition, console, this->GetWidth() + 2, this->GetHeight());
	Decorator::Draw_Color(CursorPosition, console);
	CursorPosition = wid->GetCoord();
	switch (type)
	{
	case NOBOARDER:
		break;
	case ONELINE:
	{
		DrawFrame(console, CursorPosition, ONELINE, CursorPosition.X, CursorPosition.Y, wid->GetLongestString() + 5, wid->GetHeight());

		break;
	}

	case TWOLINE:
		DrawFrame(console, CursorPosition, TWOLINE, CursorPosition.X, CursorPosition.Y, wid->GetLongestString() + 5, wid->GetHeight());

	default:
		break;
	}
}

BoarderDecorator::BoarderDecorator(Widget * w, BoarderType type,int color) : Decorator(w), type(type)
{
	w->SetColor(color);
}


BoarderDecorator::~BoarderDecorator()
{
}



