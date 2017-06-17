#include "Card.h"



Card::Card()
{
}

void Card::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}


Card::~Card()
{
}
