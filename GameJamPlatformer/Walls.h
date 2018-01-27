#pragma once
#include<SFML\Graphics.hpp>
#include <cstdlib> 
#include <ctime> 
#include"brick.h"

class Walls
{
public:
	Walls();
	~Walls();

	void render(sf::RenderWindow &window);
	void initialise();

	void holePicker();
	brick wall[9];
	int randPicker;
};

