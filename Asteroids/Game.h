#ifndef GAME
#define GAME

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Logo.h"
#include "Splash.h"
#include "Hub.h"
#include "Map.h"
#include "Help.h"
#include "GamePlay.h"
#include <string.h>



struct Planet
{
	std::string name;
	double minerals[5];
	double pirates;
	sf::IntRect location;
	bool active;
};

enum class  
	GameState   {
	Logo,
	Splash, 
	Start, 
	Hub, 
	Map, 
	Hanger, 
	Market, 
	Pause, 
	Game, 
	Help, 
	Over };
enum class
	EngineState {
	Drift,
	Power, 
	Turn };

enum class 
	PauseOption {
	Resume, 
	Base, 
	None };
enum class
	Music {
	Menu,
	Level
};

class Game
{
public:
	Game();
	~Game();
	void run();
	static GameState s_currentGameState; // current mode
	static Planet g_planets[];
	static int s_currentPlanet;
	static Music s_music;
	static GamePlay s_gameplay;

private:
	void render();
	void processEvents();
	void update(sf::Time deltaTime);
	void checkMusic();

	sf::RenderWindow  m_window; // our window
	sf::Music m_menuMusic; // music for the menu


	Logo m_logo; // logo screen
	Splash m_splash;
	Hub m_hub;
	Map m_map;
	Help m_help;
	
	sf::Font m_font; // nasa font
	Music m_currentMusic = Music::Menu;
	sf::Music m_levelmusic;
};





#endif // !GAME
