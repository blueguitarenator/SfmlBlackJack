#include "PlayStateStay.h"
#include "Player.h"


PlayStateStay::PlayStateStay(Game* game, PokerTable* table)
	:PlayState(game, table)
{
}


PlayStateStay::~PlayStateStay()
{
}

PlayState* PlayStateStay::execute()
{
	Player* nextPlayer = m_player->getNextPlayer();
	if (nextPlayer == nullptr)
	{
		return nullptr;
	}
	return nextPlayer->getPlayState();
}

void PlayStateStay::doDraw()
{

}
