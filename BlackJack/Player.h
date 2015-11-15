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

	// bet
	bool makeBetDone();
	int getBet() const { return m_bet; }
	void addHumanBet(int value);

	// play
	void setPlayChoice(BlackJack::Play play);
	BlackJack::Play getPlayChoice();

	// money
	int getBank() const { return 500; }
	Player* getNextPlayer() { return m_nextPlayer; }
private:
	std::vector<const Card*> m_myCards;
	int m_bet;
	std::string m_name;
	Player* m_nextPlayer;
	bool m_betDone;
	BlackJack::Play m_playChoice;

};

