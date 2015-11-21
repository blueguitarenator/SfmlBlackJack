#include "Robot.h"
#include "Player.h"
#include "Logger.h"
#include "PlayState.h"
#include "BlackJack.h"
#include "Card.h"

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
	int handValue = m_cardCalculator.getCardValue(play->getPlayer()->getMyCards());
	if (handValue < 12)
	{
		return play->click(BlackJack::HIT_BUTTON_X + 10, BlackJack::BUTTON_Y + 10);
	}
	
	return play->click(BlackJack::STAY_BUTTON_X + 10, BlackJack::BUTTON_Y + 10);
}