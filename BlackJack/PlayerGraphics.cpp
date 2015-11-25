#include "PlayerGraphics.h"
#include "Player.h"
#include "Card.h"
#include "BlackJack.h"
#include "PlayState.h"

using namespace std;

PlayerGraphics::PlayerGraphics(sf::RenderWindow& window, const Player& player, float myOffset)
	:m_window(window), m_player(player), m_myOffset(myOffset)
{
	m_betCircle.setRadius(50);
	m_betCircle.setOutlineThickness(5);
	m_betCircle.setOutlineColor(sf::Color::Blue);
	m_betCircle.setFillColor(sf::Color::Transparent);
	m_betCircle.setPosition(sf::Vector2f(250 + myOffset, 400));

	m_bankText.setPosition(sf::Vector2f(275 + myOffset, 825));
	m_resourceLoader.loadFont(m_bankFont, ResourceLoader::ARCON_FONT);	
	m_bankText.setFont(m_bankFont);
	m_bankText.setCharacterSize(20);

	m_betText.setPosition(sf::Vector2f(275 + myOffset, 425));
	m_betText.setFont(m_bankFont);
	m_betText.setCharacterSize(20);

	m_winText.setColor(sf::Color::Green);
	m_winText.setPosition(sf::Vector2f(275 + myOffset, 440));
	m_winText.setFont(m_bankFont);
	m_winText.setCharacterSize(20);
}


PlayerGraphics::~PlayerGraphics()
{
}

void PlayerGraphics::drawCards()
{
	if (m_player.isSplit())
	{
		doDrawCards(100, m_myOffset, &m_player);
		doDrawCards(300, m_myOffset, m_player.getSplitPlayer());
	}
	else
	{
		doDrawCards(150, m_myOffset, &m_player);
	}
}

void PlayerGraphics::doDrawCards(int leftOffset, int myPositionOffset, const Player* p)
{
	float offset = 0.0f;
	const vector<const Card*>* cards = p->getMyCards();
	for (auto c : *cards)
	{
		if (c != nullptr)
		{
			m_resourceLoader.loadTexture(m_cardTexture, c->getCardGraphic());
		}
		m_cardSprite.setTexture(m_cardTexture);
		m_cardSprite.setScale(.25f, .25f);
		m_cardSprite.setPosition(sf::Vector2f(leftOffset + offset + myPositionOffset, 550));
		m_window.draw(m_cardSprite);
		offset += 50.0f;
	}
}

void PlayerGraphics::drawBetCircle()
{
	if (m_player.isActive())
	{
		m_betCircle.setOutlineColor(sf::Color::Yellow);
	}
	else
	{
		m_betCircle.setOutlineColor(sf::Color::Blue);
	}
	m_window.draw(m_betCircle);
}

void PlayerGraphics::drawBank()
{
	m_bankText.setString("$" + to_string(m_player.getBank()));
	m_window.draw(m_bankText);
}

void PlayerGraphics::drawBet()
{
	m_betText.setString("$" + to_string(m_player.getBet()));

	if (m_player.getBet() == -1)
	{
		m_betText.setString("BUST");
	}
	if (m_player.getWinnings() > 0)
	{
		drawWin();
	}
	m_window.draw(m_betText);
}

void PlayerGraphics::drawWin()
{
	m_winText.setString("$" + to_string(m_player.getWinnings()));
	m_window.draw(m_winText);
}