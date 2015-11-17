#include "GameStateCheckBlackJack.h"
#include "Game.h"
#include "GameStatePayout.h"

GameStateCheckBlackJack::GameStateCheckBlackJack(Game* game, PokerTable* table)
	:GameState(game, table)
{
}


GameStateCheckBlackJack::~GameStateCheckBlackJack()
{
}

void GameStateCheckBlackJack::setPayout(GameStatePayout* payout)
{
	m_payout = payout;
}

GameState* GameStateCheckBlackJack::run()
{
	if (m_game->checkDealerBlackJack())
	{
		m_nextState = m_payout->init();
	}
	else
	{
		m_game->checkPlayerBlackJack();
		m_game->initFirstPlayer();
	}
	return m_nextState->init();
}