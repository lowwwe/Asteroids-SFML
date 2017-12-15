#ifndef HELP
#define HELP

#include <SFML\Graphics.hpp>
// @author Peter Lowe

class Help
{
public:
	Help();
	~Help();
	void render(sf::RenderWindow &t_window);
	void update(sf::Time t_deltaTime, sf::RenderWindow &t_window);
	void processEvents(sf::Event t_event);
	void initialise(sf::Font & t_font);

private:
	void setupText(sf::Text &t_text, std::string t_string, sf::Vector2f t_position);
	sf::Texture m_backgroundTexture;
	sf::Sprite m_backgroundSprite;	
	sf::Font m_font;
	int m_curretnPage = 0;
	sf::Text m_titleText;
	sf::Text m_footerText[5];
	sf::Text m_page1Text;
	sf::Text m_page2Text;
	sf::Text m_page3Text;
	sf::Text m_page4Text;
	int m_nextHelpPage = -1;
	
};

#endif // !HELP