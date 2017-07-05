#include "ServerGame.h"



ServerGame::ServerGame()
{
}

void ServerGame::addPlayer(std::unique_ptr<Player> player)
{
	players.push_back(std::move(player));
	sf::Packet packet;
	std::string testString = "PING Hello World";
	packet << testString;
	players.back()->send(packet);
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


ServerGame::~ServerGame()
{
}
