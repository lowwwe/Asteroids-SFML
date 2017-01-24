#include "Logo.h"
#include <iostream>
#include "Game.h"



Logo::Logo()
{
	
}


Logo::~Logo()
{
}

void Logo::render(sf::RenderWindow & window)
{
	window.draw(m_liceince);
}

void Logo::update(sf::Time deltaTime)
{
	m_delayTimer += deltaTime;
	if (m_delayTimer.asSeconds() > 2.5)
	{
		Game::s_currentGameState = GameState::Splash;
	}
}

void Logo::processEvents()
{
}

void Logo::initialise(sf::Font & font)
{
	m_font = font;
	m_liceince.setFont(font);
	m_liceince.setString("HameMade by Pete");
	m_liceince.setCharacterSize(24);
	m_liceince.setColor(sf::Color::White);

	sf::FloatRect textSize = m_liceince.getGlobalBounds();
	float xPosition = 400 - textSize.width / 2;
	m_liceince.setPosition(xPosition, 290.0f);
}
