#pragma once
#include <SFML\Graphics.hpp>


class MainMenu
{
public:
	MainMenu();
	~MainMenu();
	void initialise(sf::Font&);
	void render(sf::RenderWindow&);
	void update(sf::Time, sf::Window&);

private:
	static const int m_optionCount = 2;
	sf::Texture m_mainMenuTexture;
	sf::Sprite m_mainMenuSprite;
	sf::Texture m_buttonTexture;
	sf::Sprite m_buttonSprite[m_optionCount];
	sf::Font m_font;
	sf::Text m_buttonText[m_optionCount];

	float m_topOffset;
	float m_leftOffset;
	float m_verticalSpacing;
	float m_buttonWidth;
	float m_buttonHeight;
};

