#include "PlayerSit.h"



void PlayerSit::onClicked(Card & card)
{
	card.setOppositeState();
}

void PlayerSit::onGetFocus()
{
}

void PlayerSit::onLostFocus()
{
}

PlayerSit::PlayerSit()
{
	shape.setSize(sf::Vector2f(WIDTH_SIT, HEIGHT_SIT));
	shape.setFillColor(sf::Color::Blue);
}

void PlayerSit::setPosition(float x, float y)
{
	CardContainer::setPosition(x, y - Card::Y_CARD_SIZE);
	shape.setPosition(x, y);
}

void PlayerSit::setColor(sf::Color color)
{
	shape.setFillColor(color);
}

sf::FloatRect PlayerSit::getShapeRectangle()
{
	return shape.getGlobalBounds();
}

void PlayerSit::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	CardContainer::draw(target, states);

	target.draw(shape);
}


PlayerSit::~PlayerSit()
{
}
