#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "ScreenSize.h"

class SplashScreen
{
public:
	SplashScreen();
	~SplashScreen();

	void initialise(sf::Font&);
	void render(sf::RenderWindow&);
	void processInput(sf::Event);
	void update(sf::Time);

private:

	sf::Texture m_splashTexture;
	sf::Sprite m_splashSprite;
	sf::Font m_font;
	sf::Text m_message;
	bool m_proceedKeyPressed;
};

