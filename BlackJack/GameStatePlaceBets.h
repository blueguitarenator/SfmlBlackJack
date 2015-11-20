#pragma once
#include "GameState.h"

class PlayState;

class GameStatePlaceBets : public GameState
{
public:
	GameStatePlaceBets(Game* game, PokerTable* table);
	~GameStatePlaceBets();

	void doInit();
	GameState* run();
	GameState* click(int x, int y);
	void draw();
private:
	GameStatePlaceBets(const GameStatePlaceBets&);                 // Prevent copy-construction
	GameStatePlaceBets& operator=(const GameStatePlaceBets&);      // Prevent assignment

	PlayState* m_playState;

};