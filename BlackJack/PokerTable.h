#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerGraphics.h"
#include "ChipGraphics.h"
#include "PlayGraphics.h"
#include "ResourceLoader.h"

class Dealer;
class Player;
class GameState;

class PokerTable
{	
public:
	PokerTable(sf::RenderWindow& window, const Player& p1, const Player& p2, const Player& p3, const Dealer& dealer);
	~PokerTable();

	void drawTable(GameState* state);
	void drawCards(GameState* state);
	void drawChips();
	void drawChipsDone();
	void drawPayout();
	void display();

	PlayGraphics* getPlayGraphics() { return &m_playGraphics; }
private:
	// attributes
	sf::RenderWindow& m_window;
	sf::Texture m_feltTexture;
	sf::Sprite m_feltSprite;
	sf::Font m_titleFont;

	const Dealer& m_dealer;
	PlayerGraphics m_playerGraphics1;
	PlayerGraphics m_playerGraphics2;
	PlayerGraphics m_playerGraphics3;

	ChipGraphics m_chipGraphics;
	PlayGraphics m_playGraphics;

	ResourceLoader m_resourceLoader;

	sf::Texture m_dealerCardTexture;
	sf::Sprite m_dealerCardSprite;

	sf::RectangleShape m_continueButton;
	sf::Text m_continueText;

	// operations
	void drawDealerCards(GameState* state);
	void drawContinueButton();

};


