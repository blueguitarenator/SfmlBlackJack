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
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					std::cout << "the right button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
				}
			}
		}
	}

	return 0;
}

