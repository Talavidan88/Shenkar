#pragma once
#include <iostream>
#include <vector>
#include "Control.h"
#include "Defines.h"
#include "Button.h"
#include <algorithm>

class ComboBox : public Control, public Button::MouseListener
{
private:
	std::vector<Button*> _entries;
	size_t _selected;
	Button* _selectedControl;
	uint32_t _current;
	bool _isOpen;
	bool _redrawFlag;
public:
	ComboBox(uint32_t width, std::vector<std::string> entries);
	~ComboBox();

	size_t getSelectedIndex() const;
	void setSelectedIndex(size_t index) throw (IndexOutOfBounds);

	// Inherited via Control
	virtual void draw(Graphics& g, uint32_t x, uint32_t y, uint32_t z) const override;

	// Inherited via MouseListener
	virtual void MousePressed(Control& control, int x, int y, bool isLeft, Control* msCb = nullptr) override;
	void mousePressed(uint32_t x, uint32_t y, bool isLeft) override;
	void mouseHover(uint32_t x, uint32_t y, bool isLeft) override;
	void keyDown(uint32_t keyCode, char character) override;
	void setRedrawFlag(bool flag) override;
	bool getRedrawFlag(void) const override;
	void setBackground(Color color) override;
	void setForeground(Color color) override;
	void setCoords(uint32_t x, uint32_t y) override;
	uint32_t getHeight() const override;
};
