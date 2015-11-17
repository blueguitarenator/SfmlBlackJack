#pragma once
#include <SFML/Graphics.hpp>

class ChipGraphics
{
public:
	ChipGraphics(sf::RenderWindow& window);
	~ChipGraphics();

	void draw();
	void drawDone();
private:
	sf::RenderWindow& m_window;
	sf::Texture m_chipTexture;
	sf::CircleShape m_oneChipCircle;
	sf::CircleShape m_fiveChipCircle;
	sf::CircleShape m_tenChipCircle;
	sf::CircleShape m_twentyFiveChipCircle;
	sf::CircleShape m_doneChipCircle;

	sf::Font m_doneFont;
	sf::Text m_doneText;
};

