#include "PlayerSit.h"



PlayerSit::PlayerSit()
{
	shape.setSize(sf::Vector2f(100, 50));
	shape.setFillColor(sf::Color::Blue);
}

void PlayerSit::setPosition(float x, float y)
{
	CardContainer::setPosition(x, y);
	shape.setPosition(x, y);
}

void PlayerSit::setColor(sf::Color color)
{
	shape.setFillColor(color);
}


PlayerSit::~PlayerSit()
{
}
