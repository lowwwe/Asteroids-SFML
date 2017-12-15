#include "Help.h"
#include "Game.h"
#include <iostream>


Help::Help()
{
	if (!m_backgroundTexture.loadFromFile("ASSETS\\IMAGES\\menu.jpg"))
	{
		std::cout << "problem with menu" << std::endl;
	}
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setPosition(0.0f, 0.0f);
}


Help::~Help()
{
}

void Help::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_backgroundSprite);
	t_window.draw(m_titleText);
	t_window.draw(m_page1Text);
	for (size_t i = 0; i < 4; i++)
	{
		t_window.draw(m_footerText[i]);
	}
	
}

void Help::update(sf::Time t_deltaTime, sf::RenderWindow & t_window)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (i == m_nextHelpPage)
		{
			m_footerText[i].setFillColor(sf::Color::Yellow);
		}
		else
		{
			m_footerText[i].setFillColor(sf::Color::White);
		}
	}
}

void Help::processEvents(sf::Event t_event)
{
	if (sf::Event::EventType::MouseMoved == t_event.type)
	{
		m_nextHelpPage = -1;
		if (t_event.mouseMove.y > 550)
		{
			if (t_event.mouseMove.x > 20 && t_event.mouseMove.x  <  200)
			{
				m_nextHelpPage = 0;
			}
			if (t_event.mouseMove.x  > 200 && t_event.mouseMove.x  < 380)
			{
				m_nextHelpPage = 1;
			}
			if (t_event.mouseMove.x  > 390 && t_event.mouseMove.x < 600)
			{
				m_nextHelpPage = 2;
			}
			if (t_event.mouseMove.x  > 610 && t_event.mouseMove.x  < 780)
			{
				m_nextHelpPage = 3;
			}
		}
	}
	if (sf::Event::EventType::MouseButtonReleased == t_event.type)
	{
		if (t_event.mouseMove.x > 750 && t_event.mouseMove.y < 50)
		{
			Game::s_currentGameState = GameState::Hub;
		}
		if (m_nextHelpPage != -1)
		{
			m_curretnPage = m_nextHelpPage;
		}
	}
}

void Help::initialise(sf::Font & t_font)
{
	m_font = t_font;
	setupText(m_titleText, "Help", { 350,50 });
	setupText(m_page1Text, "Use arrow keys to fly ship.\n<ctrl> to fire laser.\n<Alt> to hyperspace.\nShoot asteroids to find crystals\nUse tractor beam to collect.\nShoot Pirate to get scrap metal.\nFufill contracts to earn Space Credits.\nUpgrade ship to progress.", { 50,100 });
	setupText(m_footerText[0], "[Flying]" ,{ 20, 550 });
	setupText(m_footerText[1], "[Map]", { 210, 550 });
	setupText(m_footerText[2], "[Market]", { 390, 550 });
	setupText(m_footerText[3], "[Hanger]", { 610, 550 });
	
}

void Help::setupText(sf::Text & t_text, std::string t_string, sf::Vector2f t_position)
{
	t_text.setFont(m_font);
	t_text.setCharacterSize(28);
	t_text.setString(t_string);	
	t_text.setFillColor(sf::Color::White);
	t_text.setPosition(t_position);
}
