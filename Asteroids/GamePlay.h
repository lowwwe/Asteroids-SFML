#ifndef GAMEPLAY
#define GAMEPLAY
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Ship.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "Explosion.h"
#include "Crystal.h"

const int MAX_ASTEROIDS = 20;
const int MAX_EXPLOSIONS = 2;
const int MAX_CRYSTALS = 10;



class GamePlay
{
public:
	GamePlay();
	~GamePlay();
	void render(sf::RenderWindow &t_window);
	void update(sf::Time t_deltaTime);
	void processEvents(sf::Event t_event);
	void initialise(sf::Font & t_font);
	void setupLevel(int t_levelNo);
private:
	
	Ship m_ship;
	Asteroid m_asteroids[MAX_ASTEROIDS];
	Bullet m_bullets[MAX_BULLETS];
	Explosion m_explosions[MAX_EXPLOSIONS];
	Crystal m_crystals[MAX_CRYSTALS];
	sf::SoundBuffer m_laserSoundBuffer;
	sf::Sound m_laserSound;
	sf::SoundBuffer m_enemyLaserSoundBuffer;
	sf::Sound m_enemyLaserSound;
	sf::SoundBuffer m_explosionSoundBuffer;
	sf::Sound m_explosionSound;
	sf::SoundBuffer m_engineSoundBuffer;
	sf::Sound m_engineSound;
	sf::SoundBuffer m_asteroidBreakSoundBuffer;
	sf::Sound m_asteroidBreakSound;
	bool m_shipTrunRight{ false };
	bool m_shipTrunLeft{ false };
	bool m_shipAccelerate{ false };
	bool m_fire{ false };

	void fireBullet();
	void collisions();
	bool checkBulletAsteroid(Bullet &t_bullet, Asteroid &t_asteroid);
	void newExplosion(MyVector2D t_location, animation t_type);
	void newCrystal(MyVector2D t_location, int t_type);
	int chooseCrystal();
	bool checkShipCrystal(MyVector2D t_shipLocation, MyVector2D t_crystalLocation);
	
};

#endif // !GAMEPLAY