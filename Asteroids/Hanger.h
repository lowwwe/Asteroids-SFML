#ifndef HANGER_H
#define HANGER_H

//////////////////////
// Headers
//////////////////////////
#include <SFML\Graphics.hpp>
#include <iostream>


enum class 
	ShipArea { 
	Engine = 0, 
	Laser = 1, 
	Hold = 2, 
	Reactor = 3,
	None = 4
};

class Hanger
{
public:
	Hanger();
	~Hanger();
	void render(sf::RenderWindow &t_window);
	void update(sf::Time t_deltaTime, sf::RenderWindow &t_window);
	void processEvents(sf::Event t_event);
	void initialise(sf::Font & t_font);
private:
	void  setupText(sf::Text &t_text, int t_size, sf::Vector2f t_position);
	
	sf::Texture m_backgroundTexture;
	sf::Texture m_shipTexture;
	sf::Sprite m_backgroundSprite;	
	sf::Sprite m_shipSprite;
	sf::Texture m_menuTexture;
	sf::Sprite m_menuSprite;
	sf::Texture m_gemsTexture;
	sf::Sprite m_gemsSprite;
	sf::Font m_font;
	const float OFFSET_SHIP_X = 10.0f;
	const float OFFSET_SHIP_Y = 30.0f;
	const float OFFSET_LEVEL_Y = 70.0f;
	const float OFFSET_LEVEL_X = 500.0f;
	const float INTERVAL_LEVEL_Y = 50.0F;
	std::string m_names[4] = { "Engine", "Laser", "Hold", "Reactor" };
	std::string m_descriptors[4][3] =
	{
		{ "Diesel", "Turbo", "SuperCharged" },
	{ "Neon", "Green", "Death Ray" },
	{ "Ample", "Spacious", "Cavernous" },
	{ "Fission", "Fusion", "Cold Fusion" }
	};
	int m_upgradeCost[4][3] =
	{
		{ 1000, 2000, 3000 },
	{ 1000, 2000, 5000 },
	{ 1000, 4000, 6000 },
	{ 1000, 4000, 9000 }
	};
	int m_upgradeMaterial[4][3] =
	{
		{ 2, 2, 4 },
	{ 2, 2, 4 },
	{ 2, 2, 4 },
	{ 2, 2, 4 }
	};
	int m_hoverAreas[4][4] =
	{
		{ 214, 316, 84, 48 },
		{ 104, 43, 290, 106 },
		{ 195, 192, 120, 140 },
		{ 98, 330, 100, 73 }
	};
	ShipArea m_currentArea{ ShipArea::None };
	bool m_mouseClick{ false };
	sf::Text m_optionText[4];
	sf::Text m_costText[3];
	sf::Text m_metalText[3];
	sf::Text m_title;
	sf::Text m_money;
	sf::Text m_material;

};

#endif // !HANGER_H
