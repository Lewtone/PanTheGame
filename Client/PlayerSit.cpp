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

void PlayerSit::onShapeClicked()
{
	if (!taken)
		controller->onSitTake(id);
}

PlayerSit::PlayerSit(int id, INetworkSitController* controller)
{
	shape.setSize(sf::Vector2f(WIDTH_SIT, HEIGHT_SIT));
	shape.setFillColor(sf::Color::Blue);
	this->id = id;
	this->controller = controller;
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

void PlayerSit::setSitting(bool state)
{
	taken = state;
	if (state)
		shape.setFillColor(sf::Color::Red);
	else
		shape.setFillColor(sf::Color::Blue);
}

sf::FloatRect PlayerSit::getShapeRectangle()
{
	return shape.getGlobalBounds();
}

void PlayerSit::handleEvent(const sf::Event & event)
{
	switch (event.type)
	{
		case sf::Event::MouseButtonReleased:
		{
			sf::Vector2f mouseVector(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

			if (shape.getGlobalBounds().contains(mouseVector))
				onShapeClicked();
		}
	}

	CardContainer::handleEvent(event);

}

void PlayerSit::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	CardContainer::draw(target, states);

	target.draw(shape);
}


PlayerSit::~PlayerSit()
{
}
