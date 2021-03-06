#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Pan The Game");
	window.setFramerateLimit(60);
	Game game;
	game.setup(window);
	game.connect();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			game.handleEvent(event);
		}

		game.doNetworkStuff();
		window.clear(sf::Color(0, 0x90, 0x20, 255));
		window.draw(game);
		window.display();
	}

	return 0;
}