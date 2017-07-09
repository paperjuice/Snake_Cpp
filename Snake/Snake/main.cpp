#include "Map.h"


int main()
{
	Map map;
	int difficulty = 80;

	while (map.GetGameStatus())
	{
		map.LoseCondition();
		map.AutomaticMovement();
		map.CollectConsumables();
		map.Control();
		map.GenerateMap();
		Sleep(difficulty);
		system("cls");
	}

	std::cin.ignore();
	return 0;
}

