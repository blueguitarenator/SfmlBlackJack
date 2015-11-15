#include "GameEngine.h"
#include <iostream>

using namespace std;
using namespace BlackJack;

GameEngine::GameEngine(Game& game)
	:m_game(game)
{
	m_gameState = State::NewGame;
}


GameEngine::~GameEngine()
{
}

void GameEngine::mouseClick(int x, int y)
{
	if (m_gameState == State::PlaceBets)
	{
		int value = m_hitDetector.hitChip(x, y);
		if (value != -1)
		{
			m_game.setPlayerBet(value);
			m_game.paint(m_gameState);
		}
	}
	else if (m_gameState == State::Play)
	{
		Play p = m_hitDetector.hitPlay(x, y);
		if (p != Play::Unknown)
		{
			m_game.setPlayerPlay(p);
			m_game.paint(m_gameState);
		}
	}
}

void GameEngine::handlePollEvent()
{
	if (m_gameState == State::NewGame)
	{
		m_gameState = State::PlaceBets;
		m_game.initFirstPlayer();
		m_game.paint(m_gameState);
	}
	else if (m_gameState == State::PlaceBets)
	{
		if (m_game.placeBetsPlayerDone())
		{
			m_game.paint(m_gameState);
		}
		if (m_game.placeBetsRoundDone())
		{
			m_gameState = State::Deal;
			m_game.paint(m_gameState);
		}
	}
	else if (m_gameState == State::Deal)
	{
		m_game.deal();
		m_gameState = State::Play;
		m_game.initFirstPlayer();
		m_game.paint(m_gameState);
	}
	else if (m_gameState == State::Play)
	{
		if (m_game.playForPlayerDone())
		{
			m_game.paint(m_gameState);
		}
		if (m_game.playForRoundDone())
		{
			m_gameState = State::DealerHit;
			m_game.paint(m_gameState);
		}
		else if (m_game.playHit())
		{
			m_game.paint(m_gameState);
		}
		else if (m_game.playDouble())
		{
			m_game.paint(m_gameState);
		}
	}
	else if (m_gameState == State::DealerHit)
	{
		if (m_game.dealerHitDone())
		{
			m_gameState = State::Payout;
		}
		m_game.paint(m_gameState);
	}

}
