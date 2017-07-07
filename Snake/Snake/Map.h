#pragma once
#include <iostream>
#include <windows.h>


enum class ControlInput
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	EXIT = 0
};


class Map {
public:
	Map();
	void GenerateMap();
	void Control();
	void Bounderies();
	void AutomaticMovement();


protected:
	int GetMapWidth() { return mapWidth; }
	int GetMapHeight() { return mapHeight; }
	

private:
	int mapWidth = 20;
	int mapHeight = 20;

	int mcInitalPosX;
	int mcInitalPosY;


};
