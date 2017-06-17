#pragma once
#include <SFML\Graphics.hpp>
#include "Card.h"
class AssetsManager
{
private:
	static constexpr int X_CARD_SIZE = 560;
	static constexpr int Y_CARD_SIZE = 780;
	sf::Texture cardsSheet;
public:
	AssetsManager();
	Card createCard(int x, int y);
	~AssetsManager();
};

