#pragma once
#include "GameState.h"

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

	bool m_thisPlayerBet;
};