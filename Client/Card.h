#pragma once
#include <SFML/Graphics.hpp>

enum Suit
{
	DEFAULT = -1,
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES
};

enum Rank
{
	NONE = -1,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE
};

class Card : public sf::Drawable
{
private:
	sf::Sprite sprite;
	bool active = false;
	bool hovered = false;
public:
	constexpr static float SCALE = 1.0f;	//scaling is ugly
	constexpr static float ACTIVE_CARD_JUMP = 20.0f;
	static constexpr int X_CARD_SIZE = 112;
	static constexpr int Y_CARD_SIZE = 156;

	Card(sf::Texture &texture, sf::IntRect rect);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::FloatRect getRectangle();
	void setPosition(float x, float y);
	const sf::Vector2f& getPosition();
	bool isActive();
	void setOppositeState();
	void hover();
	void unhover();
	~Card();
};

