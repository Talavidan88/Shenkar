#include <iostream>
#include <string>
#include "ComboBox.h"
#include "../ConsoleSingleton/ConsoleSingleton.h"
#include "../Widget/BoarderDecorator.h"
//#include "../TextBox/TextBox.h"

int main(int argc, char** argv)
{
	
	std::vector<std::string> bla = { "bla","blals","abl","oddfl","csl","aa","b" };
	//ComboBox* mcb = new ComboBox(20, 10, bla);
	//TextBox* tb = new TextBox(30, 10, 10, 10);
	//mcb->Delete(0);
	//mcb->Delete("ff");
	Widget* mcb = new BoarderDecorator(new ComboBox(20, 10, bla), ONELINE);
	ConsoleSingleton::GetInstance()->Sign(mcb);
	//ConsoleSingleton::GetInstance()->Sign(tb);
	ConsoleSingleton::GetInstance()->Listen();
	delete mcb;
	return 0;
}