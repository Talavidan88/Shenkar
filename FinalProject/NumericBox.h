#pragma once
#include <iostream>
#include "Control.h"
#include "Defines.h"
#include "Label.h"
#include "Button.h"

class NumericBox : public Control, public Button::MouseListener
{
private:
	int32_t _min;
	int32_t _max;
	Label _value;
	Button _minBtn;
	Button _maxBtn;
	int32_t _decOrInc;
public:
	NumericBox(uint32_t width, int32_t min, int32_t max);
	~NumericBox();

	int32_t getValue() const;
	bool setValue(int32_t value);

	// Inherited via MouseListener
	virtual void MousePressed(Control& control, int x, int y, bool isLeft, Control* msCb = nullptr) override;

	// Inherited via Control
	virtual void draw(Graphics& g, uint32_t x, uint32_t y, uint32_t z) const override;
	void mousePressed(uint32_t x, uint32_t y, bool isLeft) override;
	void Show(void) override;
	void Hide(void) override;
	void setCoords(uint32_t x, uint32_t y) override;
	void setBackground(Color color) override;
	void setForeground(Color color) override;
};
