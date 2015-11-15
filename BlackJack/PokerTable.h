#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerGraphics.h"
#include "ChipGraphics.h"
#include "PlayGraphics.h"
#include "ResourceLoader.h"
#include "BlackJack.h"

class Dealer;
class Player;

class PokerTable
{
private:
	
	//struct CardSpot
	//{
	//	float x;
	//	float y;
	//	sf::Texture texture;
	//	sf::Sprite sprite;
	//	const std::vector<const Card*>* cards;
	//}; 
	//
	//struct ChipSpot
	//{
	//	float x;
	//	float y;
	//	sf::CircleShape WhiteCircle;
	//};

	//struct ChipOffsets
	//{
	//	float whiteX;
	//	float whiteY;
	//	float hitX;
	//	float hitY;
	//	float stayX;
	//	float stayY;
	//};
	//struct HitStayButtons
	//{
	//	float x;
	//	float y;
	//	sf::CircleShape ButtonCircle;
	//};

public:
	PokerTable(sf::RenderWindow& window, const Player& p1, const Player& p2, const Player& p3, const Dealer& dealer);
	~PokerTable();

	void drawTable();
	void display();
	void drawCards(BlackJack::State state);
private:
	// attributes
	sf::RenderWindow& m_window;
	sf::Texture m_feltTexture;
	sf::Sprite m_feltSprite;
	sf::Font m_titleFont;

	const Dealer& m_dealer;
	PlayerGraphics m_playerGraphics1;
	PlayerGraphics m_playerGraphics2;
	PlayerGraphics m_playerGraphics3;

	ChipGraphics m_chipGraphics;
	PlayGraphics m_playGraphics;

	ResourceLoader m_resourceLoader;

	sf::Texture m_dealerCardTexture;
	sf::Sprite m_dealerCardSprite;

	// operations
	void drawDealerCards(BlackJack::State state);

	//sf::Texture m_chipTexture;
	//sf::Sprite m_p1ChipSprite;

	//sf::Texture m_hitTexture;
	//sf::Texture m_stayTexture;

	//CardSpot m_dealerCards;
	//CardSpot m_p1Cards;
	//CardSpot m_p2Cards;
	//CardSpot m_p3Cards;

	//ChipSpot m_p1Chips = { 0, 0, sf::CircleShape(0) };
	//ChipSpot m_p2Chips = { 0, 0, sf::CircleShape(0) };
	//ChipSpot m_p3Chips = { 0, 0, sf::CircleShape(0) };

	//HitStayButtons m_hitButton = { 0, 0, sf::CircleShape(0) };
	//HitStayButtons m_stayButton = { 0, 0, sf::CircleShape(0) };

	//void drawAll();
	//void drawText();
	//void drawChips(sf::RenderWindow* window);
	//void drawHitStay(sf::RenderWindow* window);
	//void drawPlayerCards(sf::RenderWindow* window, PokerTable::CardSpot& spot);
};


