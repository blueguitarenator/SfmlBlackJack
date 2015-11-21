#pragma once
#include "GameState.h"

class PlayState;

class GameStatePlay : public GameState
{
public:

	GameStatePlay(Game* game, PokerTable* table);
	~GameStatePlay();

	void doInit();
	GameState* doRun();
	GameState* doClick(int x, int y);
	GameState* doRobot();

	void draw();
	void getDealerCards(std::vector<const Card*>& cards, const Dealer* dealer);

private:
	GameStatePlay(const GameStatePlay&);                 // Prevent copy-construction
	GameStatePlay& operator=(const GameStatePlay&);      // Prevent assignment

	PlayState* m_playState;

};

