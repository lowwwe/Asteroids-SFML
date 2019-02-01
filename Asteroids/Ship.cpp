#include "Ship.h"
#include <iostream>



int Ship::s_currentLevels[4] = { 1,2,0,0 };

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
	if (!m_shieldTexture.loadFromFile("assets\\images\\shield.png"))
	{
		std::cout << "problem loading shield" << std::endl;
	}
	m_shieldSprite.setTexture(m_shieldTexture);
	m_shieldSprite.setOrigin(32.0f, 32.0f);
	m_shieldSprite.setPosition(m_location - MyVector2D{ 32, 32 });
	if (!m_gemsTexture.loadFromFile("assets\\images\\gems.png"))
	{
		std::cout << "problem loading gems" << std::endl;
	}
	m_gemsSprite.setTexture(m_gemsTexture);
	if (!m_holdTexture.loadFromFile("assets\\images\\hold.png"))
	{
		std::cout << "problem loading hold" << std::endl;
	}
	m_holdSprite.setTexture(m_holdTexture);	
	for (int i = 0; i < MAX_HOLD_ITEMS; i++)
	{
		m_hold[i] = -1;
	}


}


Ship::~Ship()
{
}

void Ship::render(sf::RenderWindow & t_window)
{
	if (m_active)
	{
		t_window.draw(m_shipSprite);
#ifdef _DEBUG
		sf::CircleShape dot{ 2.0f };
		dot.setPosition(m_location);
		t_window.draw(dot);
#endif

		if (m_sheildOn)
		{
			renderShield(t_window);
		}
	}
	renderHold(t_window);
}

void Ship::reset()
{
	m_location = MyVector2D{ 400.0 ,300.0 };
	m_accelarationRate = m_levels[ENGINE][s_currentLevels[ENGINE]];
	m_holdCapicity = m_levels[HOLD][s_currentLevels[HOLD]];
	for (int i = 0; i < m_holdCapicity; i++)
	{
		m_hold[i] = -1;
		 
	}
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
	trust = trust *  m_accelarationRate;
	m_velocity += trust;
	
}

void Ship::update(sf::Time t_delta)
{
	m_location += m_velocity;
	m_shipSprite.setPosition(m_location);
	friction();
	screenWrap();
	engineFrame();
	shield();
}

void Ship::friction()
{	
	if (m_velocity.lengthSquared() > m_maxSpeedSquared)
	{
		m_velocity = m_velocity * (m_maxSpeedSquared / m_velocity.lengthSquared());
	}
	if (m_velocity.lengthSquared() > 5.0)
	{
		m_velocity = m_velocity * FAST_FRICTION;
	}
	else
	{
		if (m_velocity.lengthSquared() > 0.1)
		{
			m_velocity = m_velocity * SLOW_FRICTION;
		}
		else
		{
			m_velocity = { 0.0,0.0 };
		}
	}
}

void Ship::screenWrap()
{
	if (m_location.y < -32)
	{
		m_location.y = 672;
	}
	if (m_location.y  > 672)
	{
		m_location.y = -32;
	}
	if (m_location.x < -32)
	{
		m_location.x = 832;
	}
	if (m_location.x > 832)
	{
		m_location.x = -32;
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

void Ship::shield()
{
	if (m_sheildOn)
	{
		if (m_sheildEnergy-- < 0)
		{
			m_sheildOn = false;
		}
	}
}

void Ship::renderShield(sf::RenderWindow & t_window)
{
	m_shieldSprite.setPosition(m_shipSprite.getPosition());
	if (m_alphaUp)
	{
		m_shieldAplha += 0.1f;
	}
	else
	{
		m_shieldAplha -= 0.1f;
	}
	if (m_shieldAplha > 255.0f)
	{
		m_alphaUp = false;
	}
	if (m_shieldAplha < 50.0f)
	{
		m_alphaUp = true;
	}
	m_shieldSprite.setColor(sf::Color{ 255,255,255,static_cast<sf::Uint8>(m_shieldAplha) });
	t_window.draw(m_shieldSprite);
	m_shieldSprite.rotate(0.05f);
}

void Ship::renderHold(sf::RenderWindow & t_window)
{
	float holdOffsetX = 60.0f;
	float holdOffsetY = 540.0f;
	sf::IntRect textureRect{ 0,0,32,32 };
	
	for (int i = 0; i < m_holdCapicity; i++)
	{
		m_holdSprite.setPosition(holdOffsetX, holdOffsetY);
		holdOffsetX += 4.0f;
		t_window.draw(m_holdSprite);
		if (m_hold[i] != -1)
		{
			textureRect.left = m_hold[i] * 32;
			m_gemsSprite.setTextureRect(textureRect);			
			m_gemsSprite.setPosition(holdOffsetX, holdOffsetY + 4.0f);			
			t_window.draw(m_gemsSprite);
		}
		holdOffsetX += 36.0f;
	}
}

void Ship::addToHold(int t_type)
{
	for (int i = 0; i < m_holdCapicity; i++)
	{
		if (m_hold[i] == -1)
		{
			m_hold[i] = t_type;
			return;	
		}
	}
	return;	
}

int Ship::getHoldItem(int t_index)
{
	if (t_index < m_holdCapicity)
	{
		return m_hold[t_index];
	}
	return -1;
}
