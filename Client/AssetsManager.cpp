#include "AssetsManager.h"



AssetsManager::AssetsManager()
{
	cardsSheet.loadFromFile("assets/cards.png");
}

Card AssetsManager::createCard(int rank, int suit)
{
	return Card(cardsSheet, sf::IntRect(X_CARD_SIZE * (rank - 9), Y_CARD_SIZE * suit, X_CARD_SIZE, Y_CARD_SIZE));
}


AssetsManager::~AssetsManager()
{
}
