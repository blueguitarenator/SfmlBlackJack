#include "PlayStateFactory.h"
#include "Player.h"


PlayStateFactory::PlayStateFactory(Game* game, PokerTable* table)
	:m_playBegin(game, table), 
	m_playHit(game, table), 
	m_playStay(game, table), 
	m_playBust(game, table),
	m_playBet(game, table),
	m_playDouble(game, table),
	m_playSplit(game, table)
{
}


PlayStateFactory::~PlayStateFactory()
{
}

void PlayStateFactory::createBetState(Player* p)
{
	m_playBet.setPlayer(p);
	p->initBetState(&m_playBet);
}

void PlayStateFactory::resetPlayState(Player* p)
{
	m_playBegin.setPlayer(p);
	m_playDouble.setPlayer(p);
	m_playStay.setPlayer(p);
	m_playHit.setPlayer(p);
	m_playBust.setPlayer(p);
	m_playSplit.setPlayer(p);
	m_playBegin.init();
	m_playHit.init();
	m_playStay.init();
	m_playBust.init();
	m_playDouble.init();
	m_playSplit.init();

	m_playBegin.setHit(&m_playHit);
	m_playBegin.setDouble(&m_playDouble);
	m_playBegin.setStay(&m_playStay);
	m_playBegin.setSplit(&m_playSplit);
	
	m_playHit.setBust(&m_playBust);
	m_playHit.setStay(&m_playStay);

	m_playDouble.setStay(&m_playStay);

	p->initPlayState(&m_playBegin);
}