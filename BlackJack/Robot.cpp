#include "Robot.h"
#include "Player.h"
#include "Logger.h"
#include "PlayState.h"
#include "BlackJack.h"
#include "Card.h"

using namespace BlackJack;

const int HIT = HIT_BUTTON_X + 10;
const int DOUBLE = DOUBLE_BUTTON_X + 10;
const int STAY = STAY_BUTTON_X + 10;

Robot::Robot()
{
}


Robot::~Robot()
{
}

void Robot::makeBet(Player* player)
{
	LOG_DEBUG("Robot betting");
	player->incrementBet(30);
}

PlayState* Robot::play(PlayState* play, const Card* dealerCard)
{
	LOG_DEBUG("Robot staying");
	int dealerValue = dealerCard->getRank();
	int handValue = m_cardCalculator.getCardValue(play->getPlayer()->getMyCards());
	if (handValue == 11)
	{
		return play->click(DOUBLE, BUTTON_Y + 10);
	}
	else if (handValue < 12|| ((dealerValue > 6 || dealerValue == 1) && handValue < 16))
	{
		return play->click(HIT, BUTTON_Y + 10);
	}
	
	return play->click(STAY, BUTTON_Y + 10);
}