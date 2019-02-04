#include "Game.h"
#include <iostream>


GameState Game::s_currentGameState = GameState::Logo;
Music Game::s_music = Music::Menu;
GamePlay Game::s_gameplay;
Planet Game::g_planets[] = {
	{ "Moon",{ 0.0, 0.1, 0.1, 0.0, 0.0 }, 0.9, sf::IntRect{ 534,41,30,25 } ,true }, 
	{ "Venus",{ 0.2, 0.2, 0.0, 0.0, 0.0 }, 0.1, sf::IntRect{ 250, 10, 30, 50 }, true },
	{ "Mercury",{ 0.5, 0.1, 0.0, 0.0, 0.0 }, 0.5, sf::IntRect{ 280, 20, 80, 80 } , true },
	{ "Earth",{ 0.15, 0.15, 0.15, 0.4, 0.0 }, 0.2, sf::IntRect{ 370, 45, 120, 90 }, false },
	{ "Mars",{ 0.1, 0.8, 0.0, 0.0, 0.0 }, 0.3, sf::IntRect{ 506, 130, 100, 60 }, false },
	{ "Jupiter",{ 0.1, 0.1, 0.1, 0.1, 0.1 }, 0.4, sf::IntRect{ 530, 240, 200, 200 }, false },
	{ "Saturn",{ 0.2, 0.2, 0.2, 0.2, 0.2 }, 0.8, sf::IntRect{ 406, 331, 150, 120 } , false },
	{ "neptune",{ 0.1, 0.0, 0.0, 0.4, 0.5 }, 0.9, sf::IntRect{ 360, 427, 130, 121 } , false },
	{ "uranus",{ 0.0, 0.0, 0.0, 0.2, 0.5 }, 0.4, sf::IntRect{ 133, 400, 200, 200 } ,false }


};
int Game::s_currentPlanet = -1;
int Game::s_gems[] = { 0,0,0,0,0,0 };
int Game::s_credits = 0;




/*
Planet m_planets[maxPlanets]{
	{ static_cast<std::string>("Moon"),		 0.0, 0.1, 0.1, 0.0, 0.0, 0.9, sf::IntRect{ 534,41,30,25 } },
	{ static_cast<std::string>("Venus"),	 0.2, 0.2, 0.0, 0.0, 0.0, 0.1, sf::IntRect{ 250, 10, 30, 50 } },
	{ static_cast<std::string>("Mercury"),		 0.5, 0.1, 0.0, 0.0, 0.0, 0.5, sf::IntRect{ 280, 20, 80, 80 } },
	{ static_cast<std::string>("Earth"),		 0.15, 0.15, 0.15, 0.4, 0.0, 0.2, sf::IntRect{ 370, 45, 120, 90 } },

	{ static_cast<std::string>("Mars"),		 0.1, 0.8, 0.0, 0.0, 0.0, 0.3, sf::IntRect{ 506, 130, 100, 60 } },
	{ static_cast<std::string>("Jupiter"),		 0.1, 0.1, 0.1, 0.1, 0.1, 0.4, sf::IntRect{ 530, 240, 200, 200 } },
	{ static_cast<std::string>("Saturn"),		 0.2, 0.2, 0.2, 0.2, 0.2, 0.8, sf::IntRect{ 406, 331, 150, 120 } },
	{ static_cast<std::string>("neptune"),		 0.1, 0.0, 0.0, 0.4, 0.5, 0.9, sf::IntRect{ 360, 427, 130, 121 } },
	{ static_cast<std::string>("uranus"),		 0.0, 0.0, 0.0, 0.2, 0.5, 0.4, sf::IntRect{ 133, 400, 200, 200 } },
};*/
Game::Game() :
	m_window(sf::VideoMode(800, 600), "Asteroids")
	
{
	if (!m_font.loadFromFile("ASSETS\\FONTS\\nasalization-rg.ttf"))
	{
		std::cout << "Problem wioth font file" << std::endl;
	}
	m_logo.initialise(m_font);
	m_hub.initialise(m_font);
	m_map.initialise(m_font);
	m_help.initialise(m_font);
	m_market.initialise(m_font);
	m_hanger.initialise(m_font);
	s_gameplay.initialise(m_font);
	if (!m_menuMusic.openFromFile("ASSETS\\AUDIO\\menumusic2.ogg"))
	{
		std::cout << "Problem with menu musoic" << std::endl;
	}
	m_menuMusic.setLoop(true);
	m_menuMusic.play();	
	if (!m_levelmusic.openFromFile("ASSETS\\AUDIO\\levelmusic2.ogg"))
	{
		std::cout << "Problem with menu music" << std::endl;
	}

	m_levelmusic.setLoop(true);
	m_levelmusic.setVolume(1.0f);
#ifdef _DEBUG
	Game::s_gems[0] = 10;
	Game::s_gems[1] = 10;
	Game::s_gems[2] = 10;
	Game::s_gems[3] = 10;
	Game::s_gems[4] = 10;
	Game::s_gems[5] = 12;
	Game::s_credits = 40000;
#endif // _DEBUG

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
	sf::Event currentEvent;
	while (m_window.pollEvent(currentEvent))
	{
		if (currentEvent.type == sf::Event::Closed)
		{
			m_window.close();
		}
		switch (s_currentGameState)
		{
		case GameState::Logo:
			break;
		case GameState::Splash:
			m_splash.processEvents(currentEvent);
			break;
		case GameState::Start:
			break;
		case GameState::Hub:
			m_hub.processEvents(currentEvent);
			break;
		case GameState::Map:
			m_map.processEvents(currentEvent);
			break;
		case GameState::Hanger:
			m_hanger.processEvents(currentEvent);
			break;
		case GameState::Market:
			m_market.processEvents(currentEvent);
			break;
		case GameState::Pause:
			s_gameplay.pauseProcessEvents(currentEvent);
			break;
		case GameState::Game:
			s_gameplay.processEvents(currentEvent);
			break;
		case GameState::Help:
			m_help.processEvents(currentEvent);
			break;
		case GameState::Over:
			break;
		default:
			break;
		}
	}
}

void Game::update(sf::Time timeSlice)
{
	checkMusic();
	switch (s_currentGameState)
	{
	case GameState::Logo:
		m_logo.update(timeSlice);
		break;
	case GameState::Splash:
		break;
	case GameState::Start:
		break;
	case GameState::Hub:
		m_hub.update(timeSlice, m_window);
		break;
	case GameState::Map:
		m_map.update(timeSlice, m_window);
		break;
	case GameState::Hanger:
		m_hanger.update(timeSlice, m_window);
		break;
	case GameState::Market:
		m_market.update(timeSlice, m_window);
		break;
	case GameState::Pause:
		s_gameplay.pauseUpdate(timeSlice);
		break;
	case GameState::Game:
		s_gameplay.update(timeSlice);
		break;
	case GameState::Help:
		m_help.update(timeSlice, m_window);
		break;
	case GameState::Over:
		s_gameplay.overUpdate(timeSlice);
		break;
	case GameState::Exit:
		m_window.close();
	default:
		break;
	}
}


void Game::checkMusic()
{
	if (Game::s_music != m_currentMusic)
	{
		if (m_currentMusic == Music::Level)
		{
			m_menuMusic.play();
			m_levelmusic.stop();
			m_currentMusic = Music::Menu;
		}
		else
		{
			m_menuMusic.stop();
			m_levelmusic.play();
			m_currentMusic = Music::Level;
		}
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
		m_map.render(m_window);
		break;
	case GameState::Hanger:
		m_hanger.render(m_window);
		break;
	case GameState::Market:
		m_market.render(m_window);
		break;
	case GameState::Pause:
		s_gameplay.pauseRender(m_window);
		break;
	case GameState::Game:
		s_gameplay.render(m_window);
		break;
	case GameState::Help:
		m_help.render(m_window);
		break;
	case GameState::Over:
		s_gameplay.gameoverRender(m_window);
		break;
	default:
		break;
	}
	m_window.display();
}