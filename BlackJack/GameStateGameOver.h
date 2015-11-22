#pragma once
#include "GameState.h"

class GameStateGameOver : public GameState
{
public:
	GameStateGameOver(Game* game, PokerTable* table);
	~GameStateGameOver();

	GameState* doRun();

private:
	GameStateGameOver(const GameStateGameOver&);                 // Prevent copy-construction
	GameStateGameOver& operator=(const GameStateGameOver&);      // Prevent assignment

};


