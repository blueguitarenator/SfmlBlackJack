#pragma once
#include <SFML/Graphics.hpp>

class Card;
class Dealer;
class Player;

class PokerTable
{
private:

	struct Spot
	{
		float x;
		float y;
		sf::Texture texture;
		sf::Sprite sprite;
		const std::vector<const Card*>* cards;
	};

public:
	PokerTable(sf::RenderWindow* window);
	~PokerTable();

	void refresh(const Dealer* dealer, const Player* player1, const Player* player2, const Player* player3);

private:
	sf::RenderWindow* m_window;
	sf::Texture m_feltTexture;
	sf::Sprite m_feltSprite;
	sf::Font m_titleFont;

	sf::Texture m_chipTexture;
	sf::Sprite m_p1ChipSprite;

	Spot m_dealerCards;
	Spot m_p1Cards;
	Spot m_p2Cards;
	Spot m_p3Cards;

	void drawAll();
	void drawText();
	void drawChips(sf::RenderWindow* window);
	void drawPlayerCards(sf::RenderWindow* window, PokerTable::Spot& spot);
};


