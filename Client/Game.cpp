#include "Game.h"




Game::Game() :
	assetsManager(),
	arrow(assetsManager.getArrowTexture()),
	stack(this)
{
	for (int i = 0; i != PLAYER_SITS_AMOUT; ++i)
		sits.push_back(PlayerSit(i, this));
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

void Game::onSitTake(int id)
{
	sf::Packet packet;
	packet << static_cast<sf::Uint8>(ClientPackets::TAKE_SIT) << id;

	sendPacket(packet);
}

void Game::handlePacket(sf::Packet & packet)
{
	sf::Uint8 header;
	if (!(packet >> header))
		return;

	switch (header)
	{
	case ServerPackets::PONG:
		onPong(packet);
		break;
	case ServerPackets::MSG:
		onMsg(packet);
		break;
	case ServerPackets::PLAYER_AMOUNT:
		onPlayerAmount(packet);
		break;
	case ServerPackets::MY_CARDS:
		onMyCards(packet);
		break;
	case ServerPackets::OTHER_CARDS:
		onOtherCards(packet);
		break;
	case ServerPackets::STACK_CARDS:
		onStackCards(packet);
		break;
	case ServerPackets::CURRENT_TURE:
		onCurrentTure(packet);
		break;
	case ServerPackets::SIT_INFO:
		onSitInfo(packet);
		break;

	default:
		break;
	}
}

void Game::sendPacket(sf::Packet & packet)
{
	while (socket.send(packet) == sf::Socket::Partial);
}

void Game::onPong(sf::Packet & packet)
{
	std::cout << "Get PONG from server\n";
}

void Game::onMsg(sf::Packet & packet)
{
	std::string message;
	if (!(packet >> message))
		return;

	std::cout << "[SERVER MESSAGE]: " << message << std::endl;
}

void Game::onPlayerAmount(sf::Packet & packet)
{
	int playersAmount;

	if (!(packet >> playersAmount))
		return;

	std::cout << "[PLAYERS AMOUNT]: " << playersAmount << std::endl;
}

void Game::onMyCards(sf::Packet & packet)
{
	if (mySitId == -1)
	{
		std::cout << "[CLIENT ERROR]: SERVER SENT ME A SET OF CARDS, BUT IM NOT SITTING ATM" << std::endl;
		return;
	}

	int sizeOfCards = 0;

	if (!(packet >> sizeOfCards))
		return;

	PlayerSit& mySit = sits.at(mySitId);
	mySit.clearCards();

	for (int i = 0; i != sizeOfCards; ++i)
	{
		sf::Uint8 rank;
		sf::Uint8 suit;

		if (!(packet >> rank >> suit))
			return;

		mySit.addCard(assetsManager.createCard(rank, suit));
	}

	std::cout << "[CLIENT MESSAGE]: Added " << sizeOfCards << " to your hand." << std::endl;
}

void Game::onOtherCards(sf::Packet & packet)
{
	int sizeOfSits = 0;

	if (!(packet >> sizeOfSits))
		return;

	if (sizeOfSits < 0 || sizeOfSits > sits.size())
		return;

	for (int i = 0; i != sits.size(); ++i)
	{
		if (i == mySitId)
			continue;

		PlayerSit& sit = sits.at(i);
		
		int dummyCardsSize = 0;
		sit.clearCards();

		if (!(packet >> dummyCardsSize))
			return;

		for (int j = 0; j != dummyCardsSize; ++j)
			sit.addCard(assetsManager.createCard(0, 0)); //dummy card later
	}
}

void Game::onStackCards(sf::Packet & packet)
{
	int sizeOfStackCards = 0;

	if (!(packet >> sizeOfStackCards))
		return;

	stack.clearCards();

	for (int i = 0; i != sizeOfStackCards; ++i)
	{
		sf::Uint8 rank;
		sf::Uint8 suit;

		if (!(packet >> rank >> suit))
			return;

		stack.addCard(assetsManager.createCard(rank, suit));
	}

	std::cout << "[CLIENT MESSAGE]: Added " << sizeOfStackCards << " to your stack." << std::endl;
}

void Game::onSitInfo(sf::Packet & packet)
{
	int sizeOfSits = 0;

	if (!(packet >> sizeOfSits))
		return;

	if (sizeOfSits < 0 || sizeOfSits > sits.size())
		return;

	for (int i = 0; i != sizeOfSits; ++i)
	{
		PlayerSit& sit = sits[i];
		
		bool state = false;

		if (!(packet >> state))
			return;

		if (state)
		{
			std::string nickname;
			if (!(packet >> nickname))
				return;
		}

		sit.setSitting(state);
	}
}

void Game::onCurrentTure(sf::Packet & packet)
{
	int packetTureSitId;

	if (!(packet >> packetTureSitId))
		return;

	this->currentTureSitId = packetTureSitId;

	if (currentTureSitId < 0 || packetTureSitId >= sits.size())
	{
		std::cout << "[CLIENT ERROR]: Couldn't set arrow because it's now ture of player with sit id equal to " << packetTureSitId << std::endl;
		return;
	}

	arrow.setOnSit(sits[packetTureSitId]);
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
		handlePacket(packet);
}

void Game::connect()
{
	sf::Socket::Status status = socket.connect(sf::IpAddress::LocalHost, 1337, sf::seconds(3.0f));
	if (status != sf::Socket::Done)
	{
		std::cout << "Couldn't reach host\n";
	}
	else
	{
		socket.setBlocking(false);
		sf::Packet initialMessage;
		initialMessage << static_cast<sf::Uint8>(ClientPackets::PING);
		sendPacket(initialMessage);
	}
}


Game::~Game()
{
}
