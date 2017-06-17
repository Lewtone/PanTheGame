#include "AssetsManager.h"



AssetsManager::AssetsManager()
{
	cardsSheet.loadFromFile("assets/cards.png");
}

Card AssetsManager::createCard(int x, int y)
{
	return Card(cardsSheet, sf::IntRect(X_CARD_SIZE * x, Y_CARD_SIZE * y, X_CARD_SIZE, Y_CARD_SIZE));
}


AssetsManager::~AssetsManager()
{
}
