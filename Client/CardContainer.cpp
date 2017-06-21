#include "CardContainer.h"



CardContainer::CardContainer()
{
}

void CardContainer::addCard(Card card)
{
	card.setPosition(position.x + SPACE * cards.size(), position.y);
	cards.push_back(card);
}

void CardContainer::handleEvent(sf::Event & event)
{
	switch (event.type)
	{
		case sf::Event::MouseButtonReleased:
		{
			sf::Vector2f mouseVector(event.mouseButton.x, event.mouseButton.y);

			for (int i = cards.size(); i != 0; --i)
			{
				Card &currentCard = cards.at(i - 1);
				if (currentCard.getRectangle().contains(mouseVector))
				{
					this->onClicked(currentCard);
					return;
				}
			}
		}

		case sf::Event::MouseMoved:
		{
			sf::Vector2f mouseVector(event.mouseMove.x, event.mouseMove.y);
			if (!isFocused && this->getRectangle().contains(mouseVector))
			{
				isFocused = true;
				this->onGetFocus();
			}
			else if (isFocused && !this->getRectangle().contains(mouseVector))
			{
				isFocused = false;
				this->onLostFocus();
			}
		}
	}

}

sf::FloatRect CardContainer::getRectangle()
{
	sf::Vector2f position = this->getPosition();
	sf::Vector2f size(0, 0);

	if (!cards.empty())
	{
		sf::FloatRect firstCardRect = cards.front().getRectangle();
		sf::FloatRect lastCardRect = cards.back().getRectangle();

		size.x = lastCardRect.left + lastCardRect.width - firstCardRect.left;
		size.y = firstCardRect.height;
	}

	return sf::FloatRect(position, size);
}

void CardContainer::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
	for (int i = 0; i != cards.size(); ++i)
		cards[i].setPosition(position.x + SPACE * i, position.y);
}

const sf::Vector2f & CardContainer::getPosition()
{
	return position;
}

void CardContainer::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto& card : cards)
		target.draw(card);
}


CardContainer::~CardContainer()
{
}
