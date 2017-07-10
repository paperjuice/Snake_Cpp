#pragma once
#include "Map.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>

#define cout std::cout
#define endl std::endl



enum class MenuOptions
{
	StartGame,
	Exit
};

class Menu:public Map {

public:
	Menu();
	void MainMenuGraphics() const;
	void MainMenuBehaviour();
	void StartGame();

	void ShowScore(int score)const;

	bool GetStartGame() const { return isGameStarting; }
	bool GetIsGameRunning() const { return isGameRunning; }

private:
	MenuOptions menuOptions = MenuOptions::StartGame;
	bool isGameStarting = false;

	int keyPressed;
	bool isGameRunning = true;


};

