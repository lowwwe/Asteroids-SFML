#ifndef ASTEROID
#define ASTEROID

#include <SFML\Graphics.hpp>
#include "MyVector2D.h"
#include "Bullet.h"

float const SPIN_FACTOR = 0.06f;

class Asteroid
{
public:
	Asteroid();
	~Asteroid();
	
	static int s_sizes[];


	sf::CircleShape dot{ 2.0f };
	bool m_active = false;
	MyVector2D m_location;
	int m_size = 3;
	void update(sf::Time t_deltaTime);	
	void render(sf::RenderWindow &t_window);
	void initialise(int t_size, MyVector2D t_velocity, MyVector2D t_position);
	void reStart(int t_size);
	bool reSize(Bullet &t_bullet, Asteroid t_newAsteroid); 
	bool destroy();

private:
	sf::Texture m_asteroidTexture[4];
	sf::Sprite m_asteroidSprite;
	MyVector2D m_velocity;
	float m_angle = 0.0f;
	float m_spinRate = 5.0f;


	void screenWrap();
};

#endif // !ASTEROID