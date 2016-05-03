/*
******************************************************************
******************************************************************
******************************************************************
*******													   *******
*******													   *******
*******			Methods in software engineering			   *******
*******			     Writen By - Golan Sabo				   *******
*******				   Date - 13/3/2016					   *******
*******					   *******						   *******
*******													   *******
******************************************************************
******************************************************************
******************************************************************
*/



#pragma once
#include <string>
#include <iostream>
#include <windows.h>
#include <stdio.h>

class Widget
{
	COORD _location;
	int _width, _height;
	bool _editFlag;
	bool _lightFlag;
	DWORD color;

protected:
	void SetLightFlag(bool flag);
public:
	//constructors
	Widget(const int& x, const int& y, const int& width, const int& height, const bool& editFlag);
	Widget();

	//Getters
	int GetX() const;
	int GetY() const;
	int GetWidth() const;
	int GetHeight() const;
	COORD GetCoord() const;
	bool GetEditFlag() const;
	bool GetLightFlag() const;
	virtual bool GetOpenState() const;
	virtual int GetLongestString() const;
	DWORD GetColor() const;
	//Setters
	void SetColor(DWORD c);
	void SetWidth(int w);
	void SetHeight(int h);

	//Functionalities
	virtual void clearWidget(COORD CursorPosition, const HANDLE& console, const int& width, const int& height) const;
	virtual void Draw(COORD CursorPosition, const HANDLE& console) = 0;
	virtual void Draw_Color(COORD CursorPosition, const HANDLE& console);
	virtual int MouseEvent(MOUSE_EVENT_RECORD& mer) = 0;
	virtual int KeyboardEvent(const KEY_EVENT_RECORD& ker, COORD& currentLocation) = 0;
	virtual bool CheckPosition(COORD clickedPosition) const = 0;
	void EnableEdit(bool flag);


	~Widget();
};

