#pragma once
#include <SFML\Graphics.hpp>
#include "PlayerSit.h"

class ArrowWidget : public sf::Drawable
{
private:
	sf::Sprite leftArrow;
	sf::Sprite rightArrow;
	static constexpr float HEIGHT = 50.0f;
	static constexpr float WIDTH = 50.0f;
	static constexpr float SPACE = 25.0f;
public:
	ArrowWidget(sf::Texture& texture);
	void setOnSit(PlayerSit& sit);
	void setColor(sf::Color color);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	~ArrowWidget();
};

