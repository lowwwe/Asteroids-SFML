#include "Splash.h"
#include <iostream>
#include "Game.h"


Splash::Splash()
{
	if (!m_backgroundTexture.loadFromFile("ASSETS\\IMAGES\\SPLASH.jpg"))
	{
		std::cout << "problem with splash" << std::endl;
	}
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setPosition(0.0f, 0.0f);
}


Splash::~Splash()
{
}

void Splash::render(sf::RenderWindow & window)
{
	window.draw(m_backgroundSprite);
}

void Splash::update(sf::Time deltaTime)
{
}

void Splash::processEvents(sf::Event event)
{
	if (sf::Event::EventType::KeyPressed == event.type)
	{
		Game::s_currentGameState = GameState::Hub;
	}
	if (sf::Event::EventType::MouseButtonPressed == event.type)
	{
		Game::s_currentGameState = GameState::Hub;
	}
}
