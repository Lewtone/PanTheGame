#include <SFML/Graphics.hpp>
#include "AssetsManager.h"
#include "Card.h"
#include "CardStack.h"
#include "PlayerSit.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Pan The Game");
	window.setFramerateLimit(60);
	AssetsManager assetsManager;

	
	std::vector<PlayerSit> sits;
	for (uint16_t i = 0; i < 4; ++i)
		sits.push_back(PlayerSit());

	//bottom
	sits.at(0).setPosition(window.getSize().x / 2 - sits.at(0).getShapeRectangle().width / 2, window.getSize().y - sits.at(0).getShapeRectangle().height - 20);
	//top
	sits.at(1).setPosition(window.getSize().x / 2 - sits.at(1).getShapeRectangle().width / 2, Card::Y_CARD_SIZE + Card::ACTIVE_CARD_JUMP + 20);
	//left	
	sits.at(2).setPosition(sits.at(2).getShapeRectangle().width + 30, window.getSize().y / 2 - sits.at(2).getShapeRectangle().height / 2 + Card::Y_CARD_SIZE / 2);
	//right
	sits.at(3).setPosition(window.getSize().x - sits.at(3).getShapeRectangle().width * 2 - 30, window.getSize().y / 2 - sits.at(3).getShapeRectangle().height / 2 + Card::Y_CARD_SIZE / 2);

	for (PlayerSit &sit : sits)
	{
		sit.addCard(assetsManager.createCard(Rank::ACE, Suit::SPADES));
		sit.addCard(assetsManager.createCard(Rank::QUEEN, Suit::HEARTS));
		sit.addCard(assetsManager.createCard(Rank::TEN, Suit::CLUBS));
		sit.addCard(assetsManager.createCard(Rank::NINE, Suit::DIAMONDS));
		sit.setCenterPositionToX(sit.getShapeRectangle());
	}
	
	//stack
	CardStack cards;
	cards.addCard(assetsManager.createCard(Rank::ACE, Suit::SPADES));
	cards.addCard(assetsManager.createCard(Rank::QUEEN, Suit::HEARTS));
	cards.addCard(assetsManager.createCard(Rank::TEN, Suit::CLUBS));
	cards.addCard(assetsManager.createCard(Rank::NINE, Suit::DIAMONDS));
	cards.addCard(assetsManager.createCard(Rank::NINE, Suit::SPADES));
	cards.setPosition(window.getSize().x / 2 - cards.getRectangle().width / 2, window.getSize().y / 2 - cards.getRectangle().height / 2);


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
		window.display();
	}

	return 0;
}