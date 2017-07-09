#pragma once
#include <iostream>
#include <windows.h>
#include <vector>


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
	~Map() { delete score; }
	void GenerateMap() ;
	void Control();
	void Bounderies();
	void AutomaticMovement();
	Coordinates RandomXandY(int maxHeight, int maxWidth);
	void CollectConsumables();
	void TailBehaviour();

	void LoseCondition();

	int GetScore() const { return *score; }

	void CleanStart();

	bool GetGameStatus() const { return isGameRunning; }
	void SetGameStatus(bool gameStatus) { isGameRunning = gameStatus; }

protected:
	int GetMapWidth() { return mapWidth; }
	int GetMapHeight() { return mapHeight; }
	

private:
	//score
	int* score = new int;

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

	// tail
	std::vector<int> tPosX;
	std::vector<int> tPosY;


	bool isGameRunning = true;
};
