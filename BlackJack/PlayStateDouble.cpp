#include "PlayStateDouble.h"
#include "Player.h"
#include "PlayStateStay.h"

PlayStateDouble::PlayStateDouble(Game* game, PokerTable* table)
	:PlayState(game, table)
{
}


PlayStateDouble::~PlayStateDouble()
{
}

void PlayStateDouble::setStay(PlayStateStay* stay)
{
	m_stay = stay;
}

PlayState* PlayStateDouble::execute()
{
	m_player->incrementBet(m_player->getBet() * 2);
	return m_stay;
}
