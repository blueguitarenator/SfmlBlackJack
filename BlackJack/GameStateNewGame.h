#pragma once
#include "GameState.h"

class GameStateNewGame : public GameState
{
public:
	GameStateNewGame(Game* game, PokerTable* table);
	~GameStateNewGame();

	GameState* doRun();

private:
	GameStateNewGame(const GameStateNewGame&);                 // Prevent copy-construction
	GameStateNewGame& operator=(const GameStateNewGame&);      // Prevent assignment

};

