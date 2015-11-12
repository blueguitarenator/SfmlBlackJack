#pragma once
#include <vector>

class Deck;
class Player;
class Card;

class Dealer
{
public:
	Dealer(Deck* deck, Player* p1, Player* p2, Player* p3);
	~Dealer();

	void deal();
	void newGame();
	const std::vector<const Card*>* getMyCards() const
	{ 
		return &m_myCards; 
	}
private:
	std::vector<const Card*> m_myCards;

	//PokerTable* m_table;
	
	Deck* m_deck;
	Player* m_player1;
	Player* m_player2;
	Player* m_player3;
};

