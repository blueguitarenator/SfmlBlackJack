#pragma once
#include "PlayStateHit.h"
#include "PlayStateStay.h"
#include "PlayStateBegin.h"
#include "PlayStateBust.h"
#include "PlayStateBet.h"
#include "PlayStateDouble.h"
#include "PlayStateSplit.h"

class Player;
class PokerTable;

class PlayStateFactory
{
public:
	PlayStateFactory(Game* game, PokerTable* table);
	~PlayStateFactory();

	void resetPlayState(Player* p);
	void createBetState(Player* p);
private:
	PlayStateHit m_playHit;
	PlayStateDouble m_playDouble;
	PlayStateSplit m_playSplit;
	PlayStateStay m_playStay;
	PlayStateBegin m_playBegin;
	PlayStateBust m_playBust;
	PlayStateBet m_playBet;
};

