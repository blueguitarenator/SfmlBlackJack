#pragma once
#include <vector>
#include <string>
#include "BlackJack.h"
#include "PlayerBank.h"

class Card;

class Player
{
public:
	Player(const std::string& name, Player* nextPlayer);
	~Player();

	void pushCard(const Card* card);

	void clearCards();

	const std::vector<const Card*>* getMyCards() const;
	void gameOver();

	// bet
	bool makeBetDone();
	int getBet() const;
	void addHumanBet(int value);
	int busted();

	// play
	void setPlayChoice(BlackJack::Play play);
	BlackJack::Play getPlayChoice() const;

	// money
	int getBank() const;
	Player* getNextPlayer() { return m_nextPlayer; }
	void setWinnings(float value);
	float getWinnings() const;
private:
	std::vector<const Card*> m_myCards;
	PlayerBank m_bank;
	std::string m_name;
	Player* m_nextPlayer;
	bool m_betDone;
	BlackJack::Play m_playChoice;

};

