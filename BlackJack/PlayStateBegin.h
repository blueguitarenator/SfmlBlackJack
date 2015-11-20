#pragma once
#include "PlayState.h"

class PlayStateHit;
class PlayStateStay;
class PlayStateDouble;

class PlayStateBegin : public PlayState
{
public:
	PlayStateBegin(Game* game, PokerTable* table);
	~PlayStateBegin();

	void setHit(PlayStateHit* hit);
	void setStay(PlayStateStay* stay);
	void setDouble(PlayStateDouble* double_);
	PlayState* execute();
	void doDraw();
	PlayState* click(int x, int y);
private:
	PlayStateHit* m_hit;
	PlayStateStay* m_stay;
	PlayStateDouble* m_double;
};

