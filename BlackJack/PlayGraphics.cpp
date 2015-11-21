#include "PlayGraphics.h"
#include "ResourceLoader.h"
#include "BlackJack.h"

using namespace std;
using namespace BlackJack;

PlayGraphics::PlayGraphics(sf::RenderWindow& window)
	:m_window(window)
{
	m_button.setSize(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
	m_button.setOutlineColor(sf::Color::Black);
	m_button.setFillColor(sf::Color::Transparent);
	m_button.setOutlineThickness(5);

	ResourceLoader resourceLoader;
	resourceLoader.loadFont(m_buttonFont, ResourceLoader::ARCON_FONT);
	m_buttonText.setFont(m_buttonFont);
	m_buttonText.setCharacterSize(20);
}


PlayGraphics::~PlayGraphics()
{
}

void PlayGraphics::doDraw(sf::RectangleShape& button, const string& text, float x, bool isActive)
{
	if (isActive)
	{
		m_button.setFillColor(sf::Color::Green);
	}
	else
	{
		m_button.setFillColor(sf::Color::Transparent);
	}
	m_buttonText.setString(text);
	m_buttonText.setPosition(x + 20, BUTTON_Y);
	button.setPosition(x, BUTTON_Y);
	m_window.draw(m_buttonText);
	m_window.draw(button);
	m_window.draw(m_buttonText);
}

void PlayGraphics::drawHit(bool isActive)
{
	doDraw(m_button, "HIT", HIT_BUTTON_X, isActive);
}

void PlayGraphics::drawStay(bool isActive)
{
	doDraw(m_button, "STAY", STAY_BUTTON_X, isActive);
}

void PlayGraphics::drawDouble(bool isActive)
{
	doDraw(m_button, "DOUBLE", DOUBLE_BUTTON_X, isActive);
}

void PlayGraphics::drawSplit(bool isActive)
{
	doDraw(m_button, "SPLIT", SPLIT_BUTTON_X, isActive);
}

