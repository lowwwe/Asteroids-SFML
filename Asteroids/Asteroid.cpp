#include "Asteroid.h"
#include <iostream>

int Asteroid::s_sizes[]={ 32,64,96,128 };


Asteroid::Asteroid()
{
	
		if (!m_asteroidTexture[0].loadFromFile("assets\\images\\asteroid0.png"))
		{
			std::cout << "problem loading asteroid 0" << std::endl;
		}
		if (!m_asteroidTexture[1].loadFromFile("assets\\images\\asteroid0.png"))
		{
			std::cout << "problem loading asteroid 1" << std::endl;
		}
		if (!m_asteroidTexture[2].loadFromFile("assets\\images\\asteroid0.png"))
		{
			std::cout << "problem loading asteroid 2" << std::endl;
		}
		if (!m_asteroidTexture[3].loadFromFile("assets\\images\\asteroid0.png"))
		{
			std::cout << "problem loading asteroid 3" << std::endl;
		}
		m_asteroidSprite.setTexture(m_asteroidTexture[3]);
		m_size = 3;
		m_velocity = { (std::rand() % 40) / 10.0f,(std::rand() % 40) / 10.0f };
		m_spinRate = (std::rand() % 16 - 8) / 2;


}


Asteroid::~Asteroid()
{
}

void Asteroid::update(sf::Time t_deltaTime)
{
	if (m_active)
	{
		m_location += m_velocity;
		m_angle += m_spinRate;
		screenWrap();
		m_asteroidSprite.setPosition(m_location);
		m_asteroidSprite.setRotation(m_angle);
	}
}

void Asteroid::render(sf::RenderWindow & t_window)
{
	if (m_active)
	{
		t_window.draw(m_asteroidSprite);
	}
}

void Asteroid::initialise(int _initialSize)
{
}

void Asteroid::screenWrap()
{
	if (m_location.y < - s_sizes[m_size]/2)
	{
		m_location.y = 640 + s_sizes[m_size] / 2;
	}
	if (m_location.y  > 640 + s_sizes[m_size] / 2)
	{
		m_location.y = -s_sizes[m_size] / 2;
	}
	if (m_location.x < -s_sizes[m_size] / 2)
	{
		m_location.x = 800 + s_sizes[m_size] / 2;
	}
	if (m_location.x > 800 + s_sizes[m_size] / 2)
	{
		m_location.x = -s_sizes[m_size] / 2;
	}
}
