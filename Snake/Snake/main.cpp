#include "Map.h"



int main()
{
	bool isRunning = true;
	Map map;


	while (isRunning)
	{
		map.GenerateMap();
	}

	std::cin.ignore();
	return 0;
}

