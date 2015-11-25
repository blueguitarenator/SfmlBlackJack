#pragma once
#include <SFML/Graphics.hpp>
#include "PokerTable.h"
#include "Deck.h"
#include "Shoe.h"
#include "Dealer.h"
#include "Player.h"
#include "Robot.h"
#include "PokerTable.h"
#include "PlayStateFactory.h"
#include <vector>

class PlayState;
class GameState;

class Game
{
public:
	
	Game(sf::RenderWindow& window);
	~Game();

	void paint(GameState* state);
	void deal();
	bool dealerHitDone();
	void payout();
	void roundOver();
	PokerTable* getTable();
	PlayState* initPlayState();
	PlayState* initBetState();
	Dealer* getDealer() { return &m_dealer; }
	bool atLeastOnePlayer() const;
	Player* getActivePlayer();
private:
	// attributes
	PokerTable m_pokerTable;
	Shoe m_shoe;
	Deck m_deck[6];
	
	Dealer m_dealer;
	Player m_player1;
	Player m_splitPlayer1;
	Player m_player2;
	Player m_splitPlayer2;
	Player m_player3;
	Player m_splitPlayer3;
	Robot m_robot1;
	Robot m_robot2;
	Robot m_robot3;

	PlayStateFactory m_playStateFactory1;
	PlayStateFactory m_playStateFactory2;
	PlayStateFactory m_playStateFactory3;
	PlayStateFactory m_playStateFactory1s;
	PlayStateFactory m_playStateFactory2s;
	PlayStateFactory m_playStateFactory3s;

	// operations
	void loadShoe();
};

