#pragma once
#include <SFML/Graphics.hpp>
#include "PokerTable.h"
#include "Card.h"
#include "Deck.h"
#include "Shoe.h"
#include "Dealer.h"
#include "Player.h"
#include "BlackJack.h"
#include <vector>

class Game
{
public:
	
	Game(sf::RenderWindow& window);
	~Game();

	void paint(BlackJack::State state);
	bool placeBetsDone();
	void deal();
	void setPlayerBet(int value);
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
	//void handleBets();
	//void handleHits();
	//void hitPress();
	//void stayPress();
	
	//void refresh();
	
	//void doHandleHit(Player& player, const Card* showCard);
};

