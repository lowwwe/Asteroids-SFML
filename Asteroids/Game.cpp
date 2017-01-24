#include "Game.h"
#include <iostream>


GameState Game::s_currentGameState = GameState::Logo;

Game::Game() :
	m_window(sf::VideoMode(800, 600), "Asteroids")
	
{
	if (!m_font.loadFromFile("ASSETS\\FONTS\\nasalization-rg.ttf"))
	{
		std::cout << "Problem wioth font file" << std::endl;
	}
	m_logo.initialise(m_font);
	m_hub.initialise(m_font);
	if (!m_menuMusic.openFromFile("ASSETS\\AUDIO\\MENULOOP.WAV"))
	{
		std::cout << "Problem with menu musoic" << std::endl;
	}
	m_menuMusic.setLoop(true);
	m_menuMusic.play();
}


Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			update(timePerFrame);
			processEvents();
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
		switch (s_currentGameState)
		{
		case GameState::Logo:
			break;
		case GameState::Splash:
			m_splash.processEvents(event);
			break;
		case GameState::Start:
			break;
		case GameState::Hub:
			m_hub.processEvents(event);
			break;
		case GameState::Map:
			break;
		case GameState::Hanger:
			break;
		case GameState::Market:
			break;
		case GameState::Pause:
			break;
		case GameState::Game:
			break;
		case GameState::Help:
			break;
		case GameState::Over:
			break;
		default:
			break;
		}
	}
}

void Game::update(sf::Time time)
{
	switch (s_currentGameState)
	{
	case GameState::Logo:
		m_logo.update(time);
		break;
	case GameState::Splash:
		break;
	case GameState::Start:
		break;
	case GameState::Hub:
		m_hub.update(time);
		break;
	case GameState::Map:
		break;
	case GameState::Hanger:
		break;
	case GameState::Market:
		break;
	case GameState::Pause:
		break;
	case GameState::Game:
		break;
	case GameState::Help:
		break;
	case GameState::Over:
		break;
	default:
		break;
	}
}


void Game::render()
{
	m_window.clear();
	switch (s_currentGameState)
	{
	case GameState::Logo:
		m_logo.render(m_window);
		break;
	case GameState::Splash:
		m_splash.render(m_window);
		break;
	case GameState::Start:
		break;
	case GameState::Hub:
		m_hub.render(m_window);
		break;
	case GameState::Map:
		break;
	case GameState::Hanger:
		break;
	case GameState::Market:
		break;
	case GameState::Pause:
		break;
	case GameState::Game:
		break;
	case GameState::Help:
		break;
	case GameState::Over:
		break;
	default:
		break;
	}
	m_window.display();
}