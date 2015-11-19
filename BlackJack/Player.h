#pragma once
#include <vector>
#include <string>
#include "PlayerBank.h"

class Card;
class PlayState;

class Player
{
public:
	Player(const std::string& name, Player* nextPlayer);
	~Player();

	void pushCard(const Card* card);

	void clearCards();

	const std::vector<const Card*>* getMyCards() const;
	void gameOver();

	int getBet() const;
	void incrementBet(int bet);


	int getBank() const;
	Player* getNextPlayer();
	void setWinnings(float value);
	float getWinnings() const;

	void initPlayState(PlayState* playState);
	void initBetState(PlayState* playState);
	PlayState* getPlayState() const;
	PlayState* getBetState() const;
	bool isActive() const { return m_isActive; }
	void setIsActive(bool isActive) { m_isActive = isActive; }
private:
	bool m_isActive;
	std::vector<const Card*> m_myCards;
	PlayerBank m_bank;
	int m_bet;
	std::string m_name;
	Player* m_nextPlayer;
	PlayState* m_playState;
	PlayState* m_betState;
};

