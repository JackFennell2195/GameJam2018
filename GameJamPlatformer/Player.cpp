#include "Player.h"

Player::Player()
{
	position = sf::Vector2f(350, 450);

	player.setSize(sf::Vector2f(50, 50));
	player.setFillColor(sf::Color::Red);
	player.setPosition(position);
	alive = true;
}

Player::~Player()
{
}

void Player::update(sf::Time t_deltaTime)
{
	acceleration = GRAVITY;
	/*if (colliosn(floor) == false)
		acceleration = GRAVITY;

	if (colliosn(floor) == true)
	{
		acceleration = sf::Vector2f(0, 0);
		position.y = 450;
	}

	if ((colliosn(block) == true) && ((position.y + player.getSize().y) > block.getPosition().y))
	{
		acceleration = sf::Vector2f(0, 0);
		position.y = 400;
	}*/

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		velocity.y -= 23.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (velocity.x >= -400)
			velocity.x -= (2 * PIXELTOMETER);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (velocity.x <= 400)
			velocity.x += (2 * PIXELTOMETER);
	}

	position = position + velocity * t_deltaTime.asSeconds() + 0.5f * acceleration * (t_deltaTime.asSeconds() * t_deltaTime.asSeconds());
	velocity = velocity + acceleration * t_deltaTime.asSeconds();

	player.setPosition(position);
}

void Player::setPosition(sf::Vector2f pos)
{
	position = pos;
}

void Player::gravity()
{
	acceleration = GRAVITY;
}

void Player::render(sf::RenderWindow &window)
{
	window.draw(player);
}

bool Player::colliosn(sf::RectangleShape object)
{
	if (player.getGlobalBounds().intersects(object.getGlobalBounds()))
		return true;
	else
		return false;
} 