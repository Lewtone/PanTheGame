#pragma once
#include <SFML/Graphics.hpp>

class Card : public sf::Drawable, public sf::Transformable
{
private:
	constexpr static float SCALE = 0.25f;
	sf::Sprite sprite;
public:
	Card(sf::Texture &texture, sf::IntRect rect);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	~Card();
};

