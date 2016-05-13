#include "TextBox.h"
#include "../ConsoleSingleton/ConsoleSingleton.h"
#include "../Widget/BoarderDecorator.h"
int main(int argc, char* argv[])
{
	TextBox* t = new TextBox(10, 10, 10, '*');
	//t.EnableEdit(true);
	TextBox* t1 = new TextBox(10, 15, 10,'*');
	t1->EnableEdit(false);
	TextBox* t2 = new TextBox(10, 20, 10, '*');
	ConsoleSingleton::GetInstance()->Sign(new BoarderDecorator(new TextBox(10,10,10),ONELINE, BACKGROUND_GREEN));
	ConsoleSingleton::GetInstance()->Sign(new BoarderDecorator(t1,TWOLINE));
	ConsoleSingleton::GetInstance()->Sign(new BoarderDecorator(t2,TWOLINE));

	ConsoleSingleton::GetInstance()->Listen();
	std::cout << "t1 = " << t1->GetContent() << "\n";
	std::cout << "t2 = " << t2->GetContent() << "\n";
	std::cout << "t = " << t->GetContent() << "\n";
	getchar();
	return 0;
}
