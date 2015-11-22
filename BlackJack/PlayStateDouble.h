#pragma once
#include "PlayState.h"

class PlayStateStay;

class PlayStateDouble : public PlayState
{
public:
	PlayStateDouble(Game* game, PokerTable* table);
	~PlayStateDouble();

	PlayState* execute();
	void doDraw();
	void setStay(PlayStateStay* stay);
private:
	PlayStateStay* m_stay;
};

