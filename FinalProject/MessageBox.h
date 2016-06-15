#pragma once
#include "Control.h"
#include "Defines.h"
#include "Label.h"
#include "Button.h"

class MyMessageBox : public Control, public Button::MouseListener
{
private:
	Label _title;
	Label _text;
	Button _ok;
	Button _cancel;
	void setLayersToMax();
	MessageBoxReturn _mbr;
public:
	MyMessageBox(uint32_t height, uint32_t width);
	~MyMessageBox();
	void setText(const std::string& text);
	void setTitle(const std::string& title);

	// Inherited via Control
	virtual void draw(Graphics& g, uint32_t x, uint32_t y, uint32_t z) const override;
	void mousePressed(uint32_t x, uint32_t y, bool isLeft) override;

	void Show(void) override;

	void Hide(void) override;

	void setCoords(uint32_t x, uint32_t y) override;

	void setBackground(Color color) override;

	void setForeground(Color color) override;
	MessageBoxReturn getReturnValue(void) const;
	// Inherited via MouseListener
	virtual void MousePressed(Control& b, int x, int y, bool isLeft, Control* msCb = nullptr) override;
};
