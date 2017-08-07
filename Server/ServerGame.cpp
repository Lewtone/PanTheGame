#include "ServerGame.h"
#include "Server.h"


ServerGame::ServerGame()
{
	for (int i = 0; i != SITS_SIZE; ++i)
		sits.push_back(std::make_shared<ServerSit>());
}

void ServerGame::addPlayer(std::shared_ptr<Player> player)
{
	players.push_back(std::move(player));

	player->sendSitInfo(sits);
}

void ServerGame::deletePlayer(std::vector<std::shared_ptr<Player>>::iterator it)
{
	std::cout << "Size of players: " << players.size() << std::endl;
	players.erase(it);
	std::cout << "Size of players: " << players.size() << std::endl;
}

std::vector<std::shared_ptr<Player>>& ServerGame::getPlayers()
{
	return players;
}


void ServerGame::onPing(const std::shared_ptr<Player> & player, sf::Packet & packet)
{
	std::cout << "got PING from client\n";
	sf::Packet replyPacket;
	replyPacket << static_cast<sf::Uint8>(Server::Packets::PONG);
	player->send(replyPacket);
	player->sendMessage("Hello, everything is going well!");
}

void ServerGame::onTakeSit(const std::shared_ptr<Player> & player, sf::Packet & packet)
{
	int wantedSitId = -1;
	packet >> wantedSitId;

	if (wantedSitId < 0 || wantedSitId >= sits.size())
	{
		player->sendMessage("There isn't sit with this id.");
		return;
	}

	const std::shared_ptr<ServerSit> &sit = sits[wantedSitId];

	if (sit->isTaken())
	{
		player->sendMessage("This sit is already taken!");
		return;
	}

	for (auto& sit : sits)
		if (sit->getPlayerId() == player->getId())
			sit->free();

	sit->setPlayer(player);

	for (auto& player : players)
		player->sendSitInfo(sits);

}

ServerGame::~ServerGame()
{
}
