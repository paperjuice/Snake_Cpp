#pragma once
#include <iostream>
#include <windows.h>


enum class AutoMovementDirection
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	IDLE
};

struct Coordinates
{
	int x;
	int y;
};


class Map {
public:
	Map();
	void GenerateMap() const;
	void Control();
	void Bounderies();
	void AutomaticMovement();

	Coordinates RandomXandY(int maxHeight, int maxWidth);

	void CollectConsumables();


protected:
	int GetMapWidth() { return mapWidth; }
	int GetMapHeight() { return mapHeight; }
	

private:
	//score
	int score = 0;

	//map dimensions
	int mapWidth = 20;
	int mapHeight = 20;

	//mc position
	int mcInitalPosX;
	int mcInitalPosY;
	
	//enum initialization
	AutoMovementDirection autoMovementDirectionVar;

	//consumable position
	int consumablePosX;
	int consumablePosY;


};
