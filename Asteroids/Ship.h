#ifndef SHIP
#define SHIP
#include <SFML\Graphics.hpp>
#include "MyVector2D.h"

const float  PI_F = 3.14159265358979f; 
const int ENGINE = 0; // Array index for ship parameters
const int LASER = 1;
const int HOLD = 2;
const int REACTOR = 3;
const float SLOW_FRICTION = 0.995f;
const float FAST_FRICTION = 0.95f;
const int MAX_HOLD_ITEMS = 10;

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
	bool m_sheildOn = false;
	float m_shieldAplha = 0;
	bool m_alphaUp = true;
	int m_sheildEnergy = 500;
	int m_levels[4][4] = { { 1,2,3,4 },{ 25,15,7,3 },{ 3,5,7,10 },{ 4,3,2,1 } };
	static int s_currentLevels[4];
	int m_hold[MAX_HOLD_ITEMS];
	void addToHold(int t_type);
	int getHoldItem(int t_index);

private:
	sf::Texture m_shipTextures[2];
	sf::Sprite m_shipSprite;
	sf::Texture m_shieldTexture;
	sf::Sprite m_shieldSprite;
	sf::Texture m_holdTexture;
	sf::Sprite m_holdSprite;
	sf::Texture m_gemsTexture;
	sf::Sprite m_gemsSprite;
	
	MyVector2D m_velocity; 
	
	float m_turnRate = 2.0f;
	int m_accelarationRate = m_levels[ENGINE][s_currentLevels[ENGINE]];

	float m_maxSpeed;
	float m_maxSpeedSquared = 25.0f;
	float m_engineFrame = 0.0f;
	float m_engineFrameIncrement = 0.5f;
	
	int m_maxEngineFrame = 6;
	int m_holdCapicity = m_levels[HOLD][s_currentLevels[HOLD]];
	int m_holdCurrentCount = 0;
	void screenWrap();
	void engineFrame();
	void shield();
	void renderShield(sf::RenderWindow &t_window);
	void renderHold(sf::RenderWindow &t_window);
	

};

#endif // !SHIP