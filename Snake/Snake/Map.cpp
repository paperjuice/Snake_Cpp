#include "Map.h"
#define cout std::cout
#define endl std::endl

Map::Map()
{

}


void Map::GenerateMap()
{
	for (int i = 0; i != mapWidth; i++)
	{
		for (int j = 0; j != mapHeight; j++)
		{
			if (i == 0 )
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
				cout << " ";
			}
		}
	}


	Sleep(500);
	system("cls");
}
