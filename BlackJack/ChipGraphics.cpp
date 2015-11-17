#include "ChipGraphics.h"
#include "ResourceLoader.h"
#include "BlackJack.h"

using namespace BlackJack;

void loadChip(sf::CircleShape& chip, sf::Texture& texture, float x, float y);

ChipGraphics::ChipGraphics(sf::RenderWindow& window)
	:m_window(window)
{
	ResourceLoader resourceLoader;
	resourceLoader.loadTexture(m_chipTexture, ResourceLoader::CHIPS);

	loadChip(m_oneChipCircle, m_chipTexture, ONE_CHIP_X, ONE_CHIP_Y);
	m_oneChipCircle.setTextureRect(sf::IntRect(4, 3, 82, 82));
	loadChip(m_fiveChipCircle, m_chipTexture, FIVE_CHIP_X, FIVE_CHIP_Y);
	m_fiveChipCircle.setTextureRect(sf::IntRect(97, 3, 82, 82));
	loadChip(m_tenChipCircle, m_chipTexture, TEN_CHIP_X, TEN_CHIP_Y);
	m_tenChipCircle.setTextureRect(sf::IntRect(190, 6, 82, 82));
	loadChip(m_twentyFiveChipCircle, m_chipTexture, TWENTYFIVE_CHIP_X, TWENTYFIVE_CHIP_Y);
	m_twentyFiveChipCircle.setTextureRect(sf::IntRect(47, 86, 82, 82));

	m_doneChipCircle.setRadius(50);
	m_doneChipCircle.setOutlineThickness(5);
	m_doneChipCircle.setOutlineColor(sf::Color(0, 0, 250));
	m_doneChipCircle.setFillColor(sf::Color::Transparent);
	m_doneChipCircle.setPosition(sf::Vector2f(DONE_CHIP_X, DONE_CHIP_Y));

	resourceLoader.loadFont(m_doneFont, ResourceLoader::ARCON_FONT);
	m_doneText.setFont(m_doneFont);
	m_doneText.setString("DONE");
	m_doneText.setCharacterSize(20);
	m_doneText.setPosition(sf::Vector2f(DONE_CHIP_X + 20, DONE_CHIP_Y + 20));
	
}

ChipGraphics::~ChipGraphics()
{
}

void loadChip(sf::CircleShape& chip, sf::Texture& texture, float x, float y)
{
	chip.setRadius((float)CHIP_RADIUS);
	chip.setTexture(&texture);
	chip.setTextureRect(sf::IntRect(3, 3, 83, 83));
	chip.setPosition(sf::Vector2f(x, y));
	chip.setScale(.5f, .5f);
}

void ChipGraphics::draw()
{
	m_window.draw(m_oneChipCircle);
	m_window.draw(m_fiveChipCircle);
	m_window.draw(m_tenChipCircle);
	m_window.draw(m_twentyFiveChipCircle);
}

void ChipGraphics::drawDone()
{
	m_window.draw(m_doneChipCircle);
	m_window.draw(m_doneText);
}
