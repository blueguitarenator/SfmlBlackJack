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

PlayState* PlayState::robotAction()
{
	return doRobotAction();
}

void PlayState::draw()
{
	doDraw();
}

void PlayState::init()
{
	doInit();
}

PlayState* PlayState::click(int x, int y)
{
	throw "Unhandled Click";
}
