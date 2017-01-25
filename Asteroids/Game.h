#ifndef GAME
#define GAME

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Logo.h"
#include "Splash.h"
#include "Hub.h"
#include "Map.h"


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

class Game
{
public:
	Game();
	~Game();
	void run();
	static GameState s_currentGameState; // current mode
private:
	void render();
	void processEvents();
	void update(sf::Time deltaTime);

	sf::RenderWindow  m_window; // our window
	sf::Music m_menuMusic; // music for the menu

	Logo m_logo; // logo screen
	Splash m_splash;
	Hub m_hub;
	Map m_map;
	sf::Font m_font; // nasa font
};

#endif // !GAME
