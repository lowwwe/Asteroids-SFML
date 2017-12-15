#include "Map.h"
#include <iostream>
#include <string.h>
#include "Game.h"




Map::Map()
	: m_currentPlanet{-1}
{
	if (!m_gemsTexture.loadFromFile("ASSETS\\IMAGES\\gems.png"))
	{
		std::cout << "problem with gems" << std::endl;
	}
	m_gemsSprite.setTexture(m_gemsTexture);

	if (!m_menuTexture.loadFromFile("ASSETS\\IMAGES\\menuicon.png"))
	{
		std::cout << "problem with gems" << std::endl;
	}
	m_menuSprite.setTexture(m_menuTexture);
	m_menuSprite.setPosition({ 750, 18 });


	if (!m_backgroundTexture.loadFromFile("ASSETS\\IMAGES\\planet0.jpg"))
	{
		std::cout << "problem with menu" << std::endl;
	}
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setPosition(0.0f, 0.0f);
	
	
	for (size_t i = 0; i < maxPlanets; i++)
	{
		std::string file = "ASSETS\\IMAGES\\planet" + std::to_string(i) + ".png";
		if (!m_planetTextures[i].loadFromFile(file))
		{
			std::cout << "problem withf planet" << i << std::endl;
		}
		m_planetSprites[i].setTexture(m_planetTextures[i]);
	}
}


Map::~Map()
{
}

void Map::render(sf::RenderWindow & window)
{
	window.draw(m_backgroundSprite);
	for (size_t i = 0; i < maxPlanets; i++)
	{
		if (Game::g_planets[i].active)
		{
			window.draw(m_planetSprites[i]);
		}
	}
	if (m_currentPlanet > -1)
	{
		sf::Color colour{ 255,255,255,255 };
		if (Game::g_planets[m_currentPlanet].active)
		{
			colour = sf::Color::Yellow;
		}
		m_pirates.setFillColor(colour);
		m_planetName.setFillColor(colour);
		m_gemProbability.setFillColor(colour);
		for (int i = 0; i < 5; i++)
		{
			m_gemsSprite.setTextureRect({ i * 32,0,32,32 });
			m_gemsSprite.setPosition({ 50.0f,140.0f + i * 40 });
			window.draw(m_gemsSprite);
			int gem =static_cast<int>( Game::g_planets[m_currentPlanet].minerals[i] * 100.0);
			m_gemProbability.setString(": " + std::to_string(gem) + "%");
			m_gemProbability.setPosition({ 90.0f,140.0f + i * 40 });
			window.draw(m_gemProbability);
		}
		int pirates = static_cast<int>(Game::g_planets[m_currentPlanet].pirates * 100.0);
		m_pirates.setString("Pirates : " + std::to_string(pirates) + "%");
		m_planetName.setString(Game::g_planets[m_currentPlanet].name);
		window.draw(m_planetName);
		window.draw(m_pirates);
	}
	window.draw(m_menuSprite);
	
}

void Map::update(sf::Time deltaTime, sf::RenderWindow & window)
{
	m_currentPlanet = -1;
	for (size_t i = 0; i < maxPlanets; i++)
	{
		if (sf::Mouse::getPosition(window).x > Game::g_planets[i].location.left
			&& sf::Mouse::getPosition(window).x < Game::g_planets[i].location.left + Game::g_planets[i].location.width
			&& sf::Mouse::getPosition(window).y > Game::g_planets[i].location.top
			&& sf::Mouse::getPosition(window).y < Game::g_planets[i].location.top + Game::g_planets[i].location.height)
		{
			m_currentPlanet = i;
		}
	}
	if (m_mouseClick)
	{
		if (sf::Mouse::getPosition(window).x > 750 && sf::Mouse::getPosition(window).y < 50)
		{
			Game::s_currentGameState = GameState::Hub;
		}
		if (m_currentPlanet != -1 && Game::g_planets[m_currentPlanet].active)
		{
			//setupPlanet(m_currentPlanet);
			Game::s_currentGameState = GameState::Game;
			//intitialiseLevel(m_currentPlanet;)
		}
	}
	m_mouseClick = false;
}

void Map::processEvents(sf::Event event)
{
	if (sf::Event::MouseButtonReleased == event.type)
	{
		m_mouseClick = true;
	}
}

void Map::initialise(sf::Font & font)
{
	m_font = font;
	m_pirates.setFont(m_font);
	m_pirates.setCharacterSize(18);
	m_pirates.setFillColor(sf::Color::Yellow);
	m_pirates.setPosition({ 50,350 });
	
	m_planetName.setFont(m_font);
	m_planetName.setCharacterSize(24);
	m_planetName.setPosition({ 50,100 });
	m_planetName.setFillColor(sf::Color::Yellow);
	m_gemProbability.setFont(m_font);
	m_gemProbability.setCharacterSize(18);

}
