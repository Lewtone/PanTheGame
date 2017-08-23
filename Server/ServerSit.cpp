#include "ServerSit.h"



ServerSit::ServerSit(int id)
{
	this->id = id;
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

void ServerSit::addCard(ServerCard card)
{
	if (std::shared_ptr<Player> player = currentPlayer.lock())
		player->addCard(card);
}

const std::shared_ptr<Player> ServerSit::getPlayer()
{
	return currentPlayer.lock();
}

int ServerSit::getId()
{
	return id;
}


ServerSit::~ServerSit()
{
}
