#include "Map.h"
#include <iostream>
#include <string.h>




Map::Map()
{
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
		if (m_planets[i].active)
		{
			window.draw(m_planetSprites[i]);
		}
	}
	
}

void Map::update(sf::Time deltaTime, sf::RenderWindow & window)
{
	m_currentPlanet = -1;
	for (size_t i = 0; i < maxPlanets; i++)
	{
		if (sf::Mouse::getPosition(window).x > m_planets[i].location.left
			&& sf::Mouse::getPosition(window).x < m_planets[i].location.left + m_planets[i].location.width
			&& sf::Mouse::getPosition(window).y > m_planets[i].location.top
			&& sf::Mouse::getPosition(window).y < m_planets[i].location.top + m_planets[i].location.height)
		{
			m_currentPlanet = i;
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

}
