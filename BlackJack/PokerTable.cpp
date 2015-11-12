#include "PokerTable.h"
#include "Card.h"
#include "Dealer.h"
#include "Player.h"

PokerTable::PokerTable(sf::RenderWindow* window)
	:m_window(window)
{
	m_dealerCards.x = 350;
	m_dealerCards.y = 100;
	m_dealerCards.cards = nullptr;

	m_p1Cards.x = 10;
	m_p1Cards.y = 500;
	m_p1Cards.cards = nullptr;

	m_p2Cards.x = 350;
	m_p2Cards.y = 500;
	m_p2Cards.cards = nullptr;

	m_p3Cards.x = 690;
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
}

PokerTable::~PokerTable()
{
}

void PokerTable::refresh(const Dealer* dealer, const Player* player1, const Player* player2, const Player* player3)
{
	m_dealerCards.cards = dealer->getMyCards();
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
	m_window->display();
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
	text.setPosition(10, 25);
	m_window->draw(text);
}

void PokerTable::drawPlayerCards(sf::RenderWindow* window, PokerTable::Spot &spot)
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
}

void PokerTable::drawChips(sf::RenderWindow* window)
{
	sf::CircleShape circle(100);
	circle.setTexture(&m_chipTexture);
	circle.setTextureRect(sf::IntRect(3, 3, 83, 83));
	circle.setScale(.5f, .5f);
	circle.setPosition(sf::Vector2f(3, 675));
	window->draw(circle);
}