#pragma once
#include "PlayState.h"

class PlayStateBet : public PlayState
{
public:
	PlayStateBet(Game* game, PokerTable* table);
	~PlayStateBet();

	void doInit();
	void doDraw();
	PlayState* execute();
	PlayState* click(int x, int y);
	PlayState* doRobotAction();
private:
	bool m_done;
};

