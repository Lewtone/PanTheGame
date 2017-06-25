#include "ArrowWidget.h"



ArrowWidget::ArrowWidget(sf::Texture & texture)
{
	leftArrow.setTexture(texture);
	rightArrow.setTexture(texture);
	
	rightArrow.setScale(-1.0f, 1.0f);
}

void ArrowWidget::setOnSit(PlayerSit & sit)
{
	sf::FloatRect rectangle = sit.getShapeRectangle();

	float left = rectangle.left;
	float right = rectangle.left + rectangle.width;
	float top = rectangle.top;

	leftArrow.setPosition(left - WIDTH - SPACE, top);
	rightArrow.setPosition(right + SPACE + WIDTH, top);
}

void ArrowWidget::setColor(sf::Color color)
{
	leftArrow.setColor(color);
	rightArrow.setColor(color);
}

void ArrowWidget::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(leftArrow);
	target.draw(rightArrow);
}

ArrowWidget::~ArrowWidget()
{
}
