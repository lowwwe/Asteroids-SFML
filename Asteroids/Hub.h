#ifndef HUB
#define HUB
#include <SFML\Graphics.hpp>

enum class
	HubRegion {
	Hanger,
	Map,
	Market,
	Help,
	Exit,
	None
};

class Hub
{
public:
	Hub();
	~Hub();
	void render(sf::RenderWindow &window);
	void update(sf::Time deltaTime, sf::RenderWindow &window);
	void processEvents(sf::Event event);
	void initialise(sf::Font & font);
private:
	void  setupText(sf::Text &text, std::string t_string, sf::Vector2f position);

	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;
	HubRegion m_currentRegion; // currently highlighted region
	sf::Font m_font;
	sf::Text m_mapText;
	sf::Text m_hangerText;
	sf::Text m_marketText;
	sf::Text m_helpText;
	sf::Text m_exitText;
	
	
};

#endif // !HUB