#include "Game.h"




Game::Game() :
	assetsManager(),
	arrow(assetsManager.getArrowTexture()),
	stack(this)
{
	for (int i = 0; i != PLAYER_SITS_AMOUT; ++i)
		sits.push_back(PlayerSit(this));
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

	arrow.setOnSit(sits.at(1));
	sits.at(1).addCard(assetsManager.createCard(Rank::ACE, Suit::SPADES));
}

void Game::setupStack(sf::RenderWindow & window)
{
	stack.setPosition(window.getSize().x / 2.0f - Card::X_CARD_SIZE / 2.0f, window.getSize().y / 2.0f - stack.getRectangle().height / 2.0f);
	stack.addCard(assetsManager.createCard(Rank::ACE, Suit::SPADES));
}

void Game::onStackCardGet()
{
}

void Game::onCardsPut()
{
}

void Game::onSitTake()
{
}

void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto& sit : sits)
		target.draw(sit);

	target.draw(stack);
	target.draw(arrow);
}

void Game::setup(sf::RenderWindow & window)
{
	setupSits(window);
	setupStack(window);
}

void Game::handleEvent(const sf::Event & event)
{
	for (auto& sit : sits)
		sit.handleEvent(event);

	stack.handleEvent(event);
}

void Game::doNetworkStuff()
{
	sf::Packet packet;
	if (socket.receive(packet) == sf::Socket::Done)
	{
		std::string msg;
		packet >> msg;
		std::cout << msg << std::endl;
	}
}

void Game::connect()
{
	sf::Socket::Status status = socket.connect(sf::IpAddress::LocalHost, 1337, sf::seconds(10.0f));
	if (status != sf::Socket::Done)
	{
		std::cout << "Couldn't reach host\n";
	}
	else
	{
		socket.setBlocking(false);
	}
}


Game::~Game()
{
}
