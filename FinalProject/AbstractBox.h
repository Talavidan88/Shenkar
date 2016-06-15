#pragma once
#include <iostream>
#include <vector>
#include "Control.h"
#include "Defines.h"
#include "Button.h"

class AbstractBox : public Control, public Button::MouseListener
{
protected:
	std::vector<Button*> _entries;
	uint32_t _current;
public:
	AbstractBox(uint32_t height, uint32_t width, std::vector<std::string> entries, BoxType bt) throw(StringWiderThenWidthOfControl,std::bad_alloc);
	virtual ~AbstractBox();
	// Inherited via MouseListener
	void MousePressed(Control& control, int x, int y, bool isLeft, Control* msCb = nullptr) override = 0;

	// Inherited via Control
	virtual void draw(Graphics& g, uint32_t x, uint32_t y, uint32_t z) const override;
	void mousePressed(uint32_t x, uint32_t y, bool isLeft) override = 0;
	void keyDown(uint32_t keyCode, char character) override = 0;
	bool isTabAble(void) override;
	void Show(void) override;
	void Hide(void) override;
	bool canGetFocus() const override;
	void setCoords(uint32_t x, uint32_t y) override;

	uint32_t getHeight() const override
	{
		return DEFAULT_HEIGHT * _entries.size();
	};
};
