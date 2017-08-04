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


ServerSit::~ServerSit()
{
}
