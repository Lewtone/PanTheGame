#include "Card.h"



Card::Card(sf::Texture &texture, sf::IntRect rect)
{
	sprite.setTexture(texture);
	sprite.setTextureRect(rect);
	sprite.setScale(SCALE, SCALE);
}

void Card::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite);
}

sf::FloatRect Card::getRectangle()
{
	return sprite.getGlobalBounds();
}

void Card::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

const sf::Vector2f & Card::getPosition()
{
	return sprite.getPosition();
}

bool Card::isActive()
{
	return active;
}

void Card::setOppositeState()
{
	if (active)
	{
		active = false;
		sprite.move(0, ACTIVE_CARD_JUMP);
	}
	else
	{
		active = true;
		sprite.move(0, -ACTIVE_CARD_JUMP);
	}
}


Card::~Card()
{
}
