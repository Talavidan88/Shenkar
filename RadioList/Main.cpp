
#include "RadioList.h"
#include "../ConsoleSingleton/ConsoleSingleton.h"
#include "../Widget/BoarderDecorator.h"
int main(int argc, char** argv)
{
	RadioList* rd = new RadioList(10, 10, '*');
	rd->Add("Golan Sabo");
	rd->Add("Ital Daskal");
	rd->Add("Ido Argom");
	rd->Add("Tal Avidan");
	//TextBox* t = new TextBox(10, 20, 10, 10, '~');
	ConsoleSingleton::GetInstance()->Sign(new BoarderDecorator(rd,ONELINE));
	//ConsoleSingleton::GetInstance()->Sign(t);
	//ConsoleSingleton::GetInstance()->ChangeCurrentWidgetColor(FOREGROUND_RED | FOREGROUND_INTENSITY);

	ConsoleSingleton::GetInstance()->Listen();
	getchar();

	return 0;
}