#include "Map.h"


int main()
{
	bool isRunning = true;
	Map map;
	int difficulty = 80;

	while (isRunning)
	{
		map.AutomaticMovement();
		map.CollectConsumables();
		map.Bounderies();
		map.Control();
		map.GenerateMap();
		Sleep(difficulty);
		system("cls");
	}

	std::cin.ignore();
	return 0;
}

