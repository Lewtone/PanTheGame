#include "AssetsManager.h"



AssetsManager::AssetsManager()
{
	cardsSheet.loadFromFile("assets/cards.png");
	arrowTexture.loadFromFile("assets/arrow.png");
}

Card AssetsManager::createCard(int rank, int suit)
{
	return Card(cardsSheet, sf::IntRect(Card::X_CARD_SIZE * (rank - 9), Card::Y_CARD_SIZE * suit, Card::X_CARD_SIZE, Card::Y_CARD_SIZE));
}

sf::Texture & AssetsManager::getArrowTexture()
{
	return arrowTexture;
}


AssetsManager::~AssetsManager()
{
}
