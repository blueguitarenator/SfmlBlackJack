#pragma once
#include "PlayState.h"

class PlayStateStay : public PlayState
{
public:
	PlayStateStay(Game* game, PokerTable* table);
	~PlayStateStay();

	PlayState* execute();
	void doDraw();
};

