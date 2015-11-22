#include "PlayStateHit.h"
#include "PlayStateStay.h"
#include "PokerTable.h"
#include "Game.h"

PlayStateHit::PlayStateHit(Game* game, PokerTable* table)
	:PlayState(game, table), m_selected(true)
{
}


PlayStateHit::~PlayStateHit()
{
}

void PlayStateHit::doInit()
{
	m_selected = true;
}

PlayState*PlayStateHit::doRobotAction()
{
	return m_player->robotPlay(this, m_game->getDealer()->getShowCard());
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
	if (m_selected)
	{
		m_selected = false;
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
	m_table->getPlayGraphics()->drawHit(true);
	m_table->getPlayGraphics()->drawStay(false);
	m_table->getPlayGraphics()->drawDouble(false);
}

PlayState* PlayStateHit::click(int x, int y)
{
	if (m_hitDetector.hitHit(x, y))
	{
		m_selected = true;
	}
	else if (m_hitDetector.hitStay(x, y))
	{
		return m_stay;
	}
	return this;
}