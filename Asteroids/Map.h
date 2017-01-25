#ifndef MAP
#define MAP
#include <SFML\Graphics.hpp>


class Map
{
public:
	Map();
	~Map();
	void render(sf::RenderWindow &window);
	void update(sf::Time deltaTime, sf::RenderWindow &window);
	void processEvents(sf::Event event);
	void initialise(sf::Font & font);
private:
	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;
};

#endif // !MAP