#include "MainMenu.h"
#include <iostream>
#include "ScreenSize.h"


MainMenu::MainMenu()
{
}


MainMenu::~MainMenu()
{
}

void MainMenu::initialise(sf::Font & font)
{
	m_font = font;
	if (!m_mainMenuTexture.loadFromFile("ASSETS/IMAGES/menu.png"))
	{
		std::cout << "error with menu file" << std::endl;
	}
	m_mainMenuSprite.setTexture(m_mainMenuTexture);
	m_mainMenuSprite.setPosition(0, 0);
	sf::Vector2u textureSize = m_mainMenuTexture.getSize();

	m_topOffset = 50;
	m_verticalSpacing = 128;
	m_buttonWidth = 200;
	m_leftOffset = (ScreenSize::s_width - m_buttonWidth) / 2;
	m_buttonHeight = 75;
	int textDropOffset = 10;
	sf::String m_menuTexts[] = { "Play", "Quit" };

	if (!m_buttonTexture.loadFromFile("ASSETS/FONTS/gamesprites/button.png"))
	{
		std::cout << "error with button file" << std::endl;
	}
	for (int i = 0; i < m_optionCount; i++)
	{
		m_buttonSprite[i].setTexture(m_buttonTexture);
		m_buttonSprite[i].setPosition(m_leftOffset, m_verticalSpacing*i + m_topOffset);
		sf::Vector2u textureSize = m_buttonTexture.getSize();
		m_buttonSprite[i].setScale(m_buttonWidth / textureSize.x, m_buttonHeight / textureSize.y);

		m_buttonText[i].setFont(m_font);
		m_buttonText[i].setString(m_menuTexts[i]);
		m_buttonText[i].setFillColor(sf::Color::White);
		m_buttonText[i].setCharacterSize(26);
		sf::FloatRect textSize = m_buttonText[i].getGlobalBounds();
		float textOffset = (m_buttonWidth - textSize.width) / 2;
		m_buttonText[i].setPosition(m_leftOffset + textOffset, m_verticalSpacing*i + m_topOffset + textDropOffset);
	}
}

void MainMenu::render(sf::RenderWindow & window)
{
	window.draw(m_mainMenuSprite);

	for (int i = 0; i < m_optionCount; i++)
	{
		window.draw(m_buttonSprite[i]);
		window.draw(m_buttonText[i]);
	}
}

void MainMenu::update(sf::Time time, sf::Window & window )
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		sf::Vector2i mouseLocation;
		mouseLocation = sf::Mouse::getPosition(window);
		if (mouseLocation.x > m_leftOffset && mouseLocation.x < m_leftOffset + m_buttonWidth)
		{
			if (mouseLocation.y > m_topOffset && mouseLocation.y < m_topOffset + m_buttonHeight)
			{

			}
			if (mouseLocation.y > m_topOffset + m_verticalSpacing && mouseLocation.y < m_topOffset + m_verticalSpacing + m_buttonHeight)
			{
				window.close();
			}
		}
	}
}
