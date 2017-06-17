#include <SFML/Graphics.hpp>
#include "AssetsManager.h"
#include "Card.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Pan The Game");
	window.setFramerateLimit(60);
	AssetsManager assetsManager;

	std::vector<Card> cards;
	cards.push_back(assetsManager.createCard(Rank::ACE, Suit::SPADES));
	cards.push_back(assetsManager.createCard(Rank::QUEEN, Suit::HEARTS));
	cards.push_back(assetsManager.createCard(Rank::TEN, Suit::CLUBS));
	cards.push_back(assetsManager.createCard(Rank::NINE, Suit::DIAMONDS));

	for (size_t i = 0; i < cards.size(); ++i)
	{
		cards.at(i).setPosition(10.0f + i * 150.0f, 10.0f);
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(0, 0x90, 0x20, 255));
		for (auto &card : cards)
			window.draw(card);
		window.display();
	}

	return 0;
}