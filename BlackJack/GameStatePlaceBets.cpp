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
		m_game->paint(this);
	}
	return this;
}

GameState* GameStatePlaceBets::run()
{
	GameState* state = this;
	m_game->placeBetsPlayerDone();

	if (m_game->placeBetsRoundDone())
	{
		state = m_nextState->init();
	}
	m_game->paint(this);
	return state;
}

void GameStatePlaceBets::draw()
{
	m_table->drawChips();
}