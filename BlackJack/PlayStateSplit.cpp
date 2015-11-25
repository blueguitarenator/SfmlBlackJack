#include "PlayStateSplit.h"
#include "PlayStateBegin.h"
#include "Game.h"
#include "Player.h"

PlayStateSplit::PlayStateSplit(Game* game, PokerTable* table)
	:PlayState(game, table)
{
}


PlayStateSplit::~PlayStateSplit()
{
}

void PlayStateSplit::setBegin(PlayStateBegin* begin)
{
	m_begin = begin;
}

PlayState* PlayStateSplit::execute()
{
	Player* splitPlayer = m_game->getActivePlayer()->split();
	m_game->getDealer()->hit(m_game->getActivePlayer());
	m_game->getDealer()->hit(splitPlayer);
	return m_begin;
}

PlayState* PlayStateSplit::doRobotAction()
{
	return this;
}
