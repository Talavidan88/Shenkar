#pragma once
#include <iostream>
#include "Control.h"
#include <vector>
#include <algorithm>
#include "Defines.h"

class Panel : public Control
{
private:
	uint32_t _height;
	uint32_t _width;
	std::vector<IControl*> _controls;
public:
	Panel(const uint32_t& height = 100, const uint32_t& width = 100);
	~Panel();

	void draw(Graphics& g, uint32_t x, uint32_t y, uint32_t z) const override;
	void addControl(IControl& control, uint32_t x, uint32_t y);
	void getAllControls(std::vector<Control*>& fill) override;
	void setAllControls(std::vector<Control*>& fill) override;
	void mousePressed(uint32_t x, uint32_t y, bool isLeft) override;
	void mouseHover(uint32_t x, uint32_t y, bool isLeft) override;
};
