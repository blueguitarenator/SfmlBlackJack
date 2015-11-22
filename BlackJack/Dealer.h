#pragma once
#include <vector>
#include "BlackJack.h"
#include "Card.h"
#include "CardCalculator.h"

class Shoe;
class Player;
class GameState;

class Dealer
{
public:
	Dealer(Shoe* shoe, Player* p1, Player* p2, Player* p3);
	~Dealer();

	const std::vector<const Card*>* getCards() const;
	void deal();
	void newGame();
	void getMyCards(std::vector<const Card*>& cards, GameState* state) const;
	const Card* getShowCard() const;
	void hit(Player* player);
	bool hitPastSoft17();
	void payout(Player* player);
	void payoutBlackjack(Player* player);
	void gameOver();
	const Card* getDownCard() const;
	void getPlayers(std::vector<Player*>& players) const;
	void playerBusted(Player* player);
	int getBank() const { return m_bank; }
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

