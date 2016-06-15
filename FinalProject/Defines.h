#pragma once
#define DEFAULT_HEIGHT 2
#define MessageBox MyMessageBox
#include "MeathodsExceptions.h"

enum class Color
{
	Black,
	Blue,
	Green,
	Red,
	Cyan,
	Purple,
	Orange,
	White
};

enum class BoxType
{
	CheckList,
	RadioBox
};

enum class BorderType
{
	None,
	Single,
	Double
};

enum class MessageBoxReturn
{
	OK,
	Cancel
};
