#include "PlayState.h"
#include "Player.h"
#include "Game.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

PlayState::PlayState(Game* game, PokerTable* table)
	:m_game(game), m_table(table)
{
}


PlayState::~PlayState()
{
}

PlayState* PlayState::robotAction()
{
	//this_thread::sleep_for(chrono::milliseconds(1000));
	PlayState* playState = doRobotAction();
	//this_thread::sleep_for(chrono::milliseconds(1000));
	return playState;
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
