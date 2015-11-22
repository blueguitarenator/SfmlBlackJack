#pragma once
#include "GameState.h"

class PlayState;

class GameStatePlaceBets : public GameState
{
public:
	GameStatePlaceBets(Game* game, PokerTable* table);
	~GameStatePlaceBets();

	void doInit();
	GameState* doRun();
	GameState* doClick(int x, int y);
	GameState* doRobot();
	void draw();
private:
	GameStatePlaceBets(const GameStatePlaceBets&);                 // Prevent copy-construction
	GameStatePlaceBets& operator=(const GameStatePlaceBets&);      // Prevent assignment

	PlayState* m_playState;

};