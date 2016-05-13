#include "Decorator.h"



void Decorator::Draw(COORD CursorPosition, const HANDLE& console)
{
	wid->Draw(CursorPosition, console);
}

void Decorator::Draw_Color(COORD CursorPosition, const HANDLE & console)
{
	wid->Draw_Color(CursorPosition, console);
}

Decorator::Decorator(Widget* w) : Widget(w->GetX(), w->GetY(), w->GetWidth(), w->GetHeight() , false)
{
	wid = w;
}

int Decorator::MouseEvent(MOUSE_EVENT_RECORD & mer)
{
	return wid->MouseEvent(mer);
}

int Decorator::KeyboardEvent(const KEY_EVENT_RECORD & ker, COORD & currentLocation)
{
	return wid->KeyboardEvent(ker, currentLocation);
}

bool Decorator::CheckPosition(COORD clickedPosition) const
{
	return wid->CheckPosition(clickedPosition);
}


Decorator::~Decorator()
{
}
