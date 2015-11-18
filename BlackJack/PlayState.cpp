#include "PlayState.h"
#include "Player.h"
#include "Game.h"
#include <iostream>

PlayState::PlayState(Game* game, PokerTable* table)
	:m_game(game), m_table(table)
{
}


PlayState::~PlayState()
{
}

void PlayState::draw()
{
	doDraw();
}

void PlayState::init(Player* p)
{
	m_player = p;
}

PlayState* PlayState::click(int x, int y)
{
	throw "Unhandled Click";
}
//void PlayState::init()
//{
//	m_state = Play::Unknown;
//}

//void PlayState::setState(Play state)
//{
//	m_state = state;
//}

//void PlayState::setChoice(PlayerBank& bank, Play choice)
//{
//	m_state = choice;
//	if (m_state == Play::Double)
//	{
//		bank.incrementBet(bank.getBet());
//	}
//	else if (m_state == Play::Bust)
//	{
//		bank.decrementBet(bank.getBet());
//	}
//}

//PlayState::Play PlayState::getChoice() const
//{
//	return m_state;
//}