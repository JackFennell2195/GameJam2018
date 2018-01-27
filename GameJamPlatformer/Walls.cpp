#include "Walls.h"

Walls::Walls()
{
	holePicker();
}

Walls::~Walls()
{
}

void Walls::render(sf::RenderWindow & window)
{
	for (int i = 0; i < 9; i++)
	{
		wall[i].render(window);
	}
}

void Walls::initialise()
{
	wall[0].block.setPosition(sf::Vector2f(1000, 0));
	wall[1].block.setPosition(sf::Vector2f(1000, 100));
	wall[2].block.setPosition(sf::Vector2f(1000, 200));
	wall[3].block.setPosition(sf::Vector2f(1000, 300));
	wall[4].block.setPosition(sf::Vector2f(1000, 400));
	wall[5].block.setPosition(sf::Vector2f(1000, 500));
	wall[6].block.setPosition(sf::Vector2f(1000, 600));
	wall[7].block.setPosition(sf::Vector2f(1000, 700));
	wall[8].block.setPosition(sf::Vector2f(1000, 800));
}

void Walls::holePicker()
{	// random hole in the wall, choses one and then the one below aswell
	srand((unsigned)time(0));
	randPicker = (rand() % 7) + 1;

	wall[randPicker].makeHole();
	wall[randPicker + 1].makeHole();
}