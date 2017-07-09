#include "Menu.h"


Menu::Menu()
{

}

void Menu::MainMenuGraphics() const
{
	switch (menuOptions)
	{
	case MenuOptions::StartGame:
		cout << "####################" << endl;
		cout << "#                  #" << endl;
		cout << "#      SNAKE       #" << endl;
		cout << "#                  #" << endl;
		cout << "#                  #" << endl;
		cout << "#  >   START GAME  #" << endl;
		cout << "#                  #" << endl;
		cout << "#                  #" << endl;
		cout << "#                  #" << endl;
		cout << "#    EXIT          #" << endl;
		cout << "#                  #" << endl;
		cout << "#                  #" << endl;
		cout << "####################" << endl;
		break;
	case MenuOptions::Exit:
		cout << "####################" << endl;
		cout << "#                  #" << endl;
		cout << "#      SNAKE       #" << endl;
		cout << "#                  #" << endl;
		cout << "#                  #" << endl;
		cout << "#    START GAME    #" << endl;
		cout << "#                  #" << endl;
		cout << "#                  #" << endl;
		cout << "#                  #" << endl;
		cout << "#  >   EXIT        #" << endl;
		cout << "#                  #" << endl;
		cout << "#                  #" << endl;
		cout << "####################" << endl;
		break;

	}
}

void Menu::MainMenuBehaviour()
{
	if (_kbhit())
	{
		keyPressed = _getch();

		switch (keyPressed)
		{
		case 's':
			if (menuOptions == MenuOptions::StartGame)
				menuOptions = MenuOptions::Exit;
			break;
		case 'w':
			if (menuOptions == MenuOptions::Exit)
				menuOptions = MenuOptions::StartGame;
			break;
		}
	}
}

void Menu::StartGame()
{
	if (_kbhit())
	{
		if (menuOptions == MenuOptions::StartGame && _getch() == '\r')
		{
			isGameStarting = true;
		}
	}
	
 	if (_kbhit())
	{
		if (menuOptions == MenuOptions::Exit && _getch() == '\r')
		{
			//isGameRunning = false;
			exit(0);
		}
	}
}

void Menu::ShowScore()
{
	
	cout << "####################" << endl;
	cout << "#                  #" << endl;
	cout << "#      SCORE       #" << endl;
	cout << "#                  #" << endl;
	cout << "#                  #" << endl;
	cout << "#        " << map.GetScore() << "       #" << endl;
	cout << "#                  #" << endl;
	cout << "#                  #" << endl;
	cout << "#                  #" << endl;
	cout << "#  >   RETRY       #" << endl;
	cout << "#                  #" << endl;
	cout << "#                  #" << endl;
	cout << "####################" << endl;

	std::cin.ignore();
	system("cls");
	isGameStarting = false;
	map.SetGameStatus(true);
}