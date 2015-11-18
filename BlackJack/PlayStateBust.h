#pragma once
#include "PlayState.h"

class PlayStateBust : public PlayState
{
public:
	PlayStateBust(Game* game, PokerTable* table);
	~PlayStateBust();

	PlayState* execute();
	void doDraw();
};

