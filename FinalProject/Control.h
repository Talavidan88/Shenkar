#pragma once
#include "IControl.h"
#include <vector>
#include "SimpleBorderFactory.h"


class Control : public IControl
{
private:
	uint32_t _width;
	uint32_t _height;
	COORD _coords;
	bool _isFocusable;
	static Control* _focused;
	uint32_t _layer;
	Color _background, _foreground;
	bool _isHidden;
	bool _isClickable;
	const BorderDrawer* _borderDrawer;
public:
	Control(const uint32_t& width, const uint32_t& height, const bool& isFocusable, const bool& isClickable);
	~Control();
	void drawBoarder(Graphics& g, uint32_t x, uint32_t y, uint32_t z) const;
	void draw(Graphics& g, uint32_t x, uint32_t y, uint32_t z) const override = 0;
	virtual void mousePressed(uint32_t x, uint32_t y, bool isLeft);
	virtual void mouseHover(uint32_t x, uint32_t y, bool isLeft);
	virtual void keyDown(uint32_t keyCode, char character);


	static Control* getFocus();
	static void setFocus(Control& control);

	virtual void getAllControls(std::vector<Control*>& fill);
	virtual void setAllControls(std::vector<Control*>& fill);

	virtual bool canGetFocus() const;
	void setHidden(bool isHidden);
	bool getHidden(void) const;
	bool isClickAble(void) const;

	void setCoords(uint32_t x, uint32_t y) override;
	COORD getCoords(void) const;
	virtual uint32_t getCursorPosition(void) const;

	uint32_t getWidth() const
	{
		return _width;
	};

	virtual uint32_t getHeight() const
	{
		return _height;
	};

	void setHeight(uint32_t height)
	{
		_height = height;
	};

	uint32_t getLeft(void) const;
	uint32_t getTop(void) const;
	void setLayer(uint32_t layer);
	uint32_t getLayer(void) const;

	virtual void setCursorToEnd(void);

	virtual void setBackground(Color color);
	virtual void setForeground(Color color);
	virtual Color getBackground(void) const;
	virtual Color getForeground(void) const;

	virtual bool isTabAble(void)
	{
		return false;
	};

	virtual void Show(void);
	virtual void Hide(void);
	virtual void setRedrawFlag(bool flag);
	virtual bool getRedrawFlag(void) const;

	struct less_than_key
	{
		inline bool operator()(IControl* struct1, IControl* struct2)
		{
			return (dynamic_cast<Control*>(struct1)->getLayer() > dynamic_cast<Control*>(struct2)->getLayer());
		}
	};

	virtual void setBorder(BorderType bt);

	virtual void setBorderDrawer(const BorderDrawer& borderDrawer)
	{
		_borderDrawer = &borderDrawer;
	}
};
