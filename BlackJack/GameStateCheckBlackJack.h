#pragma once
#include "GameState.h"

class GameStatePayout;

class GameStateCheckBlackJack : public GameState
{
public:
	GameStateCheckBlackJack(Game* game, PokerTable* table);
	~GameStateCheckBlackJack();

	GameState* run();
	void setPayout(GameStatePayout* payout);

private:
	GameStateCheckBlackJack(const GameStateCheckBlackJack&);                 // Prevent copy-construction
	GameStateCheckBlackJack& operator=(const GameStateCheckBlackJack&);      // Prevent assignment

	GameStatePayout* m_payout;
};

