#pragma once
#include "../ConsoleEventHandler/ConsoleEventHandler.h"

class ConsoleSingleton
{
	static ConsoleEventHandler* _instance;
	ConsoleSingleton();
	ConsoleSingleton(ConsoleSingleton& c);
	ConsoleSingleton& operator=(const ConsoleSingleton& c);
public:
	static ConsoleEventHandler* GetInstance();
	inline ~ConsoleSingleton() {}

};

