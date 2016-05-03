/*
	******************************************************************
	******************************************************************
	******************************************************************
	*******													   *******
	*******					         						   *******
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
#include "../TextBox/TextBox.h"
#include "../Widget/BoarderDecorator.h"
int main(int argc, char* argv[])
{
	CheckList* rd = new CheckList(10, 10, '*');
	rd->Add("Golan Sabo");
	rd->Add("Ital Daskal");
	rd->Add("Ido Argom");
	rd->Add("Tal Avidan");
	//TextBox* t = new TextBox(10, 20, 10, 10, '~');
	ConsoleSingleton::GetInstance()->Sign(new BoarderDecorator(rd,TWOLINE, BACKGROUND_RED));
	//ConsoleSingleton::GetInstance()->Sign(t);
	//ConsoleSingleton::GetInstance()->ChangeCurrentWidgetColor(FOREGROUND_RED | FOREGROUND_INTENSITY);

	ConsoleSingleton::GetInstance()->Listen();
	getchar();

	return 0;
}