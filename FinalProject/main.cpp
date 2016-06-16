#include "EventEngine.h"
#include "TextBox.h"
#include "Label.h"
#include "Button.h"
#include "Panel.h"
#include "NumericBox.h"
#include "ComboBox.h"
#include "RadioBox.h"
#include "CheckList.h"
#include "Defines.h"
#include "MessageBox.h"
using namespace std;
struct ControlData
{
	string _controlType;
	string _controlName;
	uint32_t _controlNumber;
	void* _data;
};

struct MyListener : public Button::MouseListener
{
	MyListener(Control& c, Control* mbCb) : _c(c), _mbCb(mbCb)
	{
	}

	void MousePressed(Control& b, int x, int y, bool isLeft, Control* mbCb) override
	{
		_c.setForeground(Color::Red);
		_mbCb->Show();
	}

private:
	Control& _c;
	Control* _mbCb;
};

int main(int argc, char** argv)
{
	try
	{
		MessageBox mb(15, 25);
		mb.setText("Wrong Input!!!");
		mb.setTitle("TextBox Input Is Invalid!");
		mb.Hide();
		Label lName(20);
		lName.setText("Name: ");

		Label lAddress(20);
		lAddress.setText("Address:");
		Label lCountry(20);
		lCountry.setText("Counrty:");
		Label lSex(20);
		lSex.setText("Sex:");
		Label lInterests(20);
		lInterests.setText("Interests:");
		Label lAge(20);
		lAge.setText("Age:");
		TextBox tName(20);
		tName.setText("Sherlock Holmes");
		tName.setBorder(BorderType::Single);
		TextBox tAddress(25);
		tAddress.setText("221B Baker Street, London");
		tAddress.setBorder(BorderType::Single);
		ComboBox cCountry(20, { "Israel", "Great Britain", "United States" });
		cCountry.setSelectedIndex(1);
		cCountry.setBorder(BorderType::Single);
		RadioBox rSex(2, 15, { "Male", "Female" });
		rSex.setBorder(BorderType::Single);
		CheckList clInterests(3, 15, { "Sports", "Books", "Movies" });
		clInterests.selectIndex(1);
		clInterests.setBorder(BorderType::Single);
		NumericBox nAge(15, 18, 120);
		nAge.setValue(23);
		nAge.setBorder(BorderType::Single);
		MyListener listener(tAddress, &mb);
		Button bSubmit(10);
		bSubmit.setText("Submit");
		bSubmit.addListener(listener);
		bSubmit.setBorder(BorderType::Double);
		Panel main;
		cCountry.setBackground(Color::Green);
		rSex.setBackground(Color::Cyan);
		nAge.setBackground(Color::Red);
		clInterests.setBackground(Color::Orange);
		main.addControl(lName, 1, 2);
		main.addControl(lAddress, 1, 5);
		main.addControl(lCountry, 1, 8);
		main.addControl(lSex, 1, 11);
		main.addControl(lInterests, 1, 16);
		main.addControl(lAge, 1, 23);
		main.addControl(tName, 25, 2);
		main.addControl(tAddress, 25, 5);
		main.addControl(cCountry, 25, 8);
		main.addControl(rSex, 25, 11);
		main.addControl(clInterests, 25, 16);
		main.addControl(nAge, 25, 23);
		main.addControl(mb, 10, 10);
		mb.setBorder(BorderType::Single);
		main.addControl(bSubmit, 1, 26);
		Control::setFocus(tName);
		EventEngine engine;
		engine.run(main);
		
	}
	catch (exception& e)
	{
		cerr << e.what();
	}
	return 0;
}
