#pragma once
#include "PlayState.h"

class PlayStateHit;
class PlayStateStay;

class PlayStateBegin : public PlayState
{
public:
	PlayStateBegin(Game* game, PokerTable* table);
	~PlayStateBegin();

	void setHit(PlayStateHit* hit);
	void setStay(PlayStateStay* stay);
	PlayState* execute();
	void doDraw();
	PlayState* click(int x, int y);
private:
	PlayStateHit* m_hit;
	PlayStateStay* m_stay;
};

