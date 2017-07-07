#include "Map.h"
#include <time.h>
#include <conio.h>

#define cout std::cout
#define endl std::endl

Map::Map()
{


	srand(time(NULL));
	mcInitalPosY = rand() % GetMapHeight() - 1 + 1;
	mcInitalPosX = rand() % GetMapWidth() - 1 + 1;
}


void Map::GenerateMap()
{
	for (int i = 0; i != mapWidth; i++)
	{
		for (int j = 0; j != mapHeight; j++)
		{
			if (i == mcInitalPosY && j == mcInitalPosX)
			{
				cout << "@";
			}
			else if (i == 0 )
			{
				cout << "#";
			}
			else if (j == mapHeight-1)
			{
				cout << "#";
			}else if (j == 0 && i != 0)
			{
				cout << endl<<"#";
			}
			else if (i == mapWidth - 1)
			{
				cout << "#";
			}
			else
			{
				cout << ".";
			}
		}
	}
}


void Map::Control()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			mcInitalPosX--;
			break;
		case 'd':
			mcInitalPosX++;
			break;
		case 'w':
			mcInitalPosY--;
			break;
		case 's':
			mcInitalPosY++;
			break;
		}
	}
}


void Map::Bounderies()
{
	if (mcInitalPosY > GetMapHeight()-2)
	{
		mcInitalPosY = 1;
	}
	if (mcInitalPosY < 1)
	{
		mcInitalPosY = GetMapHeight() - 2;
	}
	if (mcInitalPosX < 1)
	{
		mcInitalPosX = GetMapWidth() - 2;
	}
	if (mcInitalPosX > GetMapWidth()-2)
	{
		mcInitalPosX = 1;
	}
}

