#include "Map.h"
#include "Menu.h"


int main()
{
	Menu menu;
	Map map;
	int difficulty = 80;

	while (menu.GetIsGameRunning())
	{
		map.CleanStart();

		while (!menu.GetStartGame() )
		{
			menu.StartGame();
			menu.MainMenuGraphics();
			menu.MainMenuBehaviour();
			Sleep(10);
			system("cls");
		}

		map.SetGameStatus(true);

		while (map.GetGameStatus())
		{
			map.LoseCondition();
			map.AutomaticMovement();
			map.CollectConsumables();
			map.Control();
			map.GenerateMap();
			Sleep(difficulty);
			system("cls");
		}

		menu.ShowScore();
	}

	return 0;
}

