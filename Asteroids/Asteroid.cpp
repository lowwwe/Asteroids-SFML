#include "Asteroid.h"
#include <iostream>

int Asteroid::s_sizes[]={ 32,64,96,128 };


Asteroid::Asteroid()
{
	dot.setFillColor(sf::Color::Red);
		if (!m_asteroidTexture[0].loadFromFile("assets\\images\\asteroid0.png"))
		{
			std::cout << "problem loading asteroid 0" << std::endl;
		}
		if (!m_asteroidTexture[1].loadFromFile("assets\\images\\asteroid1.png"))
		{
			std::cout << "problem loading asteroid 1" << std::endl;
		}
		if (!m_asteroidTexture[2].loadFromFile("assets\\images\\asteroid2.png"))
		{
			std::cout << "problem loading asteroid 2" << std::endl;
		}
		if (!m_asteroidTexture[3].loadFromFile("assets\\images\\asteroid3.png"))
		{
			std::cout << "problem loading asteroid 3" << std::endl;
		}
		m_asteroidSprite.setTexture(m_asteroidTexture[3]);
		m_size = 3;
		m_velocity = { (std::rand() % 40) / 10.0f,(std::rand() % 40) / 10.0f };
		m_spinRate = (static_cast<float>(std::rand() % 16 - 8) / 2);


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
		m_asteroidSprite.setRotation(m_angle);
		m_asteroidSprite.setPosition(static_cast<sf::Vector2f>(m_location) );
	
	}
}

void Asteroid::render(sf::RenderWindow & t_window)
{
	if (m_active)
	{
		dot.setPosition(m_location);		
		t_window.draw(m_asteroidSprite);
		t_window.draw(dot);
	}
}

void Asteroid::initialise(int _initialSize)
{
}

void Asteroid::reStart(int t_size)
{
	m_active = true;
	m_size = (t_size < 3) ? t_size : 3;
	m_angle = 0.0f;
	m_spinRate = static_cast<float>((std::rand() % 100) - 50) * SPIN_FACTOR;
	m_velocity = MyVector2D{ (std::rand() % 40) / 10.0,(std::rand() % 40) / 10.0 };
	m_location = MyVector2D{ static_cast<double>(std::rand() % 800),static_cast<double>(std::rand() % 640 )};
	m_asteroidSprite.setTexture(m_asteroidTexture[m_size],true);
	m_asteroidSprite.setOrigin(static_cast<float>(s_sizes[m_size]/2), static_cast<float>(s_sizes[m_size]/2));
	
	
}

bool Asteroid::reSize(Bullet & t_bullet, Asteroid t_newAsteroid)
{
	return false;
}

bool Asteroid::destroy()
{
	return false;
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
