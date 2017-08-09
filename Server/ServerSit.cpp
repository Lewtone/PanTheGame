#include "ServerSit.h"



ServerSit::ServerSit()
{
}

bool ServerSit::isTaken()
{
	return !currentPlayer.expired();
}

std::vector<ServerCard> ServerSit::getCards()
{
	if (std::shared_ptr<Player> player = currentPlayer.lock())
		return player->getCards();

	return std::vector<ServerCard>();
}

int ServerSit::getPlayerId()
{
	if (std::shared_ptr<Player> player = currentPlayer.lock())
		return player->getId();

	return -1;
}

std::string ServerSit::getPlayerNickname()
{
	if (std::shared_ptr<Player> player = currentPlayer.lock())
		return player->getNickname();

	return "";
}

void ServerSit::setPlayer(const std::shared_ptr<Player>& player)
{
	this->currentPlayer = player;
}

void ServerSit::free()
{
	this->currentPlayer.reset();
}

bool ServerSit::isReady()
{
	if (std::shared_ptr<Player> player = currentPlayer.lock())
		return player->isReady();

	return false;
}


ServerSit::~ServerSit()
{
}
