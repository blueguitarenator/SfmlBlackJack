#include "Robot.h"
#include "Player.h"
#include "Logger.h"
#include "PlayState.h"
#include "BlackJack.h"

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

PlayState* Robot::play(PlayState* play)
{
	LOG_DEBUG("Robot staying");
	return play->click(BlackJack::STAY_BUTTON_X + 10, BlackJack::BUTTON_Y + 10);
}