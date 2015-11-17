#include "GameStatePlaceBets.h"
#include "Game.h"
#include "BlackJack.h"


GameStatePlaceBets::GameStatePlaceBets(Game* game, PokerTable* table)
	:GameState(game, table), m_thisPlayerBet(false)
{
}


GameStatePlaceBets::~GameStatePlaceBets()
{
}

void GameStatePlaceBets::doInit()
{
	m_thisPlayerBet = false;
}

GameState* GameStatePlaceBets::click(int x, int y)
{	
	int value = m_hitDetector.hitChip(x, y);
	if (value != -1)
	{
		m_thisPlayerBet |= value != BlackJack::DONE_BET;
		if (!m_thisPlayerBet && value == BlackJack::DONE_BET)
		{
			return this;
		}
		if (value == BlackJack::DONE_BET)
		{
			m_thisPlayerBet = false;
		}
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
	if (m_thisPlayerBet)
	{
		m_table->drawChipsDone();
	}
}