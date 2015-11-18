#include "PlayStateFactory.h"
#include "Player.h"


PlayStateFactory::PlayStateFactory(Game* game, PokerTable* table)
	:m_playBegin(game, table), m_playHit(game, table), m_playStay(game, table), m_playBust(game, table)
{
}


PlayStateFactory::~PlayStateFactory()
{
}

void PlayStateFactory::createPlayState(Player* p)
{
	m_playBegin.init(p);
	m_playHit.init(p);
	m_playStay.init(p);
	m_playBust.init(p);

	m_playBegin.setHit(&m_playHit);
	m_playBegin.setStay(&m_playStay);
	
	m_playHit.setBust(&m_playBust);
	m_playHit.setStay(&m_playStay);

	p->initPlayState(&m_playBegin);
}