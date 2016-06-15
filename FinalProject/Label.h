#pragma once
#include <iostream>
#include "Defines.h"
#include "Control.h"

class Label : public Control
{
private:
	std::string _value;
public:
	Label(uint32_t width);
	~Label();
	void setText(std::string value) throw(StringWiderThenWidthOfControl);
	std::string getText(void) const;
	void draw(Graphics& g, uint32_t x, uint32_t y, uint32_t z) const override;
};
