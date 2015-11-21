#pragma once
#include "CardCalculator.h"

class Player;
class PlayState;
class Card;

class Robot
{
public:
	Robot();
	~Robot();

	void makeBet(Player* player);
	PlayState* play(PlayState* play, const Card* dealerCard);

private:
	CardCalculator m_cardCalculator;
};

