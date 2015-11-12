#pragma once
#include <SFML/Graphics.hpp>

class Card;
class Dealer;
class Player;

class PokerTable
{
private:

public:
	struct Spot
	{
		int x;
		int y;
		sf::Texture texture;
		sf::Sprite sprite;
		const std::vector<const Card*>* cards;
	};
	enum Slot
	{
		DealerHole,
		P1_1,
		P2_1,
		P3_1,
	};
	PokerTable(sf::RenderWindow* window);
	~PokerTable();

	void setCard(const Card* card, Slot slot);
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
};


