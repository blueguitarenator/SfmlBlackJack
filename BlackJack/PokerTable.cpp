#include "PokerTable.h"
#include "Dealer.h"
#include "Player.h"
#include "GameState.h"
#include "BlackJack.h"
#include "PlayState.h"
#include <vector>

using namespace BlackJack;
using namespace std;

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
	m_resourceLoader.loadFont(m_titleFont, ResourceLoader::ARCON_FONT);
}

PokerTable::~PokerTable()
{
}

void PokerTable::drawCards(GameState* state)
{
	m_playerGraphics1.drawCards();
	m_playerGraphics2.drawCards();
	m_playerGraphics3.drawCards();
	drawDealerCards(state);
}

void PokerTable::drawChips()
{
	m_chipGraphics.draw();
}

void PokerTable::drawChipsDone()
{
	m_chipGraphics.drawDone();
}

//void PokerTable::drawPlay()
//{
//	m_playGraphics.draw();
//}

void PokerTable::drawPayout()
{
	m_playerGraphics1.drawWin();
	m_playerGraphics2.drawWin();
	m_playerGraphics3.drawWin();
	drawContinueButton();
}

void PokerTable::drawTable(GameState* state, const PlayState* playState)
{
	m_window.draw(m_feltSprite);
	m_playerGraphics1.drawBetCircle(playState->getPlayer());
	m_playerGraphics2.drawBetCircle(playState->getPlayer());
	m_playerGraphics3.drawBetCircle(playState->getPlayer());
	m_playerGraphics1.drawBet();
	m_playerGraphics2.drawBet();
	m_playerGraphics3.drawBet();
	m_playerGraphics1.drawBank();
	m_playerGraphics2.drawBank();
	m_playerGraphics3.drawBank();
	state->draw();

}

void PokerTable::drawContinueButton()
{
	m_continueButton.setPosition(sf::Vector2f(HIT_BUTTON_X, BUTTON_Y));
	m_continueButton.setSize(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
	m_continueButton.setOutlineColor(sf::Color::Black);
	m_continueButton.setFillColor(sf::Color::Transparent);
	m_continueButton.setOutlineThickness(5);

	m_continueText.setFont(m_titleFont);
	m_continueText.setCharacterSize(20);
	m_continueText.setPosition(sf::Vector2f(HIT_BUTTON_X + 10, BUTTON_Y));
	m_continueText.setString("Continue?");
	m_window.draw(m_continueButton);
	m_window.draw(m_continueText);

}
void PokerTable::display()
{
	m_window.display();
}

void PokerTable::drawDealerCards(GameState* state)
{
	vector<const Card*> cards;
	//Dealer* dealer = const_cast<Dealer*>(&m_dealer);
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

