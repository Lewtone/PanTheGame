#include "Game.h"




Game::Game()
{
}

void Game::setupSits(sf::RenderWindow& window)
{
	const float bx = window.getSize().x / 2.0f - PlayerSit::WIDTH_SIT / 2.0f;
	const float by = window.getSize().y - PlayerSit::HEIGHT_SIT - 20.0f;

	const float tx = window.getSize().x / 2.0f - PlayerSit::WIDTH_SIT / 2.0f;
	const float ty = Card::Y_CARD_SIZE + Card::ACTIVE_CARD_JUMP + 20.0f;

	const float lx = 240.0f;
	const float ly = window.getSize().y / 2.0f + Card::Y_CARD_SIZE / 2.0f - Card::ACTIVE_CARD_JUMP;

	const float rx = window.getSize().x - 240.0f - PlayerSit::WIDTH_SIT;
	const float ry = window.getSize().y / 2.0f + Card::Y_CARD_SIZE / 2.0f - Card::ACTIVE_CARD_JUMP;

	//bottom
	sits.at(0).setPosition(bx, by);
	//top
	sits.at(1).setPosition(tx, ty);
	//left	
	sits.at(2).setPosition(lx, ly);
	//right
	sits.at(3).setPosition(rx, ry);
}

void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto& sit : sits)
		target.draw(sit);
}

void Game::setup(sf::RenderWindow & window)
{
	setupSits(window);
}


Game::~Game()
{
}
