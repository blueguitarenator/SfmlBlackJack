#include "PlayStateBet.h"
#include "BlackJack.h"
#include "Player.h"
#include "PokerTable.h"

PlayStateBet::PlayStateBet(Game* game, PokerTable* table)
	:PlayState(game, table)
{
}


PlayStateBet::~PlayStateBet()
{
}

void PlayStateBet::doInit()
{
	m_done = false;
}

PlayState* PlayStateBet::click(int x, int y)
{
	int value = m_hitDetector.hitChip(x, y);
	if (value != -1)
	{
		if (value != BlackJack::DONE_BET)
		{
			m_done = true;
		}
		else
		{
			if (m_player->getNextPlayer() != nullptr)
			{
				return m_player->getNextPlayer()->getBetState();
			}
			else
			{
				return nullptr;
			}
		}
	}
	return this;
}

void PlayStateBet::doDraw()
{
	if (m_done)
	{
		m_table->drawChipsDone();
	}
}

PlayState* PlayStateBet::execute()
{
	return this;
}

