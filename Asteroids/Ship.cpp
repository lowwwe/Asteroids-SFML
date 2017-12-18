#include "Ship.h"
#include <iostream>


const float  PI_F = 3.14159265358979f;

Ship::Ship()
{
	if (!m_shipTextures[0].loadFromFile("assets\\images\\smallplayerstrip064.png"))
	{
		std::cout << "problem loading small ship 0" << std::endl;
	}
	if (!m_shipTextures[1].loadFromFile("assets\\images\\smallplayerstrip164.png"))
	{
		std::cout << "problem loading small ship 1" << std::endl;
	}
	m_shipSprite.setTexture(m_shipTextures[0]);
	m_shipSprite.setTextureRect(sf::IntRect{ 0,0,64,64 });
	m_shipSprite.setPosition(m_location - MyVector2D{32, 32});
	m_shipSprite.setOrigin(32.0f, 32.0f);
	m_shipSprite.rotate(90);
}


Ship::~Ship()
{
}

void Ship::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_shipSprite);
}

void Ship::reset()
{
	m_location = MyVector2D{ 400.0 ,300.0 };



}

void Ship::turnLeft()
{
	m_heading -= m_turnRate;
	m_shipSprite.setRotation(m_heading +90.0f);
}

void Ship::turnRight()
{
	m_heading += m_turnRate;
	m_shipSprite.setRotation(m_heading + 90.0f);
}

void Ship::accelerate()
{
	float headingRadians = m_heading * PI_F / 180.0f;
	MyVector2D trust{ cos(headingRadians),sin(headingRadians) };

	trust.normalise();
	trust * m_accelarationRate;
	m_velocity += trust;
	
}

void Ship::update(sf::Time t_delta)
{
	m_location += m_velocity;
	m_shipSprite.setPosition(m_location);
	friction();
	screenWrap();
	engineFrame();
}

void Ship::friction()
{	
	if (m_velocity.lengthSquared() > m_maxSpeedSquared)
	{
		m_velocity = m_velocity * (m_maxSpeedSquared / m_velocity.lengthSquared());
	}
	if (m_velocity.lengthSquared() > 5.0)
	{
		m_velocity = m_velocity *.99;
	}
	else
	{
		if (m_velocity.lengthSquared() > 0.5)
		{
			m_velocity = m_velocity * m_dragCoefficient;
		}
		else
		{
			m_velocity = { 0.0,0.0 };
		}
	}
}

void Ship::screenWrap()
{
	if (m_location.y < -64)
	{
		m_location.y = 640;
	}
	if (m_location.y  > 640)
	{
		m_location.y = -64;
	}
	if (m_location.x < -64)
	{
		m_location.x = 800;
	}
	if (m_location.x > 800)
	{
		m_location.x = -64;
	}
}

void Ship::engineFrame()
{
	if (m_enginePowerOn)
	{
		m_engineFrame += m_engineFrameIncrement;
		int frame = static_cast<int>(m_engineFrame) % m_maxEngineFrame;
		m_shipSprite.setTextureRect(sf::IntRect{ 64 * frame,0,64,64 });
	}
	else
	{
		m_shipSprite.setTextureRect(sf::IntRect{ 0,0,64,64 });
	}
}
