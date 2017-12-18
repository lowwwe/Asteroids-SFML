#ifndef GAMEPLAY
#define GAMEPLAY
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Ship.h"

class GamePlay
{
public:
	GamePlay();
	~GamePlay();
	void render(sf::RenderWindow &t_window);
	void update(sf::Time t_deltaTime);
	void processEvents(sf::Event t_event);
	void initialise(sf::Font & t_font);
private:
	
	Ship m_ship;
	sf::Sprite m_shipSprite;
	sf::SoundBuffer m_laserSoundBuffer;
	sf::Sound m_laserSound;
	sf::SoundBuffer m_enemyLaserSoundBuffer;
	sf::Sound m_enemyLaserSound;
	sf::SoundBuffer m_explosionSoundBuffer;
	sf::Sound m_explosionSound;
	sf::SoundBuffer m_engineSoundBuffer;
	sf::Sound m_engineSound;
	bool m_shipTrunRight{ false };
	bool m_shipTrunLeft{ false };
	bool m_shipAccelerate{ false };
	
};

#endif // !GAMEPLAY