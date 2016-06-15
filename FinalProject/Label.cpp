#include "Label.h"


Label::Label(uint32_t width) : Control(width, DEFAULT_HEIGHT, false, false)
{
}

Label::~Label()
{
}

void Label::setText(std::string value)
{
	uint32_t w = getWidth();
	if (value.length() <= w)
	{
		if (w > value.size())
			value.insert(value.end(), w - value.size(), ' ');
		_value = value;
	}
	else
		throw StringWiderThenWidthOfControl();
}

std::string Label::getText(void) const
{
	return _value;
}

void Label::draw(Graphics& g, uint32_t x, uint32_t y, uint32_t z) const
{
	if (z == getLayer())
	{
		g.setBackground(getBackground());
		g.setForeground(getForeground());
		g.write(getCoords().X, getCoords().Y, getText());
		drawBoarder(g, x, y, z);
	}
}
