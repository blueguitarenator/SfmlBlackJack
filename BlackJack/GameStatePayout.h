#pragma once
#include "GameState.h"

class GameStatePayout : public GameState
{
public:
	GameStatePayout(Game* game, PokerTable* table);
	~GameStatePayout();

	GameState* run();
	GameState* click(int x, int y);
	void draw();
private:
	GameStatePayout(const GameStatePayout&);                 // Prevent copy-construction
	GameStatePayout& operator=(const GameStatePayout&);      // Prevent assignment

};


