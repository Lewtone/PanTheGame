#pragma once
#include "Card.h"
#include <SFML\Graphics.hpp>

class CardContainer : public sf::Drawable
{
private:
	static constexpr float SPACE = 21.0f;
	sf::Vector2f position;
	std::vector<Card> cards;

	bool isFocused = false;
	virtual void onClicked(Card &card) = 0;
	virtual void onGetFocus() = 0;
	virtual void onLostFocus() = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	CardContainer();
	void addCard(Card card);
	void handleEvent(sf::Event& event);
	sf::FloatRect getRectangle();
	void setPosition(float x, float y);
	const sf::Vector2f& getPosition();
	~CardContainer();
};

