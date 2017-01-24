#include "Hub.h"
#include <iostream>

void setupText(sf::Font &font, sf::Text &text, std::string string, sf::Vector2f position);

Hub::Hub()
{
	if (!m_backgroundTexture.loadFromFile("ASSETS\\IMAGES\\menu.PNG"))
	{
		std::cout << "problem with menu" << std::endl;
	}
	m_backgroundSprite.setTexture(m_backgroundTexture);
	m_backgroundSprite.setPosition(0.0f, 0.0f);
}


Hub::~Hub()
{
}

void Hub::render(sf::RenderWindow & window)
{
	window.draw(m_backgroundSprite);
	window.draw(m_mapText);
	window.draw(m_hangerText);
	window.draw(m_marketText);
	window.draw(m_helpText);
}

void Hub::update(sf::Time deltaTime)
{
}

void Hub::processEvents(sf::Event event)
{
}

void Hub::initialise(sf::Font & font)
{
	m_font = font;
	setupText(font, m_mapText, "MAP", { 150,100 });
	setupText(font, m_hangerText, "HANGER", { 500,100 });
	setupText(font, m_marketText, "MARKET", { 150,300 });
	setupText(font, m_helpText, "HELP", { 500,300 });
}
void setupText(sf::Font &font, sf::Text &text, std::string string, sf::Vector2f position)
{
	text.setFont(font);
	text.setCharacterSize(24);
	text.setString(string);
	text.setColor(sf::Color::White);
	text.setPosition(position);
}
