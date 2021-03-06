#pragma once
#include "GameState.h"

class GameStateDealerHit : public GameState
{
public:
	GameStateDealerHit(Game* game, PokerTable* table);
	~GameStateDealerHit();

	GameState* doRun();

private:
	GameStateDealerHit(const GameStateDealerHit&);                 // Prevent copy-construction
	GameStateDealerHit& operator=(const GameStateDealerHit&);      // Prevent assignment
};


