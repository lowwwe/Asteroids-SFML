#include "Market.h"
#include "Game.h"
#include <iostream>



Market::Market()
{
	if (!m_backgroundTexture.loadFromFile("ASSETS\\IMAGES\\menu.jpg"))
	{
		std::cout << "problem with menu" << std::endl;
	}
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setPosition(0.0f, 0.0f);
	if (!m_menuIconTexture.loadFromFile("ASSETS\\IMAGES\\menuicon.png"))
	{
		std::cout << "problem with menu" << std::endl;
	}
	m_menuIconSprite.setTexture(m_menuIconTexture);
	m_menuIconSprite.setPosition(750.0f, 5.0f);
}


Market::~Market()
{
}

void Market::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_backgroundSprite);
	t_window.draw(m_menuIconSprite);
	t_window.draw(m_titleText);
}

void Market::update(sf::Time t_deltaTime, sf::RenderWindow & t_window)
{
}

void Market::processEvents(sf::Event t_event)
{
	if (sf::Event::EventType::MouseButtonReleased == t_event.type)
	{
		if (t_event.mouseButton.x > 750 && t_event.mouseButton.y < 50)
		{
			Game::s_currentGameState = GameState::Hub;
		}
	}
}

void Market::initialise(sf::Font & t_font)
{
	m_font = t_font;
	setupText(m_titleText, "Market", { 350,50 });
}

void Market::setupText(sf::Text & t_text, std::string t_string, sf::Vector2f t_position)
{
	t_text.setFont(m_font);
	t_text.setCharacterSize(24);
	t_text.setString(t_string);
	t_text.setFillColor(sf::Color::White);
	t_text.setPosition(t_position);
}
