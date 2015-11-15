#include "PokerTable.h"
#include "Dealer.h"
#include "Player.h"
#include <vector>

using namespace std;

PokerTable::PokerTable(sf::RenderWindow& window, const Player& p1, const Player& p2, const Player& p3, const Dealer& dealer)
	:m_window(window), 
	m_playerGraphics1(window, p1, 0.0f), 
	m_playerGraphics2(window, p2, 400.0f), 
	m_playerGraphics3(window, p3, 800.0f),
	m_dealer(dealer),
	m_chipGraphics(window)
{
	m_resourceLoader.loadTexture(m_feltTexture, ResourceLoader::FELT);
	m_feltSprite.setTexture(m_feltTexture);

	/*
	float centerOffset = 100.0f;
	m_dealerCards.x = 350.0f + centerOffset;
	m_dealerCards.y = 100;
	m_dealerCards.cards = nullptr;

	m_p1Cards.x = 10.0f + centerOffset;
	m_p1Cards.y = 500;
	m_p1Cards.cards = nullptr;

	m_p2Cards.x = 350.0f + centerOffset;
	m_p2Cards.y = 500;
	m_p2Cards.cards = nullptr;

	m_p3Cards.x = 690.0f + centerOffset;
	m_p3Cards.y = 500;
	m_p3Cards.cards = nullptr;

	if (!m_feltTexture.loadFromFile("felt.png"))
	{
		throw "Could not load felt png";
	}
	m_feltSprite.setTexture(m_feltTexture);

	if (!m_chipTexture.loadFromFile("chips.png"))
	{
		throw "Could not load chip png";
	}
	if (!m_hitTexture.loadFromFile("hit.png"))
	{
		throw "Could not load hit png";
	}
	if (!m_stayTexture.loadFromFile("hit.png"))
	{
		throw "Could not load stay png";
	}

	m_p1Chips.WhiteCircle.setRadius(100);
	m_p1Chips.WhiteCircle.setTexture(&m_chipTexture);
	m_p1Chips.WhiteCircle.setTextureRect(sf::IntRect(3, 3, 83, 83));
	m_p1Chips.WhiteCircle.setScale(.5f, .5f);
	m_p1Chips.WhiteCircle.setPosition(sf::Vector2f(100, 675));

	m_p2Chips.WhiteCircle.setRadius(100);
	m_p2Chips.WhiteCircle.setTexture(&m_chipTexture);
	m_p2Chips.WhiteCircle.setTextureRect(sf::IntRect(3, 3, 83, 83));
	m_p2Chips.WhiteCircle.setScale(.5f, .5f);
	m_p2Chips.WhiteCircle.setPosition(sf::Vector2f(450, 675));

	m_p3Chips.WhiteCircle.setRadius(100);
	m_p3Chips.WhiteCircle.setTexture(&m_chipTexture);
	m_p3Chips.WhiteCircle.setTextureRect(sf::IntRect(3, 3, 83, 83));
	m_p3Chips.WhiteCircle.setScale(.5f, .5f);
	m_p3Chips.WhiteCircle.setPosition(sf::Vector2f(790, 675));

	m_hitButton.x = 100;
	m_hitButton.y = 700;
	m_hitButton.ButtonCircle.setTexture(&m_chipTexture);
	m_hitButton.ButtonCircle.setScale(.5f, .5f);
	m_hitButton.ButtonCircle.setPosition(sf::Vector2f(790, 675));
	*/
}

PokerTable::~PokerTable()
{
}

void PokerTable::drawCards(BlackJack::State state)
{
	m_playerGraphics1.drawCards();
	m_playerGraphics2.drawCards();
	m_playerGraphics3.drawCards();
	drawDealerCards(state);
}

void PokerTable::drawTable()
{
	m_window.draw(m_feltSprite);
	m_playerGraphics1.drawBetCircle();
	m_playerGraphics2.drawBetCircle();
	m_playerGraphics3.drawBetCircle();
	m_playerGraphics1.drawBet();
	m_playerGraphics2.drawBet();
	m_playerGraphics3.drawBet();
	m_playerGraphics1.drawBank();
	m_playerGraphics2.drawBank();
	m_playerGraphics3.drawBank();
	m_chipGraphics.draw();
}

void PokerTable::display()
{
	m_window.display();
}

void PokerTable::drawDealerCards(BlackJack::State state)
{
	vector<const Card*> cards;
	m_dealer.getMyCards(cards, state);
	float offset = 0.0f;
	for (auto c : cards)
	{
		if (c != nullptr)
		{
			m_resourceLoader.loadTexture(m_dealerCardTexture, c->getCardGraphic());
		}
		else
		{
			m_resourceLoader.loadTexture(m_dealerCardTexture, ResourceLoader::CARD_BACK);
		}
		m_dealerCardSprite.setTexture(m_dealerCardTexture);
		m_dealerCardSprite.setScale(.25f, .25f);
		m_dealerCardSprite.setPosition(sf::Vector2f(350 + offset, 150));
		m_window.draw(m_dealerCardSprite);
		offset += 50.0f;
	}
}

/*
void PokerTable::drawChips(sf::RenderWindow* window)
{
	window->draw(m_p1Chips.WhiteCircle);
	window->draw(m_p2Chips.WhiteCircle);
	window->draw(m_p3Chips.WhiteCircle);
}

void PokerTable::refresh(Dealer* dealer, const Player* player1, const Player* player2, const Player* player3, BlackJack::GameState state)
{
	m_dealerCards.cards = dealer->getMyCards(state);
	m_p1Cards.cards = player1->getMyCards();
	m_p2Cards.cards = player2->getMyCards();
	m_p3Cards.cards = player3->getMyCards();

	drawAll();
}

void PokerTable::drawAll()
{	
	m_window->clear();
	m_window->draw(m_feltSprite);
	drawText();
	drawPlayerCards(m_window, m_dealerCards);
	drawPlayerCards(m_window, m_p1Cards);
	drawPlayerCards(m_window, m_p2Cards);
	drawPlayerCards(m_window, m_p3Cards);

	drawChips(m_window);
	drawHitStay(m_window);
	m_window->display();
}

void PokerTable::drawHitStay(sf::RenderWindow* window)
{
	window->draw(m_hitButton.ButtonCircle);
	window->draw(m_stayButton.ButtonCircle);
}

void PokerTable::drawText()
{
	//riesling.ttf
	//Arcon-Regular.otf
	if (!m_titleFont.loadFromFile("Arcon-Regular.otf"))
	{
		throw "Font not found";
	}
	sf::Text text("Black Jack", m_titleFont, 100);
	text.setPosition(710, 25);
	m_window->draw(text);
}

void PokerTable::drawPlayerCards(sf::RenderWindow* window, PokerTable::CardSpot &spot)
{
	float offset = 0.0f;
	for (auto c : *spot.cards)
	{
		if (c != nullptr)
		{
			if (!spot.texture.loadFromFile(c->getCardGraphic()))
			{
				throw "Graphic for card not found";
			}
		}
		else
		{
			if (!spot.texture.loadFromFile("back.png"))
			{
				throw "Graphic for card not found";
			}
		}
		spot.sprite.setTexture(spot.texture);
		spot.sprite.setScale(.25f, .25f);
		spot.sprite.setPosition(sf::Vector2f(spot.x + offset, spot.y));
		window->draw(spot.sprite);
		offset += 50;
	}
	*/
//}
