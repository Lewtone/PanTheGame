#include <SFML/Graphics.hpp>
#include "AssetsManager.h"
#include "Card.h"
#include "CardContainer.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Pan The Game");
	window.setFramerateLimit(60);
	AssetsManager assetsManager;

	CardContainer cards;
	cards.addCard(assetsManager.createCard(Rank::ACE, Suit::SPADES));
	cards.addCard(assetsManager.createCard(Rank::QUEEN, Suit::HEARTS));
	cards.addCard(assetsManager.createCard(Rank::TEN, Suit::CLUBS));
	cards.addCard(assetsManager.createCard(Rank::NINE, Suit::DIAMONDS));


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(0, 0x90, 0x20, 255));
		window.draw(cards);
		window.display();
	}

	return 0;
}