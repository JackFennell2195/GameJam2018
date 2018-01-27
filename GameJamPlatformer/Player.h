#pragma once
#include<SFML\Graphics.hpp>

const float PIXELTOMETER = 50.0;
const sf::Vector2f GRAVITY(0.0f, 9.8f * PIXELTOMETER);

class Player
{
public:
	Player();
	~Player();
	
	void update(sf::Time t_deltaTime);

	void setPosition(sf::Vector2f pos);

	void gravity();

	void render(sf::RenderWindow &window);

	bool colliosn(sf::RectangleShape object);

private:
	sf::RectangleShape player;
	sf::RectangleShape ground;
	sf::RectangleShape roof;

	sf::Vector2f position;
	sf::Vector2f g_position;
	sf::Vector2f r_position;
	sf::Vector2f velocity;

	sf::Vector2f acceleration;
	sf::Vector2f coeffFriction;
	sf::Vector2f unitVelocity;
	
	bool alive;
	bool onGround;
};

