#pragma once
#include "Player.h"
#include "ServerCard.h"
#include <memory>

class Player;
class ServerSit
{
private:
	std::weak_ptr<Player> currentPlayer;
	int id;
public:
	ServerSit(int id);
	bool isTaken();
	std::vector<ServerCard> getCards();
	int getPlayerId();
	std::string getPlayerNickname();
	void setPlayer(const std::shared_ptr<Player> &player);
	void free();
	bool isReady();
	void addCard(ServerCard card);
	const std::shared_ptr<Player> getPlayer();
	int getId();
	~ServerSit();
};

