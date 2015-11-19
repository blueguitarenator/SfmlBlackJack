#include "PlayStateBust.h"
#include "PokerTable.h"
#include "Player.h"

PlayStateBust::PlayStateBust(Game* game, PokerTable* table)
	:PlayState(game, table)
{
}


PlayStateBust::~PlayStateBust()
{
}

PlayState* PlayStateBust::execute()
{
	return m_player->getNextPlayer()->getPlayState();
}

void PlayStateBust::doDraw()
{

}