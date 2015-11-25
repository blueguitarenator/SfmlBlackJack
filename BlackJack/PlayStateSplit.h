#pragma once
#include "PlayState.h"

class PlayStateBegin;

class PlayStateSplit : public PlayState
{
public:
	PlayStateSplit(Game* game, PokerTable* table);
	~PlayStateSplit();

	PlayState* execute();

	PlayState* doRobotAction();

	void setBegin(PlayStateBegin* begin);
	void doDraw() {}
private:
	PlayStateBegin* m_begin;
};

