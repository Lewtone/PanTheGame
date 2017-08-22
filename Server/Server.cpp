#include "Server.h"




Server::Server()
{
}

void Server::run()
{
	listener.listen(1337);
	selector.add(listener);
	loop();
}

void Server::loop()
{
	while (true)
	{
		if (selector.wait())
		{
			checkForListener();
			checkForSockets();
		}
	}
}

void Server::checkForListener()
{
	if (!selector.isReady(listener))
		return;

	std::shared_ptr<Player> player = std::make_shared<Player>(currentId);
	listener.accept(*player);
	selector.add(*player);
	game.addPlayer(std::move(player));

	currentId++;
}

void Server::checkForSockets()
{
	auto& players = game.getPlayers();
	for (auto it = players.begin(); it != players.end(); ++it)
	{
		std::shared_ptr<Player> player = *it;
		if (selector.isReady(*player))
		{
			std::cout << "Selector signals ready\n";
			sf::Packet packet;
			if (player->receive(packet) == sf::Socket::Done)
				handlePacket(player, packet);
			else if (player->receive(packet) == sf::Socket::Disconnected)
			{
				game.deletePlayer(it);
				selector.remove(*player);
				return;
			}
		}
	}
}

void Server::handlePacket(const std::shared_ptr<Player>& player, sf::Packet & packet)
{
	sf::Uint8 header;
	if (!(packet >> header))
		return;

	switch (header)
	{
	case Player::Packets::PING:
		game.onPing(player, packet);
		break;
	case Player::Packets::TAKE_SIT:
		game.onTakeSit(player, packet);
		break;
	default:
		break;
	}
}

Server::~Server()
{
}
