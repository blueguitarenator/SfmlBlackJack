#include "GameStatePayout.h"
#include "Game.h"

GameStatePayout::GameStatePayout(Game* game, PokerTable* table)
	:GameState(game, table)
{
}

GameStatePayout::~GameStatePayout()
{
}

GameState* GameStatePayout::doClick(int x, int y)
{
	if (m_hitDetector.hitContinue(x, y))
	{
		return m_nextState->init();
	}
	return this;
}

GameState* GameStatePayout::doRun()
{
	if (m_game->atLeastOnePlayer())
	{
		m_game->payout();
	}
	return this;
}

void GameStatePayout::draw()
{
	m_table->drawPayout();
}