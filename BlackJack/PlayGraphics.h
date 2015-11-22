#pragma once
#include <SFML/Graphics.hpp>

class PlayGraphics
{
public:
	PlayGraphics(sf::RenderWindow& window);
	~PlayGraphics();

	void drawHit(bool isActive);
	void drawStay(bool isActive);
	void drawDouble(bool isActive);
	void drawSplit(bool isActive);

private:
	sf::RenderWindow& m_window;
	sf::RectangleShape m_button;

	sf::Font m_buttonFont;
	sf::Text m_buttonText;

	void doDraw(sf::RectangleShape& button, const std::string& text, float x, bool isActive);
};

