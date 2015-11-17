#pragma once
#include <vector>
#include "HitDetector.h"

class Game;
class Dealer;
class Card;
class PokerTable;

class GameState
{
public:
	GameState(Game* game, PokerTable* table);
	virtual ~GameState();

	GameState* doRun();
	GameState* doClick(int x, int y);
	virtual GameState* run() = 0;
	
	virtual GameState* click(int x, int y);
	virtual void draw();
	virtual void getDealerCards(std::vector<const Card*>& cards, const Dealer* dealer);

	GameState* init();
	virtual void doInit() {}
	void setNextState(GameState* nextState);
protected:
	PokerTable* m_table;
	Game* m_game;
	HitDetector m_hitDetector;
	bool m_done;
	GameState* m_nextState;

private:
	GameState(const GameState&);                 // Prevent copy-construction
	GameState& operator=(const GameState&);      // Prevent assignment
};

