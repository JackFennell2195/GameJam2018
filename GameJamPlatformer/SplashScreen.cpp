#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
}


SplashScreen::~SplashScreen()
{
}

void SplashScreen::initialise(sf::Font & font)
{
	m_font = font;
	
	m_splashSprite.setTexture(m_splashTexture);
	m_splashSprite.setPosition(0, 0);
	sf::Vector2u textureSize = m_splashTexture.getSize();


	m_message.setFont(m_font);
	m_message.setString("Press the space bar to continue");
	m_message.setCharacterSize(40);
	m_message.setStyle(sf::Text::Bold);
	m_message.setFillColor(sf::Color::White);

	sf::FloatRect textSize = m_message.getGlobalBounds();
	float xposition = ScreenSize::s_width/ 2 - textSize.width / 2;
	m_message.setPosition(xposition, ScreenSize::s_height * 0.87f);
	m_proceedKeyPressed = false;
}

void SplashScreen::render(sf::RenderWindow & window)
{
	window.draw(m_splashSprite);
	window.draw(m_message);
}

void SplashScreen::processInput(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Space)
		{
			m_proceedKeyPressed = true;
		}
	}
}

void SplashScreen::update(sf::Time time)
{
	if (m_proceedKeyPressed)
	{

	}
	m_proceedKeyPressed = false;
}
