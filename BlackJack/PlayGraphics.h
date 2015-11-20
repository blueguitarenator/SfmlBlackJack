#pragma once
#include <SFML/Graphics.hpp>

class PlayGraphics
{
public:
	PlayGraphics(sf::RenderWindow& window);
	~PlayGraphics();

	void drawHit();
	void drawStay();
	void drawDouble();
	void drawSplit();

private:
	sf::RenderWindow& m_window;
	sf::RectangleShape m_hitButton;

	sf::Font m_buttonFont;
	sf::Text m_buttonText;

	void doDraw(sf::RectangleShape& button, const std::string& text, float x);
};

