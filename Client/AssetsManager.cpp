#include "AssetsManager.h"



AssetsManager::AssetsManager()
{
	cardsSheet.loadFromFile("assets/cards.png");
	arrowTexture.loadFromFile("assets/arrow.png");
	backTexture.loadFromFile("assets/back.png");
}

Card AssetsManager::createCard(int rank, int suit)
{
	if (rank == -1 || suit == -1)
		return Card(backTexture, sf::IntRect(0, 0, Card::X_CARD_SIZE, Card::Y_CARD_SIZE));
	return Card(cardsSheet, sf::IntRect(Card::X_CARD_SIZE * rank, Card::Y_CARD_SIZE * suit, Card::X_CARD_SIZE, Card::Y_CARD_SIZE));
}

sf::Texture & AssetsManager::getArrowTexture()
{
	return arrowTexture;
}


AssetsManager::~AssetsManager()
{
}
