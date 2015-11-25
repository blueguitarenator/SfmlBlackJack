#pragma once
#include "PlayState.h"

class PlayStateHit;
class PlayStateStay;
class PlayStateDouble;
class PlayStateSplit;

class PlayStateBegin : public PlayState
{
public:
	PlayStateBegin(Game* game, PokerTable* table);
	~PlayStateBegin();

	void setHit(PlayStateHit* hit);
	void setStay(PlayStateStay* stay);
	void setDouble(PlayStateDouble* double_);
	void setSplit(PlayStateSplit* split);
	PlayState* execute();
	void doDraw();
	PlayState* click(int x, int y);
	PlayState* doRobotAction();
private:
	PlayStateHit* m_hit;
	PlayStateStay* m_stay;
	PlayStateDouble* m_double;
	PlayStateSplit* m_split;
};

