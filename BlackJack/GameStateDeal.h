#pragma once
#include "GameState.h"

class GameStateDeal : public GameState
{
public:
	GameStateDeal(Game* game, PokerTable* table);
	~GameStateDeal();

	GameState* run();
	void getDealerCards(std::vector<const Card*>& cards, const Dealer* dealer);
private:
	GameStateDeal(const GameStateDeal&);                 // Prevent copy-construction
	GameStateDeal& operator=(const GameStateDeal&);      // Prevent assignment

};

