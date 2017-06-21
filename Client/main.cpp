#include <SFML/Graphics.hpp>
#include "AssetsManager.h"
#include "Card.h"
#include "CardStack.h"
#include "PlayerSit.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Pan The Game");
	window.setFramerateLimit(60);
	AssetsManager assetsManager;

	PlayerSit sit;
	sit.setPosition(500, 500);
	sit.addCard(assetsManager.createCard(Rank::ACE, Suit::SPADES));
	sit.addCard(assetsManager.createCard(Rank::QUEEN, Suit::HEARTS));
	sit.addCard(assetsManager.createCard(Rank::TEN, Suit::CLUBS));
	sit.addCard(assetsManager.createCard(Rank::NINE, Suit::DIAMONDS));
	sit.addCard(assetsManager.createCard(Rank::NINE, Suit::SPADES));
	sit.setCenterPositionToX(sit.getShapeRectangle());
	CardStack cards;
	cards.setPosition(100, 100);
	cards.addCard(assetsManager.createCard(Rank::ACE, Suit::SPADES));
	cards.addCard(assetsManager.createCard(Rank::QUEEN, Suit::HEARTS));
	cards.addCard(assetsManager.createCard(Rank::TEN, Suit::CLUBS));
	cards.addCard(assetsManager.createCard(Rank::NINE, Suit::DIAMONDS));
	cards.addCard(assetsManager.createCard(Rank::NINE, Suit::SPADES));


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			cards.handleEvent(event);
			sit.handleEvent(event);
		}

		window.clear(sf::Color(0, 0x90, 0x20, 255));
		window.draw(cards);
		window.draw(sit);
		window.display();
	}

	return 0;
}