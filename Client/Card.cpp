#include "Card.h"



Card::Card(sf::Texture &texture, sf::IntRect rect)
{
	sprite.setTexture(texture);
	sprite.setTextureRect(rect);
	sprite.setScale(SCALE, SCALE);
}

void Card::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(sprite, states);
}

sf::FloatRect Card::getRectangle()
{
	return sprite.getGlobalBounds();
}


Card::~Card()
{
}
