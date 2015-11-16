#pragma once
#include <vector>
#include "BlackJack.h"
#include "Card.h"
#include "CardCalculator.h"

class Shoe;
class Player;

class Dealer
{
public:
	Dealer(Shoe* shoe, Player* p1, Player* p2, Player* p3);
	~Dealer();

	void deal();
	void checkBlackJack(Player* player);
	void newGame();
	void getMyCards(std::vector<const Card*>& cards, BlackJack::State state) const;
	const Card* getShowCard() const;
	void hit(Player* player);
	bool hitPastSoft17();
	void payout(Player* player, bool blackJack = false);
	void gameOver();
private:
	// attributes
	int m_bank;
	std::vector<const Card*> m_myCards;
	Card m_downCard;
	CardCalculator m_cardCalculator;

	Shoe* m_shoe;
	Player* m_player1;
	Player* m_player2;
	Player* m_player3;

	// operations
	bool isBust(const std::vector<const Card*>* cards);
};

