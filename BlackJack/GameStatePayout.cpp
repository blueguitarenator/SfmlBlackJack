#include "GameStatePayout.h"
#include "Game.h"

GameStatePayout::GameStatePayout(Game* game, PokerTable* table)
	:GameState(game, table)
{
}

GameStatePayout::~GameStatePayout()
{
}

GameState* GameStatePayout::click(int x, int y)
{
	if (m_hitDetector.hitContinue(x, y))
	{
		return m_nextState->init();
	}
	return this;
}

GameState* GameStatePayout::run()
{
	m_game->payout();
	return this;
}

void GameStatePayout::draw()
{
	m_table->drawPayout();
}