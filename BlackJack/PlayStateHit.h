#pragma once
#include "PlayState.h"

class PlayStateStay;
class PlayStateBust;

class PlayStateHit : public PlayState
{
public:
	PlayStateHit(Game* game, PokerTable* table);
	~PlayStateHit();

	void doInit();
	PlayState* execute();
	void setStay(PlayStateStay* stay);
	void setBust(PlayStateBust* bust);
	void doDraw();
	PlayState* click(int x, int y);
	PlayState* doRobotAction();
private:
	PlayStateStay* m_stay;
	PlayStateBust* m_bust;
	bool m_selected;

};

