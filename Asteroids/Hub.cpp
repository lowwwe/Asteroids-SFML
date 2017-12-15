#include "Hub.h"
#include <iostream>
#include "Game.h"



Hub::Hub()
{
	if (!m_backgroundTexture.loadFromFile("ASSETS\\IMAGES\\menu.jpg"))
	{
		std::cout << "problem with menu" << std::endl;
	}
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setPosition(0.0f, 0.0f);
}


Hub::~Hub()
{
}

void Hub::render(sf::RenderWindow & window)
{
	window.draw(m_backgroundSprite);
	window.draw(m_mapText);
	window.draw(m_hangerText);
	window.draw(m_marketText);
	window.draw(m_helpText);
}

void Hub::update(sf::Time deltaTime, sf::RenderWindow &window)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	m_mapText.setFillColor(sf::Color::White);
	m_hangerText.setFillColor(sf::Color::White);
	m_marketText.setFillColor(sf::Color::White);
	m_helpText.setFillColor(sf::Color::White);
	m_currentRegion = HubRegion::None;
	if (mousePosition.y < 400)
	{
		if (mousePosition.x > 370)
		{
			if (mousePosition.y > 200)
			{
				m_helpText.setFillColor(sf::Color::Yellow);
				m_currentRegion = HubRegion::Help;
			}
			else
			{
				m_hangerText.setFillColor(sf::Color::Yellow);
				m_currentRegion = HubRegion::Hanger;
			}
		}
		else
		{
			if (mousePosition.y > 200)
			{
				m_marketText.setFillColor(sf::Color::Yellow);
				m_currentRegion = HubRegion::Market;
			}
			else
			{
				m_mapText.setFillColor(sf::Color::Yellow);
				m_currentRegion = HubRegion::Map;
			}
		}
	}
}

void Hub::processEvents(sf::Event event)
{
	if (sf::Event::EventType::MouseButtonPressed == event.type)
	{
		switch (m_currentRegion)
		{
		case HubRegion::Hanger:
			Game::s_currentGameState = GameState::Hanger;
			break;
		case HubRegion::Map:
			Game::s_currentGameState = GameState::Map;
			break;
		case HubRegion::Market:
			Game::s_currentGameState = GameState::Market;
			break;
		case HubRegion::Help:
			Game::s_currentGameState = GameState::Help;
			break;		
		}
	}
}

void Hub::initialise(sf::Font & font)
{
	m_font = font;
	setupText(m_mapText, "MAP", { 150,100 });
	setupText(m_hangerText, "HANGER", { 500,100 });
	setupText(m_marketText, "MARKET", { 150,300 });
	setupText(m_helpText, "HELP", { 500,300 });
}
void  Hub::setupText(sf::Text &text, std::string string, sf::Vector2f position)
{
	text.setFont(m_font);
	text.setCharacterSize(24);
	text.setString(string);
	text.setFillColor(sf::Color::White);
	text.setPosition(position);
}
