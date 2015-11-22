#include "PlayStateBegin.h"
#include "PlayStateHit.h"
#include "PlayStateStay.h"
#include "PlayStateDouble.h"
#include "PokerTable.h"
#include "Player.h"
#include "Game.h"
#include <vector>

using namespace std;

PlayStateBegin::PlayStateBegin(Game* game, PokerTable* table)
	:PlayState(game, table)
{
}


PlayStateBegin::~PlayStateBegin()
{
}

void PlayStateBegin::setHit(PlayStateHit* hit)
{
	m_hit = hit;
}

void PlayStateBegin::setStay(PlayStateStay* stay)
{
	m_stay = stay;
}

void PlayStateBegin::setDouble(PlayStateDouble* double_)
{
	m_double = double_;
}

PlayState* PlayStateBegin::execute()
{
	if (!m_player->isInGame())
	{
		return m_stay;
	}
	return this;
}

void PlayStateBegin::doDraw()
{
	m_table->getPlayGraphics()->drawHit(false);
	m_table->getPlayGraphics()->drawStay(false);
	m_table->getPlayGraphics()->drawDouble(false);
	const vector<const Card*>* cards = m_player->getMyCards();
	if (cards->at(0)->getRank() == cards->at(1)->getRank())
	{
		m_table->getPlayGraphics()->drawSplit(false);
	}
}

PlayState*PlayStateBegin::doRobotAction()
{
	return m_player->robotPlay(this, m_game->getDealer()->getShowCard());
}

PlayState* PlayStateBegin::click(int x, int y)
{
	if (m_hitDetector.hitHit(x, y))
	{
		return m_hit;
	}
	else if (m_hitDetector.hitStay(x, y))
	{
		return m_stay;
	}
	else if (m_hitDetector.hitDouble(x, y))
	{
		return m_double;
	}
	return this;
}