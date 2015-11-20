#pragma once
#include "GameState.h"

class GameStatePayout;
class GameStatePlay;

class GameStateCheckBlackJack : public GameState
{
public:
	GameStateCheckBlackJack(Game* game, PokerTable* table);
	~GameStateCheckBlackJack();

	void doInit();
	GameState* run();
	void setPayout(GameStatePayout* payout);
	void setPlay(GameStatePlay* play);
	void getDealerCards(std::vector<const Card*>& cards, const Dealer* dealer);
private:
	GameStateCheckBlackJack(const GameStateCheckBlackJack&);                 // Prevent copy-construction
	GameStateCheckBlackJack& operator=(const GameStateCheckBlackJack&);      // Prevent assignment

	GameStatePayout* m_payout;
	GameStatePlay* m_play;
};

