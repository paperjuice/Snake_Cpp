#include "Map.h"
#include "MainCharacter.h"



int main()
{
	bool isRunning = true;
	Map map;
	MainCharacter mc;


	

	while (isRunning)
	{
		map.Bounderies();
		map.Control();
		map.GenerateMap();
		Sleep(50);
		system("cls");
	}

	std::cin.ignore();
	return 0;
}

