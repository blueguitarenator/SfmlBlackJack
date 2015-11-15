#pragma once
#include <vector>
#include <string>
#include "BlackJack.h"

class Card;

class Player
{
public:
	Player(const std::string& name, Player* nextPlayer);
	~Player();

	void pushCard(const Card* card);

	void clearCards();

	const std::vector<const Card*>* getMyCards() const;

	bool makeBetDone();
	int getBet() const { return m_bet; }
	void addHumanBet(int value);

	void makeHitChoice(const Card* dealerShowCard);
	//BlackJack::HitChoice getHitChoice() const;
	void setNoChoice();
	void setStayChoice();
	int getBank() const { return 500; }
	Player* getNextPlayer() { return m_nextPlayer; }
private:
	std::vector<const Card*> m_myCards;
	bool m_isHuman;
	int m_bet;
	std::string m_name;
	//BlackJack::HitChoice m_choice;
	Player* m_nextPlayer;
	bool m_betDone;

};

