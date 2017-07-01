#include <SFML/Graphics.hpp>
#include "Card.h"
#include "CardStack.h"
#include "PlayerSit.h"
#include "ArrowWidget.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Pan The Game");
	window.setFramerateLimit(60);

	for (PlayerSit &sit : sits)
	{
		sit.addCard(assetsManager.createCard(Rank::ACE, Suit::SPADES));
		sit.addCard(assetsManager.createCard(Rank::ACE, Suit::SPADES));
		sit.addCard(assetsManager.createCard(Rank::ACE, Suit::SPADES));
		sit.addCard(assetsManager.createCard(Rank::ACE, Suit::SPADES));
		sit.addCard(assetsManager.createCard(Rank::ACE, Suit::SPADES));
		sit.setCenterPositionToX(sit.getShapeRectangle());
	}
	
	//stack
	CardStack cards;
	cards.addCard(assetsManager.createCard(Rank::NINE, Suit::HEARTS));
	cards.addCard(assetsManager.createCard(Rank::NINE, Suit::SPADES));
	cards.addCard(assetsManager.createCard(Rank::NINE, Suit::DIAMONDS));
	cards.addCard(assetsManager.createCard(Rank::NINE, Suit::CLUBS));
	cards.setPosition(window.getSize().x / 2.0f - Card::X_CARD_SIZE / 2.0f, window.getSize().y / 2.0f - cards.getRectangle().height / 2.0f);


	//arrows
	ArrowWidget arrowWidget(assetsManager.getArrowTexture());
	arrowWidget.setOnSit(sits.at(1));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			cards.handleEvent(event);
			for (PlayerSit &sit : sits)
				sit.handleEvent(event);
		}

		window.clear(sf::Color(0, 0x90, 0x20, 255));
		window.draw(cards);
		for (PlayerSit &sit : sits)
			window.draw(sit);
		window.draw(arrowWidget);
		window.display();
	}

	return 0;
}