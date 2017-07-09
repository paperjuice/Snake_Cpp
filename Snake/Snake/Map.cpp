#include "Map.h"
#include <time.h>
#include <conio.h>
#include <chrono>

#define cout std::cout
#define endl std::endl

Map::Map(): autoMovementDirectionVar(AutoMovementDirection::IDLE)
{
	srand(static_cast<unsigned int>(time(nullptr)));

	Coordinates mcRandCoord = Map::RandomXandY(GetMapHeight(), GetMapWidth());
	Coordinates consRandCoord = Map::RandomXandY(GetMapHeight(), GetMapWidth());

	mcInitalPosX = mcRandCoord.x;
	mcInitalPosY = mcRandCoord.y;


	consumablePosX = consRandCoord.x;
	consumablePosY = consRandCoord.y;


	//tail
	tPosX.push_back(mcInitalPosX);
	tPosY.push_back(mcInitalPosY);
}


Coordinates Map::RandomXandY(int maxHeight, int maxWidth)
{
	int randomX = rand() % (maxHeight - 2) + 1;
	int randomY = rand() % (maxWidth - 2) + 1;

	return { randomX, randomY };
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
			else if (i == consumablePosY && j == consumablePosX)
			{
				cout << "C";
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
				bool trigger = false;
				for (int a = 1; a != tPosX.size(); a++)
				{
					if (tPosY[a] == i && tPosX[a] == j && tPosX.size()>1)
					{
						cout << "x";
						trigger = true;
					}
				}
				if (!trigger)
				{
					cout << ".";
				}
			}
		}
	}
	cout << endl;
	cout << "Score: "<< tPosX.size()-1 << endl;
	
}


void Map::Control() 
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			autoMovementDirectionVar = AutoMovementDirection::LEFT;
			break;
		case 'd':
			autoMovementDirectionVar = AutoMovementDirection::RIGHT;
			break;
		case 'w':
			autoMovementDirectionVar = AutoMovementDirection::DOWN;
			break;
		case 's':
			autoMovementDirectionVar = AutoMovementDirection::UP;
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

void Map::AutomaticMovement()
{
	tPosX[0] = mcInitalPosX;
	tPosY[0] = mcInitalPosY;

	switch (autoMovementDirectionVar)
	{
	case AutoMovementDirection::UP:
		mcInitalPosY++;
		break;
	case AutoMovementDirection::DOWN:
		mcInitalPosY--;
		break;
	case AutoMovementDirection::LEFT:
		mcInitalPosX--;
		break;
	case AutoMovementDirection::RIGHT:
		mcInitalPosX++;
		break;
	default:
		break;
	}

	TailBehaviour();
}

void Map::CollectConsumables()
{
	if (mcInitalPosX == consumablePosX && mcInitalPosY == consumablePosY)
	{
		Coordinates consRandCoord = Map::RandomXandY(GetMapHeight(), GetMapWidth());
		consumablePosX = consRandCoord.x;
		consumablePosY = consRandCoord.y;

		score += 10;


		tPosX.push_back(0);
		tPosY.push_back(0);
	}
}



void Map::TailBehaviour()
{
	int tempX;
	int tempY;

	if (tPosX.size() > 1)
	{
		for (int a = 1; a != tPosX.size(); a++)
		{
			tempX = tPosX[a];
			tempY = tPosY[a];

			tPosX[a] = tPosX[a-1];
			tPosY[a] = tPosY[a - 1];

			tPosX[a - 1] = tempX;
			tPosY[a - 1] = tempY;
		}
	}
}

void Map::LoseCondition()
{
	for (int a = 1; a != tPosX.size(); a++)
	{
		if (mcInitalPosX == tPosX[a] && mcInitalPosY == tPosY[a])
		{
			isGameRunning = false;
		}
	}

	if (mcInitalPosY > GetMapHeight() - 2 || mcInitalPosY < 1 || mcInitalPosX < 1|| mcInitalPosX > GetMapWidth() - 2)
	{
		isGameRunning = false;
	}
}

