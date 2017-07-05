#include "Map.h"
#include "MainCharacter.h"



int main()
{
	bool isRunning = true;
	Map map;
	MainCharacter mc;


	mc.SpawnInScene();
/*
	while (isRunning)
	{
		map.GenerateMap();
	}
*/
	std::cin.ignore();
	return 0;
}

