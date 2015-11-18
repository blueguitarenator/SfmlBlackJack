#include "PlayStateHit.h"
#include "PlayStateStay.h"
#include "PokerTable.h"
#include "Game.h"

PlayStateHit::PlayStateHit(Game* game, PokerTable* table)
	:PlayState(game, table), m_done(false)
{
}


PlayStateHit::~PlayStateHit()
{
}

void PlayStateHit::setStay(PlayStateStay* stay)
{
	m_stay = stay;
}

void PlayStateHit::setBust(PlayStateBust* bust)
{
	m_bust = bust;
}

PlayState* PlayStateHit::execute()
{
	if (!m_done)
	{
		m_done = true;
		Dealer* dealer = m_game->getDealer();
		
		dealer->hit(m_player);
		if (m_cardCalculator.getCardValue(m_player->getMyCards()) > 21)
		{
			return m_bust;
		}
	}
	return this;
}

void PlayStateHit::doDraw()
{
	m_table->getPlayGraphics()->drawHit();
	m_table->getPlayGraphics()->drawStay();
}

PlayState* PlayStateHit::click(int x, int y)
{
	if (m_hitDetector.hitHit(x, y))
	{
		m_done = false;
	}
	if (m_hitDetector.hitStay(x, y))
	{
		return m_stay;
	}
	return this;
}