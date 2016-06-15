#pragma once
#include <iostream>
#include "Control.h"
#include "Defines.h"
#include "Button.h"

class TextBox : public Control
{
private:
	std::string _value;
	uint32_t _cursorPosition;
public:
	TextBox(uint32_t width);
	~TextBox();

	void setText(std::string value) throw(StringWiderThenWidthOfControl);
	void setText(std::wstring value);

	void draw(Graphics& g, uint32_t x, uint32_t y, uint32_t z) const override;
	void mousePressed(uint32_t x, uint32_t y, bool isLeft) override;
	void keyDown(uint32_t keyCode, char character) override;
	std::string getText(void) const;
	uint32_t getCursorPosition(void) const override;
	void setCursorToEnd(void) override;
};
