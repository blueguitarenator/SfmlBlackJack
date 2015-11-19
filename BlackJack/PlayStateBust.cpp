#include "PlayStateBust.h"
#include "PokerTable.h"
#include "Player.h"
#include "Dealer.h"
#include "Game.h"

PlayStateBust::PlayStateBust(Game* game, PokerTable* table)
	:PlayState(game, table)
{
}


PlayStateBust::~PlayStateBust()
{
}

PlayState* PlayStateBust::execute()
{
	Dealer* dealer = m_game->getDealer();
	dealer->playerBusted(m_player);
	if (m_player->getNextPlayer() != nullptr)
	{
		return m_player->getNextPlayer()->getPlayState();
	}
	return nullptr;
}

void PlayStateBust::doDraw()
{

}