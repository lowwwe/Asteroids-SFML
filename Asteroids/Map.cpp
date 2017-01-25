#include "Map.h"
#include <iostream>



Map::Map()
{
	if (!m_backgroundTexture.loadFromFile("ASSETS\\IMAGES\\planet0.jpg"))
	{
		std::cout << "problem with menu" << std::endl;
	}
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setPosition(0.0f, 0.0f);
}


Map::~Map()
{
}

void Map::render(sf::RenderWindow & window)
{
	window.draw(m_backgroundSprite);
}

void Map::update(sf::Time deltaTime, sf::RenderWindow & window)
{
}

void Map::processEvents(sf::Event event)
{
}

void Map::initialise(sf::Font & font)
{

}
