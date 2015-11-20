#include "GameStateDealerHit.h"
#include "Game.h"


GameStateDealerHit::GameStateDealerHit(Game* game, PokerTable* table)
	:GameState(game, table)
{
}


GameStateDealerHit::~GameStateDealerHit()
{
}

GameState* GameStateDealerHit::run()
{
	if (!m_game->atLeastOnePlayer() || m_game->dealerHitDone())
	{
		return m_nextState->init();
	}
	return this;
}
