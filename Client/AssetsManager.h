#pragma once
#include <SFML\Graphics.hpp>
#include "Card.h"
class AssetsManager
{
private:
	sf::Texture cardsSheet;
	sf::Texture arrowTexture;
	sf::Texture backTexture;
public:
	AssetsManager();
	Card createCard(int x, int y);
	sf::Texture& getArrowTexture();
	~AssetsManager();

};

