#pragma once
#include "CardContainer.h"
class PlayerSit :
	public CardContainer, public sf::Drawable
{
private:
	sf::RectangleShape shape;
public:
	PlayerSit();
	void setPosition(float x, float y);
	void setColor(sf::Color color);
	~PlayerSit();
};

