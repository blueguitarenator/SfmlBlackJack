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
	GameState* state = this;
	if (m_game->dealerHitDone())
	{
		state = m_nextState->init();
	}
	m_game->paint(this);
	return state;
}