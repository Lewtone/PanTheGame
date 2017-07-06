#include "ServerGame.h"
#include "Server.h"


ServerGame::ServerGame()
{
}

void ServerGame::addPlayer(std::unique_ptr<Player> player)
{
	players.push_back(std::move(player));
}

void ServerGame::deletePlayer(std::vector<std::unique_ptr<Player>>::iterator it)
{
	std::cout << "Size of players: " << players.size() << std::endl;
	players.erase(it);
	std::cout << "Size of players: " << players.size() << std::endl;
}

std::vector<std::unique_ptr<Player>>& ServerGame::getPlayers()
{
	return players;
}


void ServerGame::onPing(Player * player, sf::Packet & packet)
{
	std::cout << "got PING from client\n";
	sf::Packet replyPacket;
	replyPacket << static_cast<sf::Uint8>(Server::Packets::PONG);
	player->send(replyPacket);
}

ServerGame::~ServerGame()
{
}
