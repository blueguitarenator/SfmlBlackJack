#include "PlayStateDouble.h"
#include "Player.h"
#include "PlayStateStay.h"
#include "Dealer.h"
#include "Game.h"

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
	m_player->incrementBet(m_player->getBet());
	Dealer* dealer = m_game->getDealer();
	dealer->hit(m_player);
	return m_stay;
}
