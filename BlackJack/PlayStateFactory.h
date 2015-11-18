#pragma once
#include "PlayStateHit.h"
#include "PlayStateStay.h"
#include "PlayStateBegin.h"
#include "PlayStateBust.h"

class Player;
class PokerTable;

class PlayStateFactory
{
public:
	PlayStateFactory(Game* game, PokerTable* table);
	~PlayStateFactory();

	void createPlayState(Player* p);
private:
	PlayStateHit m_playHit;
	PlayStateStay m_playStay;
	PlayStateBegin m_playBegin;
	PlayStateBust m_playBust;
};

