#pragma once
#include "AbstractBox.h"
#include <algorithm>

class CheckList : public AbstractBox
{
private:
	std::vector<size_t> _selected;
	void selectOrDeselect(uint32_t index);
public:
	CheckList(uint32_t height, uint32_t width, std::vector<std::string> entries);
	~CheckList();
	std::vector<size_t> getSelectedIndices() const;
	void selectIndex(size_t index) throw (IndexOutOfBounds);
	void deselectIndex(size_t index) throw (IndexOutOfBounds);

	// Inherited via AbstractBox
	virtual void MousePressed(Control& control, int x, int y, bool isLeft, Control* msCb = nullptr) override;
	virtual void mousePressed(uint32_t x, uint32_t y, bool isLeft) override;
	virtual void keyDown(uint32_t keyCode, char character) override;
	void setBackground(Color color) override;
	void setForeground(Color color) override;
};
