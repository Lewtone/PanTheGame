#pragma once
#include "Card.h"
#include <SFML\Graphics.hpp>

class CardContainer : public sf::Drawable, public sf::Transformable
{
private:
	static constexpr float SPACE = 21.0f;
	std::vector<Card> cards;
public:
	CardContainer();
	void addCard(Card card);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	~CardContainer();
};

