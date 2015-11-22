#pragma once
#include <vector>
#include "HitDetector.h"
#include "CardCalculator.h"

class Game;
class Dealer;
class Card;
class PokerTable;

class GameState
{
public:
	GameState(Game* game, PokerTable* table);
	virtual ~GameState();

	GameState* init();
	virtual void doInit() {}

	GameState* run();
	virtual GameState* doRun() = 0;

	GameState* click(int x, int y);
	virtual GameState* doClick(int x, int y);
	
	virtual void draw();
	virtual void getDealerCards(std::vector<const Card*>& cards, const Dealer* dealer);

	void setNextState(GameState* nextState);
	virtual GameState* doRobot() { return this; }
protected:
	PokerTable* m_table;
	Game* m_game;
	HitDetector m_hitDetector;
	CardCalculator m_cardCalculator;
	bool m_done;
	GameState* m_nextState;

private:
	GameState(const GameState&);                 // Prevent copy-construction
	GameState& operator=(const GameState&);      // Prevent assignment
};

