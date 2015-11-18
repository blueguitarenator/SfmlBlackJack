#include "PlayStateBegin.h"
#include "PlayStateHit.h"
#include "PlayStateStay.h"
#include "PokerTable.h"

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

PlayState* PlayStateBegin::execute()
{
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
	return this;
}