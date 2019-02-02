#include "Bullet.h"

sf::Texture Bullet::s_bulletTexture;

Bullet::Bullet()
{
	//m_bulletSprite.setTexture(s_bulletTexture,true);
	
	m_alive = false;
	m_framesLeft = 240;
	
}


Bullet::~Bullet()
{
}

void Bullet::render(sf::RenderWindow & t_window)
{
	if (m_alive)
	{
		t_window.draw(m_bulletSprite);
	}
}

void Bullet::update(sf::Time t_delta)
{
	if (m_alive)
	{
		m_location += m_velocity;
		if (m_framesLeft-- < 0)
		{
			m_alive = false;
		}
		screenWrap();
		m_bulletSprite.setPosition(m_location);
	}
}

void Bullet::reStart(int t_size, MyVector2D t_loaction, MyVector2D t_velocity, float t_heading, bool t_friendly)
{
	m_bulletSprite.setTexture(s_bulletTexture, true);
	m_bulletSprite.setOrigin(8.0f, 8.0f);
	m_alive = true;
	m_friendly = t_friendly;
	m_location = t_loaction;
	m_velocity = t_velocity *5.0f;
	m_framesLeft = 240;
	m_bulletSprite.setRotation(t_heading + 90.0f);
	m_bulletSprite.setPosition(m_location);
	
}



void Bullet::screenWrap()
{
	if (m_location.y < -BULLET_SIZE)
	{
		m_location.y = 640 + BULLET_SIZE;
	}
	if (m_location.y  > 640 + BULLET_SIZE)
	{
		m_location.y = -BULLET_SIZE;
	}
	if (m_location.x < -BULLET_SIZE)
	{
		m_location.x = 800 + BULLET_SIZE;
	}
	if (m_location.x > 800 + BULLET_SIZE)
	{
		m_location.x = -BULLET_SIZE;
	}
}
