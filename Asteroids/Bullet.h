#ifndef BULLET
#define BULLET

#include <SFML\Graphics.hpp>
#include "MyVector2D.h"

const int BULLET_SIZE = 16;
const int MAX_BULLETS = 50;
class Bullet
{
public:
	Bullet();
	~Bullet();
	void render(sf::RenderWindow &t_window);
	void update(sf::Time t_delta);
	void reStart(int t_size, MyVector2D t_loaction, MyVector2D t_velocity, float t_heading);
	bool m_alive = false;

	MyVector2D m_location;
	static sf::Texture s_bulletTexture;
	MyVector2D m_velocity;
private:
	void screenWrap();
	int m_framesLeft = 180;
	sf::Sprite m_bulletSprite;
	

};

#endif // !BULLET