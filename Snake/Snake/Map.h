#pragma once
#include <iostream>
#include <windows.h>




class Map {
public:
	Map();
	void GenerateMap();

protected:
	int GetMapWidth() { return mapWidth; }
	int GetMapHeight() { return mapHeight; }
	

private:
	int mapWidth = 20;
	int mapHeight = 20;

};
