#pragma once
#include "CardContainer.h"
#include <iostream>

class PlayerSit :
	public CardContainer
{
private:
	sf::RectangleShape shape;
	virtual void onClicked(Card &card);
	virtual void onGetFocus();
	virtual void onLostFocus();
public:
	PlayerSit();
	void setPosition(float x, float y);
	void setColor(sf::Color color);
	sf::FloatRect getShapeRectangle();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	static constexpr float WIDTH_SIT = 100.f;
	static constexpr float HEIGHT_SIT = 50.f;
	~PlayerSit();
};

