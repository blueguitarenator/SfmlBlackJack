#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "PokerTable.h"
#include "GameEngine.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1400, 1000), "Black Jack");
	window.setFramerateLimit(60);
	//PokerTable pokerTable(window);
	
	Game game(window);
	GameEngine engine(game);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					engine.mouseClick(event.mouseButton.x, event.mouseButton.y);
					//std::cout << "the right button was pressed" << std::endl;
					//std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					//std::cout << "mouse y: " << event.mouseButton.y << std::endl;
				}
			}
			else
			{
				engine.handlePollEvent();
			}
		}
	}

	return 0;
}

