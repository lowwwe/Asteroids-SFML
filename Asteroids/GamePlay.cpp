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

}


GamePlay::~GamePlay()
{
}

void GamePlay::render(sf::RenderWindow & t_window)
{
	m_ship.render(t_window);
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
	m_ship.update(t_deltaTime);
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
	}
}

void GamePlay::initialise(sf::Font & t_font)
{
	
}
