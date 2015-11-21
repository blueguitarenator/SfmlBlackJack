#include "PlayStateStay.h"
#include "Player.h"
#include "PokerTable.h"

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
	m_player->setIsActive(false);
	if (nextPlayer == nullptr)
	{
		return nullptr;
	}
	nextPlayer->setIsActive(true);

	return nextPlayer->getPlayState();
}

void PlayStateStay::doDraw()
{
	m_table->getPlayGraphics()->drawHit(false);
	m_table->getPlayGraphics()->drawStay(true);
}
