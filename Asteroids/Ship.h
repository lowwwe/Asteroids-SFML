#ifndef SHIP
#define SHIP
#include <SFML\Graphics.hpp>
#include "MyVector2D.h"

const float  PI_F = 3.14159265358979f;

class Ship
{
public:
	Ship();
	~Ship();
	void render(sf::RenderWindow &t_window);
	bool active = true;
	void reset();
	void turnLeft();
	void turnRight();
	void accelerate();
	void update(sf::Time t_delta);
	void friction();
	MyVector2D m_location{ 400.0 ,300.0 };
	bool m_enginePowerOn{ false };
	float m_heading = 0.0f;

private:
	sf::Texture m_shipTextures[2];
	sf::Sprite m_shipSprite;
	
	MyVector2D m_velocity;
	
	float m_turnRate = 2.0f;
	float m_accelarationRate = 0.20f;
	float m_maxSpeed;
	float m_maxSpeedSquared = 25.0f;
	float m_engineFrame = 0.0f;
	float m_engineFrameIncrement = 0.5f;
	float m_dragCoefficient = 0.995f;
	int m_maxEngineFrame = 6;
	
	void screenWrap();
	void engineFrame();
	

};

#endif // !SHIP