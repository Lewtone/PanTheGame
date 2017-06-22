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
	const float bx = window.getSize().x / 2.0f - PlayerSit::WIDTH_SIT / 2.0f;
	const float by = window.getSize().y - PlayerSit::HEIGHT_SIT - 20.0f;

	const float tx = window.getSize().x / 2.0f - PlayerSit::WIDTH_SIT / 2.0f;
	const float ty = Card::Y_CARD_SIZE + Card::ACTIVE_CARD_JUMP + 20.0f;

	const float lx = 240.0f;
	const float ly = window.getSize().y / 2.0f + Card::Y_CARD_SIZE / 2.0f - Card::ACTIVE_CARD_JUMP;

	const float rx = window.getSize().x - 240.0f - PlayerSit::WIDTH_SIT;
	const float ry = window.getSize().y / 2.0f + Card::Y_CARD_SIZE / 2.0f - Card::ACTIVE_CARD_JUMP;

	
	std::vector<PlayerSit> sits;
	for (size_t i = 0; i < 4; ++i)
		sits.push_back(PlayerSit());

	//bottom
	sits.at(0).setPosition(bx, by);
	//top
	sits.at(1).setPosition(tx, ty);
	//left	
	sits.at(2).setPosition(lx, ly);
	//right
	sits.at(3).setPosition(rx, ry);

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