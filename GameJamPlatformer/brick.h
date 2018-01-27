#pragma once
#include<SFML\Graphics.hpp>

class brick
{
public:
	brick();
	~brick();

	void makeHole();

	void render(sf::RenderWindow &window);

	sf::RectangleShape block;
	
	int m_type;
	bool m_active;

};

