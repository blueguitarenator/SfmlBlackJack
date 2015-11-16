#pragma once
#include <SFML/Graphics.hpp>
#include "PokerTable.h"
#include "Deck.h"
#include "Shoe.h"
#include "Dealer.h"
#include "Player.h"
#include "BlackJack.h"
#include "PokerTable.h"

#include <vector>

class GameState;

class Game
{
public:
	
	Game(sf::RenderWindow& window);
	~Game();

	void paint(GameState* state);
	bool placeBetsRoundDone();
	bool placeBetsPlayerDone();
	void deal();
	void checkPlayerBlackJack();
	bool checkDealerBlackJack();
	void setPlayerBet(int value);
	bool playForPlayerDone();
	bool playForRoundDone();
	bool playHit();
	bool playDouble();
	void setPlayerPlay(BlackJack::Play play);
	void initFirstPlayer();
	bool dealerHitDone();
	void payout();
	void roundOver();
	PokerTable* getTable();
private:
	// attributes
	PokerTable m_pokerTable;
	Shoe m_shoe;
	Deck m_deck[6];
	
	Dealer m_dealer;
	Player m_player1;
	Player m_player2;
	Player m_player3;
	Player* m_currentPlayer;

	// operations
};

