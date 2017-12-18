#ifndef MARKET
#define MARKET

#include <SFML\Graphics.hpp>


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
	sf::Font m_font;	
	sf::Text m_titleText;

	void  setupText(sf::Text &t_text, std::string t_string, sf::Vector2f t_position);
};

#endif // !MARKET