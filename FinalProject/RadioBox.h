#pragma once
#include "AbstractBox.h"

class RadioBox : public AbstractBox
{
private:
	size_t _selected;
	void ClearAstrix();
public:
	RadioBox(uint32_t height, uint32_t width, std::vector<std::string> entries);
	~RadioBox();
	size_t getSelectedIndex() const;
	void setSelectedIndex(size_t index);

	// Inherited via MouseListener
	virtual void MousePressed(Control& control, int x, int y, bool isLeft, Control* msCb = nullptr) override;

	// Inherited via Control
	void mousePressed(uint32_t x, uint32_t y, bool isLeft) override;
	void keyDown(uint32_t keyCode, char character) override;
	void setBackground(Color color) override;
	void setForeground(Color color) override;
};
