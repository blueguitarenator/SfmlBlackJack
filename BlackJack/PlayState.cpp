#include "PlayState.h"



PlayState::PlayState()
	: m_state(Play::Unknown)
{
}


PlayState::~PlayState()
{
}

void PlayState::init()
{
	m_state = Play::Unknown;
}

void PlayState::setState(Play state)
{
	m_state = state;
}

void PlayState::setChoice(PlayerBank& bank, Play choice)
{
	m_state = choice;
	if (m_state == Play::Double)
	{
		bank.incrementBet(bank.getBet());
	}
	else if (m_state == Play::Bust)
	{
		bank.decrementBet(bank.getBet());
	}
}

PlayState::Play PlayState::getChoice() const
{
	return m_state;
}