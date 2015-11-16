#pragma once
#include "GameState.h"

class GameStatePlay : public GameState
{
public:
	GameStatePlay(Game* game, PokerTable* table);
	~GameStatePlay();

	GameState* run();
	GameState* click(int x, int y);
	void draw();
	void getDealerCards(std::vector<const Card*>& cards, const Dealer* dealer);
private:
	GameStatePlay(const GameStatePlay&);                 // Prevent copy-construction
	GameStatePlay& operator=(const GameStatePlay&);      // Prevent assignment

};

