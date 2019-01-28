#include "Crystal.h"
#include <iostream>



sf::Texture Crystal::s_crystalTexture;

Crystal::Crystal()
{
}


Crystal::~Crystal()
{
}

void Crystal::render(sf::RenderWindow & t_window)
{
	if (m_active)
	{
		t_window.draw(m_crystalSprite);
		dot.setPosition(m_location);		
		t_window.draw(dot);
	}
}

void Crystal::update(sf::Time t_deltaTime)
{
}

void Crystal::loadContent()
{
	if (!Crystal::s_crystalTexture.loadFromFile("assets\\images\\gems.png"))
	{
		std::cout << "problem loading Crystal " << std::endl;
	}
}

void Crystal::activate(sf::Vector2f t_location, int t_type)
{
	m_crystalSprite.setTexture(s_crystalTexture);
	m_crystalSprite.setTextureRect(sf::IntRect{ t_type * 32,0,32,32 });
	m_crystalSprite.setOrigin(16.0f, 16.0f);
	m_crystalSprite.setPosition(t_location);
	m_type = t_type;
	m_location = t_location;
	m_active = true;
}
