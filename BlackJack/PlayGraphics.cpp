#include "PlayGraphics.h"
#include "ResourceLoader.h"
#include "BlackJack.h"

using namespace std;
using namespace BlackJack;

PlayGraphics::PlayGraphics(sf::RenderWindow& window)
	:m_window(window)
{
	m_hitButton.setSize(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
	m_hitButton.setOutlineColor(sf::Color::Black);
	m_hitButton.setFillColor(sf::Color::Transparent);
	m_hitButton.setOutlineThickness(5);

	ResourceLoader resourceLoader;
	resourceLoader.loadFont(m_buttonFont, ResourceLoader::ARCON_FONT);
	m_buttonText.setFont(m_buttonFont);
	m_buttonText.setCharacterSize(20);
}


PlayGraphics::~PlayGraphics()
{
}

void PlayGraphics::draw()
{
	doDraw(m_hitButton, "HIT", HIT_BUTTON_X);
	doDraw(m_hitButton, "STAY", STAY_BUTTON_X);
	doDraw(m_hitButton, "DOUBLE", DOUBLE_BUTTON_X);
	doDraw(m_hitButton, "SPLIT", SPLIT_BUTTON_X);
}

void PlayGraphics::doDraw(sf::RectangleShape& button, const string& text, float x)
{
	m_buttonText.setString(text);
	m_buttonText.setPosition(x + 20, BUTTON_Y);
	button.setPosition(x, BUTTON_Y);
	m_window.draw(m_buttonText);
	m_window.draw(button);
}