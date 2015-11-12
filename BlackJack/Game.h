#pragma once
#include <SFML/Graphics.hpp>
#include "Card.h"
#include "Deck.h"
#include "Shoe.h"
#include "Dealer.h"
#include "Player.h"
#include <vector>

class PokerTable;

class Game
{
public:
	Game(PokerTable* table);
	~Game();

	void handleKeyPressed(sf::Event::KeyEvent keyEvent);
private:
	PokerTable* m_pokerTable;
	Shoe m_shoe;
	Deck m_deck[6];
	
	Dealer m_dealer;
	Player m_player1;
	Player m_player2;
	Player m_player3;

};

