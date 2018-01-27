#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Walls.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "ScreenSize.h"

enum class
	GameState
{
	None,
	Splash,
	MainMenu,
	Game
};

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

	static GameState currentState;

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	sf::RenderWindow m_window; // main SFML window

	bool m_exitGame; // control exiting game

	Player player1;

	Walls wall;

	SplashScreen splash;
	MainMenu menu;
};

#endif // !GAME