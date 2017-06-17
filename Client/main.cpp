#include <SFML/Graphics.hpp>
#include "AssetsManager.h"
#include "Card.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Pan The Game");
	AssetsManager assetsManager;
	Card card = assetsManager.createCard(0, 0);
	card.setPosition(10.0f, 10.0f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Green);
		window.draw(card);
		window.display();
	}

	return 0;
}