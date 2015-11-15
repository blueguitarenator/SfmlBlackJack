#include "PokerTable.h"
#include "Dealer.h"
#include "Player.h"
#include <vector>

using namespace std;
using namespace BlackJack;

PokerTable::PokerTable(sf::RenderWindow& window, const Player& p1, const Player& p2, const Player& p3, const Dealer& dealer)
	:m_window(window), 
	m_playerGraphics1(window, p1, 0.0f), 
	m_playerGraphics2(window, p2, 400.0f), 
	m_playerGraphics3(window, p3, 800.0f),
	m_dealer(dealer),
	m_chipGraphics(window),
	m_playGraphics(window)
{
	m_resourceLoader.loadTexture(m_feltTexture, ResourceLoader::FELT);
	m_feltSprite.setTexture(m_feltTexture);
}

PokerTable::~PokerTable()
{
}

void PokerTable::drawCards(State state)
{
	m_playerGraphics1.drawCards();
	m_playerGraphics2.drawCards();
	m_playerGraphics3.drawCards();
	drawDealerCards(state);
}

void PokerTable::drawTable(State state)
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
	if (state == State::PlaceBets)
	{
		m_chipGraphics.draw();
	}
	if (state == State::Play)
	{
		m_playGraphics.draw();
	}
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
	*/

