#pragma once
#include <SFML/Graphics.hpp>

class Card : public sf::Drawable
{
private:
	constexpr static float SCALE = 0.25f;
	sf::Sprite sprite;
public:
	Card();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	~Card();
};

