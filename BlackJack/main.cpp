#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "PokerTable.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Black Jack");

	PokerTable pokerTable(&window);
	
	Game game(&pokerTable);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				game.handleKeyPressed(event.key);
			}
		}
	}

	return 0;
}

