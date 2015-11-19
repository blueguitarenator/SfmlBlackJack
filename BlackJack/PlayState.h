#pragma once
#include "HitDetector.h"
#include "CardCalculator.h"

class Player;
class PokerTable;
class Game;

class PlayState
{
public:

	PlayState(Game* game, PokerTable* table);
	~PlayState();
	void init();
	virtual void doInit() {}
	virtual PlayState* execute() = 0;
	void draw();
	virtual PlayState* click(int x, int y);
	const Player* getPlayer() const { return m_player; }
	void setPlayer(Player* p) { m_player = p; }

protected:
	Player* m_player;
	HitDetector m_hitDetector;
	PokerTable* m_table;
	Game* m_game;
	CardCalculator m_cardCalculator;

	// operations
	virtual void doDraw() = 0;

};

