#include "Hub.h"
#include <iostream>
#include "Game.h"

void setupText(sf::Font &font, sf::Text &text, std::string string, sf::Vector2f position);

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
	m_mapText.setColor(sf::Color::White);
	m_hangerText.setColor(sf::Color::White);
	m_marketText.setColor(sf::Color::White);
	m_helpText.setColor(sf::Color::White);
	m_currentRegion = HubRegion::None;
	if (mousePosition.y < 400)
	{
		if (mousePosition.x > 370)
		{
			if (mousePosition.y > 200)
			{
				m_helpText.setColor(sf::Color::Yellow);
				m_currentRegion = HubRegion::Help;
			}
			else
			{
				m_hangerText.setColor(sf::Color::Yellow);
				m_currentRegion = HubRegion::Hanger;
			}
		}
		else
		{
			if (mousePosition.y > 200)
			{
				m_marketText.setColor(sf::Color::Yellow);
				m_currentRegion = HubRegion::Market;
			}
			else
			{
				m_mapText.setColor(sf::Color::Yellow);
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
	setupText(font, m_mapText, "MAP", { 150,100 });
	setupText(font, m_hangerText, "HANGER", { 500,100 });
	setupText(font, m_marketText, "MARKET", { 150,300 });
	setupText(font, m_helpText, "HELP", { 500,300 });
}
void setupText(sf::Font &font, sf::Text &text, std::string string, sf::Vector2f position)
{
	text.setFont(font);
	text.setCharacterSize(24);
	text.setString(string);
	text.setColor(sf::Color::White);
	text.setPosition(position);
}
