#pragma once
#include <SFML/Graphics.hpp>

enum Suit
{
	CLUBS = 0,
	DIAMONDS = 1,
	HEARTS = 2,
	SPADES = 3
};

enum Rank
{
	NINE = 9,
	TEN = 10,
	JACK = 11,
	QUEEN = 12,
	KING = 13,
	ACE = 14
};

class Card : public sf::Drawable
{
private:
	constexpr static float SCALE = 1.0f;	//scaling is ugly
	sf::Sprite sprite;
public:
	Card(sf::Texture &texture, sf::IntRect rect);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::FloatRect getRectangle();
	void setPosition(float x, float y);
	const sf::Vector2f& getPosition();
	~Card();
};

