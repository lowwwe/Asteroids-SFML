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
	if (!m_menuIconTexture.loadFromFile("ASSETS\\IMAGES\\menuicon.png"))
	{
		std::cout << "problem with menu" << std::endl;
	}
	m_menuIconSprite.setTexture(m_menuIconTexture);
	m_menuIconSprite.setPosition(750.0f, 5.0f);
}


Help::~Help()
{
}

void Help::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_backgroundSprite);
	t_window.draw(m_menuIconSprite);
	t_window.draw(m_titleText);
	switch (m_curretnPage)
	{
	case 0:
		t_window.draw(m_page1Text);
		break;
	case 1:
		t_window.draw(m_page2Text);
		break;
	case 2:
		t_window.draw(m_page3Text);
		break;
	case 3:
		t_window.draw(m_page4Text);
		break;
	default:
		break;
	}	
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
		if (t_event.mouseButton.x > 750 && t_event.mouseButton.y < 50)
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
	setupText(m_page2Text, "Use mouse to select a Planet or moon.\nView crystal data.\nExpected Pirate activity.\nClick to explore.\nTo unlock new planets succecfully complete\na mission to the previous planet.", { 50,100 });
	setupText(m_page3Text, "Available contracts displayed in white.\nSelect by clicking\nCredits added to your balance\nContracts with crystals you don't\nhave displayed in gray", { 50,100 });
	setupText(m_page4Text, "Use mouse to select by clicking\na part of the ship to upgrade.\nCurrent level displayed in white.\nCost in metal and credits\nGrayed out entries currently\nUnavailable", { 50,100 });
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
