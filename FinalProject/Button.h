#pragma once
#include <iostream>
#include "Control.h"
#include "Defines.h"

class Button : public Control
{
public:
	struct MouseListener
	{
		virtual void MousePressed(Control& b, int x, int y, bool isLeft, Control* mbCb = nullptr) = 0;
	};

	explicit Button(uint32_t width);
	~Button();
	void setText(std::string value) throw(StringWiderThenWidthOfControl,std::bad_alloc);
	std::string getText(void) const;
	void addListener(MouseListener& listener);


	// Inherited via Control
	virtual void draw(Graphics& g, uint32_t x, uint32_t y, uint32_t z) const override;
	void mousePressed(uint32_t x, uint32_t y, bool isLeft) override;


private:
	std::string _value;
	MouseListener* ml;
};
