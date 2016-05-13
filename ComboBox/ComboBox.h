/***************************************************************************
*                                                                          *
* FILE NAME:   ComboBox.h                                                  *
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

#pragma once


#include "../Widget/Widget.h"
#include "../ConsoleEventHandler/ConsoleEventHandler.h"
#include <vector>
#include <string>
#include <algorithm>


/*=========================================*
*           P A R A M E T E R S           *
*=========================================*/
#define HEIGHT_OF_CELL 3

/*=========================================*
*          D E F I N I T I O N S          *
*=========================================*/

#define strVec std::vector<cmb> 
#define strVecItr std::vector<cmb>::iterator 


typedef struct CMB {
	std::string text;
	int index;

}cmb;

class ComboBox : public Widget
{
private:
	strVec _comboNames;  // formación para salvar strings y index
	int _current;		 // cual string es corriente - para mostrar cuando el ComboBox esta cerrado
	bool _isOpen;		 // es comboBox esta cerrado o abbierto
	bool _isSorted;
	int _selected;


	/*=========================================*
	*  F U N C T I O N   P R O T O T Y P E S  *
	*=========================================*/


	/* --------------------------------------------------------------------
	* FUNCTION NAME: GetLongestString
	* DESCRIPTION  : Returns the longest string size in ComboBox array.
	* RETURN       : Int - longest string size
	* NOTES        : Private Method
	* -------------------------------------------------------------------- */
	int GetLongestString() const;

	/* --------------------------------------------------------------------
	* FUNCTION NAME: DrawItem
	* DESCRIPTION  : Draws one item on console.
	* RETURN       : None.
	* NOTES        : Private Method
	* -------------------------------------------------------------------- */
	void DrawItem(COORD CursorPosition,		 /* Current cursor position */
		const HANDLE& console,	 /* Current console handle  */
		strVecItr itr,			 /* Iterator of of current item in combobox array to draw */
		const bool& focusFlag		 /* Is focused? */
		) const;

	/* --------------------------------------------------------------------
	* FUNCTION NAME: SortArray
	* DESCRIPTION  : Sorts the combobox array alphabetically.
	* RETURN       : None.
	* NOTES        : Private Method
	* -------------------------------------------------------------------- */
	void SortArray(void);


public:

	/* --------------------------------------------------------------------
	* FUNCTION NAME: Constructor
	* DESCRIPTION  : Creates a ComboBox object.
	* RETURN       : None.
	* NOTES        : None.
	* -------------------------------------------------------------------- */
	ComboBox(int x,								/* X position to draw combobox */
		int y,								/* y position to draw combobox */
		std::vector<std::string> labels	/* Vector of strings - labels for combobox. will be sorted alphabetically O(n log(n)) */
		);

	/* --------------------------------------------------------------------
	* FUNCTION NAME: Add
	* DESCRIPTION  : Adds a label to the ComboBox object.
	* RETURN       : None.
	* NOTES        : None.
	* -------------------------------------------------------------------- */
	void Add(const std::string&);

	/* --------------------------------------------------------------------
	* FUNCTION NAME: Delete
	* DESCRIPTION  : Delets a label from the ComboBox object using index.
	* RETURN       : None.
	* NOTES        : None.
	* -------------------------------------------------------------------- */
	void Delete(const int & index);


	/* --------------------------------------------------------------------
	* FUNCTION NAME: Delete
	* DESCRIPTION  : Delets a label from the ComboBox object searching a string.
	* RETURN       : None.
	* NOTES        : None.
	* -------------------------------------------------------------------- */
	void Delete(const std::string & toDelete);


	/* --------------------------------------------------------------------
	* FUNCTION NAME: GetSize
	* DESCRIPTION  : Gets the size of the combobox array.
	* RETURN       : int - size of combobox array.
	* NOTES        : None.
	* -------------------------------------------------------------------- */
	int GetSize() const;

	/* --------------------------------------------------------------------
	* FUNCTION NAME: Draw
	* DESCRIPTION  : Draws Combobox on console, will check whether to draw
	*				  One label or the entire combobox using _isOpen.
	* RETURN       : None.
	* NOTES        : Polymorphic function - inherited from Widget.
	* -------------------------------------------------------------------- */
	void Draw(COORD CursorPosition, const HANDLE& console);

	/* --------------------------------------------------------------------
	* FUNCTION NAME: Draw_Color
	* DESCRIPTION  : Draws Combobox on console, will be used to change color
	*				  On hover
	* RETURN       : None.
	* NOTES        : Polymorphic function - inherited from Widget.
	* -------------------------------------------------------------------- */
	void Draw_Color(COORD CursorPosition, const HANDLE& console);

	/* --------------------------------------------------------------------
	* FUNCTION NAME: MouseEvent
	* DESCRIPTION  : Recives mouse event and check what to do.
	* RETURN       : On Hover - DRAW_COLOR, On click - DRAW.
	* NOTES        : Polymorphic function - inherited from Widget.
	* -------------------------------------------------------------------- */
	int MouseEvent(MOUSE_EVENT_RECORD& mer);

	/* --------------------------------------------------------------------
	* FUNCTION NAME: KeyboardEvent
	* DESCRIPTION  : Recives Key event and check what to do.
	* RETURN       : On ↑ or ↓ returns DRAW_COLOR, on enter returns DRAW.
	* NOTES        : Polymorphic function - inherited from Widget.
	* -------------------------------------------------------------------- */
	int KeyboardEvent(const KEY_EVENT_RECORD& ker, COORD& currentLocation);

	/* --------------------------------------------------------------------
	* FUNCTION NAME: CheckPosition
	* DESCRIPTION  : Recives position of click and check if is in widget.
	* RETURN       : True - if is in widget, false otherwise.
	* NOTES        : Polymorphic function - inherited from Widget.
	* -------------------------------------------------------------------- */
	bool CheckPosition(COORD clickedPosition) const;

	/* --------------------------------------------------------------------
	* FUNCTION NAME: ~ComboBox
	* DESCRIPTION  : Destructor, unused - no dynamic allocation to be freed.
	* RETURN       : None.
	* NOTES        : None.
	* -------------------------------------------------------------------- */
	bool GetOpenState(void) const;
	~ComboBox();
};

