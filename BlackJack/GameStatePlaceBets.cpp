#include "GameStatePlaceBets.h"
#include "Game.h"


GameStatePlaceBets::GameStatePlaceBets(Game* game, PokerTable* table)
	:GameState(game, table)
{
}


GameStatePlaceBets::~GameStatePlaceBets()
{
}

GameState* GameStatePlaceBets::click(int x, int y)
{	
	int value = m_hitDetector.hitChip(x, y);
	if (value != -1)
	{
		m_game->setPlayerBet(value);
	}
	return this;
}

GameState* GameStatePlaceBets::run()
{
	m_game->placeBetsPlayerDone();

	if (m_game->placeBetsRoundDone())
	{
		return m_nextState->init();
	}
	return this;
}

void GameStatePlaceBets::draw()
{
	m_table->drawChips();
}