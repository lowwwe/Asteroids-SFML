#include "Hanger.h"
#include "Game.h"


Hanger::Hanger()
{
	if (!m_backgroundTexture.loadFromFile("ASSETS\\IMAGES\\menu.jpg"))
	{
		std::cout << "problem with menu" << std::endl;
	}
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setPosition(0.0f, 0.0f);
	if (!m_shipTexture.loadFromFile("ASSETS\\IMAGES\\ship0.png"))
	{
		std::cout << "problem with menu" << std::endl;
	}
	m_shipSprite.setTexture(m_shipTexture);
	m_shipSprite.setPosition(OFFSET_SHIP_X, OFFSET_SHIP_Y);
	if (!m_menuTexture.loadFromFile("ASSETS\\IMAGES\\menuicon.png"))
	{
		std::cout << "problem with gems" << std::endl;
	}
	m_menuSprite.setTexture(m_menuTexture);
	m_menuSprite.setPosition({ 750, 18 }); 
	if (!m_gemsTexture.loadFromFile("ASSETS\\IMAGES\\gems.png"))
	{
		std::cout << "problem with gems" << std::endl;
	}
	m_gemsSprite.setTexture(m_gemsTexture);
	m_gemsSprite.setTextureRect(sf::IntRect{ 160,0,32,32 });
	m_gemsSprite.setPosition(sf::Vector2f{ OFFSET_LEVEL_X  , OFFSET_LEVEL_Y + 340.0f });
}


Hanger::~Hanger()
{
}

void Hanger::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_backgroundSprite);
	t_window.draw(m_shipSprite);
	t_window.draw(m_menuSprite);
	t_window.draw(m_money);
	t_window.draw(m_material);
	t_window.draw(m_gemsSprite);
	if (m_currentArea != ShipArea::None)
	{
		int current = static_cast<int>(m_currentArea);
		m_title.setString(m_names[current]);
		for (int i = 0; i < 3; i++)
		{
			if (Game::s_credits < m_upgradeCost[current][i]
				|| Game::s_gems[5] < m_upgradeMaterial[current][i])
			{
				m_optionText[i].setFillColor(sf::Color{ 128,128,128,255 });
				m_costText[i].setFillColor(sf::Color{ 128,128,128,255 });
				m_metalText[i].setFillColor(sf::Color{ 128,128,128,255 });
			} 
			else
			{
				m_optionText[i].setFillColor(sf::Color::Yellow);
				m_costText[i].setFillColor(sf::Color::Yellow);
				m_metalText[i].setFillColor(sf::Color::Yellow);
			}		
			if (Ship::s_currentLevels[current] > i)
			{
				m_optionText[i].setFillColor(sf::Color::White);
				m_costText[i].setFillColor(sf::Color::White);
				m_metalText[i].setFillColor(sf::Color::White);
			}
			m_optionText[i].setString("");
			m_costText[i].setString("");
			m_metalText[i].setString("");
			if (i > Ship::s_currentLevels[current]-1)
			{
				m_optionText[i].setString(m_descriptors[current][i]);
				m_costText[i].setString(std::to_string(m_upgradeCost[current][i]));
				m_metalText[i].setString(std::to_string(m_upgradeMaterial[current][i]));
			}
			if (i == Ship::s_currentLevels[current]-1)
			{
				m_optionText[i].setString(m_descriptors[current][i]);				
			}
		}
		t_window.draw(m_title);
		t_window.draw(m_money);
		t_window.draw(m_material);
		t_window.draw(m_gemsSprite);
		for (int i = 0; i < 3; i++)
		{
			t_window.draw(m_optionText[i]);
			t_window.draw(m_costText[i]);
			t_window.draw(m_metalText[i]);
		}
		

	}
}

void Hanger::update(sf::Time t_deltaTime, sf::RenderWindow & t_window)
{
	m_currentArea = ShipArea::None;
	int current = -1;
	for (int i = 0; i < 4; i++)
	{
		if (sf::Mouse::getPosition(t_window).x > m_hoverAreas[i][0] // left
			&& sf::Mouse::getPosition(t_window).x < m_hoverAreas[i][0] + m_hoverAreas[i][2] // right = left + width
			&& sf::Mouse::getPosition(t_window).y > m_hoverAreas[i][1]
			&& sf::Mouse::getPosition(t_window).y < m_hoverAreas[i][1] + m_hoverAreas[i][3])
		{
			m_currentArea = static_cast<ShipArea>(i);
			current = static_cast<int>(m_currentArea);
		}
	}
	if (m_mouseClick && current != -1)
	{
		
		if (Ship::s_currentLevels[current] < 3)
		{
			if ( !(Game::s_credits < m_upgradeCost[current][Ship::s_currentLevels[current] + 1]
				|| Game::s_gems[5] < m_upgradeMaterial[current][Ship::s_currentLevels[current] + 1]))
			{
				Game::s_credits -= m_upgradeCost[current][Ship::s_currentLevels[current]];
				Game::s_gems[5] -= m_upgradeMaterial[current][Ship::s_currentLevels[current]];
				Ship::s_currentLevels[current]++;				
			}
		}
	}
	m_material.setString(std::to_string(Game::s_gems[5]));
	m_money.setString(std::to_string(Game::s_credits));
	m_mouseClick = false;
}

void Hanger::processEvents(sf::Event t_event)
{
	if (sf::Event::MouseButtonReleased == t_event.type)
	{
		m_mouseClick = true;
		if (t_event.mouseButton.x > 750 && t_event.mouseButton.y < 50)
		{
			Game::s_currentGameState = GameState::Hub;
		}
	}
}

void Hanger::initialise(sf::Font & t_font)
{
	m_font = t_font;
	setupText(m_title, 32, sf::Vector2f{ OFFSET_LEVEL_X, OFFSET_LEVEL_Y  });
	setupText(m_optionText[0], 24, sf::Vector2f{ OFFSET_LEVEL_X, OFFSET_LEVEL_Y + 1 * INTERVAL_LEVEL_Y });
	setupText(m_optionText[1], 24, sf::Vector2f{ OFFSET_LEVEL_X, OFFSET_LEVEL_Y + 2 * INTERVAL_LEVEL_Y });
	setupText(m_optionText[2], 24, sf::Vector2f{ OFFSET_LEVEL_X, OFFSET_LEVEL_Y + 3 * INTERVAL_LEVEL_Y });
	setupText(m_costText[0], 24, sf::Vector2f{ OFFSET_LEVEL_X + 170.0f, OFFSET_LEVEL_Y + 1 * INTERVAL_LEVEL_Y });
	setupText(m_costText[1], 24, sf::Vector2f{ OFFSET_LEVEL_X + 170.0f, OFFSET_LEVEL_Y + 2 * INTERVAL_LEVEL_Y });
	setupText(m_costText[2], 24, sf::Vector2f{ OFFSET_LEVEL_X + 170.0f, OFFSET_LEVEL_Y + 3 * INTERVAL_LEVEL_Y });
	setupText(m_metalText[0], 24, sf::Vector2f{ OFFSET_LEVEL_X + 250.0f, OFFSET_LEVEL_Y + 1 * INTERVAL_LEVEL_Y });
	setupText(m_metalText[1], 24, sf::Vector2f{ OFFSET_LEVEL_X + 250.0f, OFFSET_LEVEL_Y + 2 * INTERVAL_LEVEL_Y });
	setupText(m_metalText[2], 24, sf::Vector2f{ OFFSET_LEVEL_X + 250.0f, OFFSET_LEVEL_Y + 3 * INTERVAL_LEVEL_Y });
	setupText(m_money, 24, sf::Vector2f{ OFFSET_LEVEL_X , OFFSET_LEVEL_Y + 300.0f});
	setupText(m_material, 24, sf::Vector2f{ OFFSET_LEVEL_X + 40.0f , OFFSET_LEVEL_Y + 340.0f });
}

void Hanger::setupText(sf::Text & text, int t_size, sf::Vector2f position)
{
	text.setFont(m_font);
	text.setCharacterSize(t_size);	
	text.setFillColor(sf::Color::White);
	text.setPosition(position);
}
