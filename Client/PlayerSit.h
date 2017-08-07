#pragma once
#include "CardContainer.h"
#include "INetworkSitController.h"
#include <iostream>

class PlayerSit :
	public CardContainer
{
private:
	int id = -1;
	bool taken = false;
	sf::RectangleShape shape;
	INetworkSitController* controller;
	virtual void onClicked(Card &card) override;
	virtual void onGetFocus() override;
	virtual void onLostFocus() override;

	void onShapeClicked();
public:
	PlayerSit(int id, INetworkSitController* controller);
	void setPosition(float x, float y);
	void setColor(sf::Color color);
	void setSitting(bool state);
	sf::FloatRect getShapeRectangle();
	void handleEvent(const sf::Event& event);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	static constexpr float WIDTH_SIT = 100.f;
	static constexpr float HEIGHT_SIT = 50.f;
	~PlayerSit();
};

