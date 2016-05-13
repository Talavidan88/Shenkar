#include <conio.h>
#include <iostream>
#include <string>
#include <windows.h>
#include "../ConsoleSingleton/ConsoleSingleton.h"
#include "Label.h"
#include "../Widget/BoarderDecorator.h"


int main(int)
{
	
	Label* lab = new Label(28, 6, "Hi, my name is label and i love Unicorns!" );
	ConsoleSingleton::GetInstance()->Sign(new BoarderDecorator(lab,ONELINE, FOREGROUND_GREEN | FOREGROUND_INTENSITY));
	ConsoleSingleton::GetInstance()->Listen();
	delete lab;
	return 0;
}
