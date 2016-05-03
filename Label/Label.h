#pragma once

#include <string>
#include "../Widget/Widget.h"
#include "../ConsoleEventHandler/ConsoleEventHandler.h"

class Label : public Widget 
{
private:
	std::string _str;
public:
	Label(const int& x,const int& y,const std::string& str);
	~Label();
	void Draw(COORD CursorPosition, const HANDLE& console);
	int MouseEvent(MOUSE_EVENT_RECORD& mer);
	int KeyboardEvent(const KEY_EVENT_RECORD& ker, COORD& currentLocation);
	bool CheckPosition(COORD clickedPosition) const;
};

