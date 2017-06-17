#include "CardContainer.h"



CardContainer::CardContainer()
{
}

void CardContainer::addCard(Card card)
{
	card.setPosition(card.getPosition().x + 21.0f * cards.size(), this->getPosition().y);
	cards.push_back(card);
}

void CardContainer::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto& card : cards)
		target.draw(card);
}


CardContainer::~CardContainer()
{
}
