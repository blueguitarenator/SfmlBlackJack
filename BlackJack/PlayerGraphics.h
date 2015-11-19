#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceLoader.h"

class Player;

class PlayerGraphics
{
public:
	PlayerGraphics(sf::RenderWindow& window, const Player& player, float myOffset);
	~PlayerGraphics();

	void drawBetCircle();
	void drawBank();
	void drawBet();
	void drawWin();
	void drawCards();
private:
	float m_myOffset;
	ResourceLoader m_resourceLoader;
	const Player& m_player;
	sf::RenderWindow& m_window;
	sf::CircleShape m_betCircle;
	sf::Font m_bankFont;
	sf::Text m_bankText;
	sf::Text m_betText;
	sf::Text m_winText;
	sf::Texture m_cardTexture;
	sf::Sprite m_cardSprite;
};

