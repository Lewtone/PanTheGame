#pragma once
#include <SFML\Graphics.hpp>
#include "Card.h"
class AssetsManager
{
private:
	sf::Texture cardsSheet;
public:
	AssetsManager();
	Card createCard(int x, int y);
	~AssetsManager();
};

