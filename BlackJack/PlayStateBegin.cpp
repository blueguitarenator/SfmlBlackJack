#include "PlayStateBegin.h"
#include "PlayStateHit.h"
#include "PlayStateStay.h"
#include "PlayStateDouble.h"
#include "PokerTable.h"
#include "Player.h"

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
	m_table->getPlayGraphics()->drawHit();
	m_table->getPlayGraphics()->drawStay();
	m_table->getPlayGraphics()->drawDouble();
	m_table->getPlayGraphics()->drawSplit();
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