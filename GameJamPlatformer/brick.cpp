#include "brick.h"

brick::brick()
{
	m_active = true;	//is it in use on screen? 

	block.setSize(sf::Vector2f(100, 100));
	block.setFillColor(sf::Color::Blue);
}

brick::~brick()
{
}

void brick::makeHole()
{ 
	m_active = false;
}

void brick::render(sf::RenderWindow & window)
{
	if (m_active)
	window.draw(block);
}
