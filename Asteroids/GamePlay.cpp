#include "GamePlay.h"
#include <iostream>




GamePlay::GamePlay()
{
	if (!m_laserSoundBuffer.loadFromFile("assets\\audio\\laser.wav"))
	{
		std::cout << "problem loading laser sound" << std::endl;
	}
	m_laserSound.setBuffer(m_laserSoundBuffer);
	if (!m_enemyLaserSoundBuffer.loadFromFile("assets\\audio\\enemy laser.wav"))
	{
		std::cout << "problem loading enemy laser sound" << std::endl;
	}
	m_enemyLaserSound.setBuffer(m_enemyLaserSoundBuffer);
	if (!m_explosionSoundBuffer.loadFromFile("assets\\audio\\explosionSound.wav"))
	{
		std::cout << "problem loading explosion sound" << std::endl;
	}
	m_explosionSound.setBuffer(m_explosionSoundBuffer);	
	if (!m_engineSoundBuffer.loadFromFile("assets\\audio\\engine.wav"))
	{
		std::cout << "problem loading engine sound" << std::endl;
	}
	m_engineSound.setBuffer(m_engineSoundBuffer);
	m_engineSound.setLoop(true);
	m_engineSound.stop();
	if (!m_asteroidBreakSoundBuffer.loadFromFile("assets\\audio\\Asteroid breaking.wav"))
	{
		std::cout << "problem loading asteroid sound" << std::endl;
	}
	m_asteroidBreakSound.setBuffer(m_asteroidBreakSoundBuffer);
	m_asteroidBreakSound.play(); 
	if (!Bullet::s_bulletTexture.loadFromFile("assets\\images\\bullet16.png"))
	{
		std::cout << "problem loading bullet texture" << std::endl;
	}
}


GamePlay::~GamePlay()
{
}

void GamePlay::render(sf::RenderWindow & t_window)
{
	m_ship.render(t_window);
	for (size_t i = 0; i < MAX_ASTEROIDS; i++)
	{
		m_asteroids[i].render(t_window);
	}
	for (size_t i = 0; i < MAX_BULLETS; i++)
	{
		m_bullets[i].render(t_window);
	}
	m_bullets[0].render(t_window);
	
}

void GamePlay::update(sf::Time t_deltaTime)
{
	if (m_shipTrunRight)
	{
		m_ship.turnRight();
	}
	if (m_shipTrunLeft)
	{
		m_ship.turnLeft();
	}
	if (m_shipAccelerate)
	{
		m_ship.accelerate();	
		m_ship.m_enginePowerOn = true;
	}
	if (m_fire)
	{
		fireBullet();
		m_fire = false;
	}
	m_ship.update(t_deltaTime);
	for (size_t i = 0; i < MAX_ASTEROIDS; i++)
	{
		m_asteroids[i].update(t_deltaTime);
	}
	for (size_t i = 0; i < MAX_BULLETS; i++)
	{
		m_bullets[i].update(t_deltaTime);
	}
	collisions();
}

void GamePlay::processEvents(sf::Event t_event)
{
	if (sf::Event::KeyPressed == t_event.type)
	{
		if (sf::Keyboard::Right == t_event.key.code || sf::Keyboard::D == t_event.key.code)
		{
			m_shipTrunRight = true;
			m_shipTrunLeft = false;
		}
		if (sf::Keyboard::Left == t_event.key.code || sf::Keyboard::A == t_event.key.code)
		{
			m_shipTrunLeft = true;
			m_shipTrunRight = false;
		}
		if (sf::Keyboard::Up == t_event.key.code || sf::Keyboard::W == t_event.key.code)
		{
			if (!m_shipAccelerate)
			{
				m_shipAccelerate = true;
				m_engineSound.play();
				std::cout << "play engine" << std::endl;
			}
		}
		if (sf::Keyboard::LControl == t_event.key.code || sf::Keyboard::RControl == t_event.key.code)
		{
			m_fire = true; 			
		}
		if (sf::Keyboard::LShift == t_event.key.code || sf::Keyboard::RShift == t_event.key.code)
		{
			m_ship.m_sheildOn = true;
		}
	}
	if (sf::Event::KeyReleased == t_event.type)
	{
		if (sf::Keyboard::Right == t_event.key.code || sf::Keyboard::D == t_event.key.code  )
		{
			m_shipTrunRight = false;
		}
		if (sf::Keyboard::Left == t_event.key.code || sf::Keyboard::A == t_event.key.code)
		{
			m_shipTrunLeft = false;
		
		}
		if (sf::Keyboard::Up == t_event.key.code || sf::Keyboard::W == t_event.key.code)
		{
			m_shipAccelerate = false;
			m_engineSound.stop();
			m_ship.m_enginePowerOn = false;
		}
		if (sf::Keyboard::LShift == t_event.key.code || sf::Keyboard::RShift == t_event.key.code)
		{
			m_ship.m_sheildOn = false;
		}
	}
}

void GamePlay::initialise(sf::Font & t_font)
{
	
}

void GamePlay::setupLevel(int t_levelNo)
{
	m_ship.reset();
	for (size_t i = 0; i < MAX_ASTEROIDS; i++)
	{
		m_asteroids[i].m_active = false;
	}
	int asteroidCount;
	asteroidCount = (t_levelNo < 2) ? 2 : t_levelNo;
	for (int i = 0; i < asteroidCount; i++)
	{
		m_asteroids[i].reStart(i);
	}
	// add pirates
	// do crystals
	// do explosions
}

void GamePlay::fireBullet()
{
	int i{ 0 };
	bool found{ false };
	while( !found && i < MAX_BULLETS)
	{
		if (!m_bullets[i].m_alive)
		{
			found = true;
			float xBit = std::cos(m_ship.m_heading /180.0f * PI_F);
			float yBit = std::sin(m_ship.m_heading / 180.0f * PI_F);
			m_bullets[i].reStart(1, m_ship.m_location, MyVector2D{ xBit,yBit }, m_ship.m_heading);
		}
		++i;
	}
}

void GamePlay::collisions()
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (m_bullets[i].m_alive)
		{
			for (int j = 0; j < MAX_ASTEROIDS; j++)
			{
				if (m_asteroids[j].m_active)
				{
					if (checkBulletAsteroid(m_bullets[i], m_asteroids[j]))
					{
						m_bullets[i].m_alive = false;
						bool notFound = true;
						int index = 0;
						while (notFound && index < MAX_ASTEROIDS)
						{
							if(!m_asteroids[index].m_active)
							{ 
								notFound = false;
							}
							else
							{
								index++;
							}
						}
						if (!notFound)
						{
							m_asteroids[j].reSize(m_bullets[i], m_asteroids[index]);
						}
						else
						{
							m_asteroids[j].destroy();
						}
					}
				}
			}
		}
	}
}

bool GamePlay::checkBulletAsteroid(Bullet & t_bullet, Asteroid & t_asteroid)
{	
	float gap = Asteroid::s_sizes[ t_asteroid.m_size] + 16.0f;
	if (t_bullet.m_location.y < t_asteroid.m_location.y - gap)
	{
		return false;
	}
	if (t_bullet.m_location.y > t_asteroid.m_location.y + gap)
	{
		return false;
	}
	if (t_bullet.m_location.x < t_asteroid.m_location.x - gap)
	{
		return false;
	}
	if (t_bullet.m_location.x > t_asteroid.m_location.x + gap)
	{
		return false;
	}
	if ((t_asteroid.m_location - t_bullet.m_location).lengthSquared() > (gap * gap / 4))
	{
		return false;
	}
	return true;
}
