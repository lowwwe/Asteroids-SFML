#ifndef MARKET
#define MARKET

#include <SFML\Graphics.hpp>
#include "Contract.h"
const int MAX_CONTRACTS = 100;

class Market
{
public:
	Market();
	~Market();
	void render(sf::RenderWindow &t_window);
	void update(sf::Time t_deltaTime, sf::RenderWindow &t_window);
	void processEvents(sf::Event t_event);
	void initialise(sf::Font & t_font);

private:
	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;
	sf::Texture m_menuIconTexture;
	sf::Sprite m_menuIconSprite;
	sf::Texture m_gemsTexture;
	sf::Sprite m_gemsSprites[5];
	sf::Font m_font;	
	sf::Text m_titleText;
	sf::Text m_valueText;
	int m_marketSelection = -1;

	Contract m_contracts[MAX_CONTRACTS];

	void  setupText(sf::Text &t_text, std::string t_string, sf::Vector2f t_position);
	void setupContracts(); 
};

#endif // !MARKET