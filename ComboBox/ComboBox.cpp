#include "ComboBox.h"
/***************************************************************************
*                                                                          *
* FILE NAME:   ComboBox.cpp                                                *
*                                                                          *
* MODULE NAME: ComboBox                                                    *
*                                                                          *
* PROGRAMMER:  Tal Avidan.							                       *
*                                                                          *
* DESCRIPTION: API For ComboBox GUI.				                       *
*                                                                          *
* REVISION:    01_00  19/03/16                                             *
*                                                                          *
****************************************************************************/


/* --------------------------------------------------------------------
* FUNCTION NAME: Constructor
* DESCRIPTION  : Creates a ComboBox object.
* RETURN       : None.
* NOTES        : None.
* -------------------------------------------------------------------- */
ComboBox::ComboBox(int x, int y, std::vector<std::string> labels) : Widget(x, y, 10, 10, false), _current(0),_selected(0), _isOpen(false) {
	
	std::sort(labels.begin(), labels.end());
	for (std::vector<std::string>::iterator itr = labels.begin(); itr != labels.end(); ++itr) {
		Add(*itr);
	}
	SetWidth(GetLongestString() + 4);
	SetHeight(HEIGHT_OF_CELL);
	_isSorted = true;
}

/* --------------------------------------------------------------------
* FUNCTION NAME: Add
* DESCRIPTION  : Adds a label to the ComboBox object.
* RETURN       : None.
* NOTES        : None.
* -------------------------------------------------------------------- */
void ComboBox::Add(const std::string& toAdd) {
	cmb temp;
	temp.index = _comboNames.size();
	temp.text = toAdd;
	_comboNames.push_back(temp);
	_isSorted = false;
}


/* --------------------------------------------------------------------
* FUNCTION NAME: Delete
* DESCRIPTION  : Delets a label from the ComboBox object using index.
* RETURN       : None.
* NOTES        : None.
* -------------------------------------------------------------------- */
void ComboBox::Delete(const int& index) {
	_comboNames.erase(_comboNames.begin() + index);
	if (_current != 0) --_current;
	SortArray();
}

/* --------------------------------------------------------------------
* FUNCTION NAME: Delete
* DESCRIPTION  : Delets a label from the ComboBox object searching a string.
* RETURN       : None.
* NOTES        : None.
* -------------------------------------------------------------------- */
void ComboBox::Delete(const std::string& toDelete) {
	for (strVecItr itr = _comboNames.begin(); itr != _comboNames.end(); ++itr) {
		if (itr->text == toDelete) {
			_comboNames.erase(itr);
			SortArray();
			if (_current != 0) --_current;
			return;
		}
	}
}

/* --------------------------------------------------------------------
* FUNCTION NAME: GetLongestString
* DESCRIPTION  : Returns the longest string size in ComboBox array.
* RETURN       : Int - longest string size
* NOTES        : Private Method
* -------------------------------------------------------------------- */
int ComboBox::GetLongestString() const
{
	int maxSize = 0;
	for (std::vector<cmb>::const_iterator itr = _comboNames.begin(); itr != _comboNames.end(); ++itr)
		if (itr->text.size() > maxSize)
			maxSize = itr->text.size();
	return maxSize;
}

/* --------------------------------------------------------------------
* FUNCTION NAME: DrawItem
* DESCRIPTION  : Draws one item on console.
* RETURN       : None.
* NOTES        : Private Method
* -------------------------------------------------------------------- */
void ComboBox::DrawItem(COORD CursorPosition, const HANDLE& console, strVecItr itr, const bool& focusFlag) const
{

	int width = GetLongestString() + 4;
	int height = HEIGHT_OF_CELL;
	int k = 0;
	CONSOLE_SCREEN_BUFFER_INFO cbi;
	//SetConsoleTextAttribute(console, BACKGROUND_RED);
	GetConsoleScreenBufferInfo(console, &cbi);

	DWORD wAttr = cbi.wAttributes;
	DWORD wAttr1 = cbi.wAttributes;
	if (focusFlag)
		wAttr1 = BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
	else
		wAttr1 = GetColor();
	for (int i = 0; i < height; ++i)
	{
		SetConsoleCursorPosition(console, CursorPosition);
		CursorPosition.Y += 1;
		for (int j = 0; j < width; ++j)
		{
			if (i == 0 || i % HEIGHT_OF_CELL == 0 || i == height - 1)
			{
				//std::cout << "*";
			}
			else if (j == width - 1)
			{
					//std::cout << " ";
			}

			else if (j > 1 && k < itr->text.size())
			{
				SetConsoleTextAttribute(console, wAttr1);
				std::cout << itr->text.at(k);
				++k;
			}
			else
			{
				SetConsoleTextAttribute(console, wAttr1);
				std::cout << " ";
			}
			SetConsoleTextAttribute(console, wAttr);
		}
	}
}


/* --------------------------------------------------------------------
* FUNCTION NAME: SortArray
* DESCRIPTION  : Sorts the combobox array alphabetically.
* RETURN       : None.
* NOTES        : Private Method
* -------------------------------------------------------------------- */
void ComboBox::SortArray(void)
{
	strVec tempVec;
	std::vector<std::string> sortMe;
	for (strVecItr itr1 = _comboNames.begin(); itr1 != _comboNames.end(); ++itr1) {
		sortMe.push_back(itr1->text);
	}
	std::sort(sortMe.begin(), sortMe.end());
	for (std::vector<std::string>::iterator itrstr = sortMe.begin(); itrstr != sortMe.end(); ++itrstr) {
		cmb temp;
		temp.index = tempVec.size();
		temp.text = *itrstr;
		tempVec.push_back(temp);
	}
	_comboNames = tempVec;
	_isSorted = true;
}

/* --------------------------------------------------------------------
* FUNCTION NAME: GetSize
* DESCRIPTION  : Gets the size of the combobox array.
* RETURN       : int - size of combobox array.
* NOTES        : None.
* -------------------------------------------------------------------- */
int ComboBox::GetSize() const
{
	return _comboNames.size();
}


/* --------------------------------------------------------------------
* FUNCTION NAME: Draw
* DESCRIPTION  : Draws Combobox on console, will check whether to draw
*				  One label or the entire combobox using _isOpen.
* RETURN       : None.
* NOTES        : Polymorphic function - inherited from Widget.
* -------------------------------------------------------------------- */
void ComboBox::Draw(COORD CursorPosition, const HANDLE& console)
{
	if (!_comboNames.size())
		return;
	if (!_isSorted) {
		SortArray();
	}
	strVecItr itr = _comboNames.begin();
	if (!_isOpen) {
		SetHeight(HEIGHT_OF_CELL);
		_isOpen = true;
		CursorPosition = GetCoord();
		CursorPosition.X--;
		clearWidget(CursorPosition, console, GetLongestString() + 6, _comboNames.size()*HEIGHT_OF_CELL);
		CursorPosition.X++;
		while (itr->index != _selected)
			itr++;
		DrawItem(CursorPosition, console, itr, true);
	}
	else {
		while (itr != _comboNames.end())
		{
			_isOpen = false;
			if (itr->index == _selected)
				DrawItem(CursorPosition, console, itr, true);
			else
				DrawItem(CursorPosition, console, itr, false);
			CursorPosition.Y += 2;
			++itr;
		}
	}
}


/* --------------------------------------------------------------------
* FUNCTION NAME: Draw_Color
* DESCRIPTION  : Draws Combobox on console, will be used to change color
*				  On hover
* RETURN       : None.
* NOTES        : Polymorphic function - inherited from Widget.
* -------------------------------------------------------------------- */
void ComboBox::Draw_Color(COORD CursorPosition,const HANDLE& console) {
	COORD t = { CursorPosition.X - 1,CursorPosition.Y };
	SetHeight(HEIGHT_OF_CELL*(_comboNames.size() - 2));
	CursorPosition.X--;
	clearWidget(CursorPosition, console, GetLongestString() + 6, _comboNames.size()*HEIGHT_OF_CELL);
	CursorPosition.X++;
	strVecItr itr = _comboNames.begin();
	
	while (itr != _comboNames.end())
	{
		
		_isOpen = false;
		if (itr->index == _current)
			DrawItem(CursorPosition, console, itr, true);
		else
			DrawItem(CursorPosition, console, itr, false);
		CursorPosition.Y += 2;
		++itr;
	}
}


/* --------------------------------------------------------------------
* FUNCTION NAME: MouseEvent
* DESCRIPTION  : Recives mouse event and check what to do.
* RETURN       : On Hover - DRAW_COLOR, On click - DRAW.
* NOTES        : Polymorphic function - inherited from Widget.
* -------------------------------------------------------------------- */
int ComboBox::MouseEvent(MOUSE_EVENT_RECORD& mer)
{
	COORD x = mer.dwMousePosition;
	if (CheckPosition(x))
	{
		if (mer.dwButtonState == 0 && !_isOpen) {
			int tmp = x.Y - GetY();
			tmp = static_cast<int>(tmp) / (HEIGHT_OF_CELL - 1);


			strVecItr itr = _comboNames.begin();
			while (itr != _comboNames.end())
			{
				if (itr->index == tmp)
				{
					_current = itr->index;
					return DRAW_COLOR;
				}
				++itr;
			}
		}
		else {
			int tmp = x.Y - GetY();
			tmp = static_cast<int>(tmp) / (HEIGHT_OF_CELL - 1);


			strVecItr itr = _comboNames.begin();
			while (itr != _comboNames.end())
			{
				if (itr->index == tmp)
				{
					if (!_isOpen)
						_selected = itr->index;
					return DRAW;
				}
				++itr;
			}
		}
	}

}


/* --------------------------------------------------------------------
* FUNCTION NAME: KeyboardEvent
* DESCRIPTION  : Recives Key event and check what to do.
* RETURN       : On ↑ or ↓ returns DRAW_COLOR, on enter returns DRAW.
* NOTES        : Polymorphic function - inherited from Widget.
* -------------------------------------------------------------------- */
int ComboBox::KeyboardEvent(const KEY_EVENT_RECORD& ker, COORD & currentLocation)
{

	if (ker.wVirtualKeyCode == VK_UP || ker.wVirtualKeyCode == 104)
	{
		if (_current != 0)
		{
			strVecItr itr = _comboNames.begin();
			while (itr != _comboNames.end())
			{
				if ((itr + 1)->index == _current)
				{
					_current = itr->index;
					return DRAW_COLOR;
				}
				itr++;
			}
		}
		else return NONE;
	}
	else if (ker.wVirtualKeyCode == VK_DOWN || ker.wVirtualKeyCode == 98)
	{
		if (_current != _comboNames.size() - 1)
		{
			_current++;
			return DRAW_COLOR;
		}
		else return NONE;
	}
	else if (ker.wVirtualKeyCode == VK_RETURN)
	{
		_selected = _current;
		return DRAW;
	}
	return 0;
}


/* --------------------------------------------------------------------
* FUNCTION NAME: CheckPosition
* DESCRIPTION  : Recives position of click and check if is in widget.
* RETURN       : True - if is in widget, false otherwise.
* NOTES        : Polymorphic function - inherited from Widget.
* -------------------------------------------------------------------- */
bool ComboBox::CheckPosition(COORD clickedPosition) const
{
	COORD tmp = GetCoord();
	if (!_isOpen) {
		int y = tmp.Y + (_comboNames.size() * HEIGHT_OF_CELL);
		int x = tmp.X + GetLongestString() + 6;
		if (y < clickedPosition.Y || tmp.Y > clickedPosition.Y)
			return false;
		if (x < clickedPosition.X || tmp.X > clickedPosition.X)
			return false;
	}
	else {
		int y = tmp.Y + 1;
		int x = tmp.X + GetLongestString() + 6;
		if (y < clickedPosition.Y || tmp.Y > clickedPosition.Y)
			return false;
		if (x < clickedPosition.X || tmp.X > clickedPosition.X)
			return false;
	}
	
	return true;
}

/* --------------------------------------------------------------------
* FUNCTION NAME: ~ComboBox
* DESCRIPTION  : Destructor, unused - no dynamic allocation to be freed.
* RETURN       : None.
* NOTES        : None.
* -------------------------------------------------------------------- */


bool ComboBox::GetOpenState(void) const
{
	return _isOpen;
}

ComboBox::~ComboBox()
{
}
