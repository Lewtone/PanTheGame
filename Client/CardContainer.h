#pragma once
#include "Card.h"
#include <SFML\Graphics.hpp>

class CardContainer : public sf::Drawable
{
private:
	static constexpr float SPACE = 21.0f;
	sf::Vector2f position;

	bool isFocused = false;
	virtual void onClicked(Card &card) = 0;
	virtual void onGetFocus() = 0;
	virtual void onLostFocus() = 0;
protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	std::vector<Card> cards;
public:
	CardContainer();
	void addCard(Card card);
	void handleEvent(const sf::Event& event);
	sf::FloatRect getRectangle();
	void setPosition(float x, float y);
	const sf::Vector2f& getPosition();
	void setCenterPositionToX(sf::FloatRect rect);
	~CardContainer();
};

