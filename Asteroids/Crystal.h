#pragma once
#include <SFML\Graphics.hpp>
#include "MyVector2D.h"

class Crystal
{
public:
	Crystal();
	~Crystal();
	static sf::Texture s_crystalTexture;
	MyVector2D m_location;
	int m_type;
	sf::Sprite m_crystalSprite;
	bool m_active = false;

	sf::CircleShape dot{ 2.0f };

	void render(sf::RenderWindow &t_window);
	void update(sf::Time t_deltaTime);
	static void loadContent();
	void activate(sf::Vector2f t_location, int t_type);
	
};

