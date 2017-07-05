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

	std::unique_ptr<Player> player = std::make_unique<Player>();
	listener.accept(*player);
	game.addPlayer(std::move(player));
}

void Server::checkForSockets()
{
	auto& players = game.getPlayers();
	for (auto it = players.begin(); it != players.end(); ++it)
	{
		Player* player = it->get();
		if (selector.isReady(*player))
		{
			std::cout << "Selector signals ready\n";
			sf::Packet packet;
			if (player->receive(packet) == sf::Socket::Done)
				handlePacket(player, packet);
			else if (player->receive(packet) == sf::Socket::Disconnected)
			{
				game.deletePlayer(it);
				return;
			}
		}
	}
}

void Server::handlePacket(Player * player, sf::Packet & packet)
{
	std::string message;
	packet >> message;
	std::cout << message << std::endl;
}

Server::~Server()
{
}
