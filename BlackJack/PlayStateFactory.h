#pragma once
#include "PlayStateHit.h"
#include "PlayStateStay.h"
#include "PlayStateBegin.h"
#include "PlayStateBust.h"
#include "PlayStateBet.h"
#include "PlayStateDouble.h"

class Player;
class PokerTable;

class PlayStateFactory
{
public:
	PlayStateFactory(Game* game, PokerTable* table);
	~PlayStateFactory();

	void createPlayState(Player* p);
	void createBetState(Player* p);
private:
	PlayStateHit m_playHit;
	PlayStateDouble m_playDouble;
	PlayStateStay m_playStay;
	PlayStateBegin m_playBegin;
	PlayStateBust m_playBust;
	PlayStateBet m_playBet;
};

