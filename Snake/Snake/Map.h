#pragma once
#include <iostream>
#include <windows.h>


#define cout std::cout
#define endl std::endl

class Map {
public:
	Map();
	void GenerateMap();

private:
	int mapWidth = 20;
	int mapHeight = 10;



};
