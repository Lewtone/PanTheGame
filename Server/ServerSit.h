#pragma once
#include "Player.h"
#include <memory>

class Player;
class ServerSit
{
private:
	std::weak_ptr<Player> currentPlayer;
	int id;
public:
	ServerSit();
	bool isTaken();
	std::vector<ServerCard> getCards();
	int getPlayerId();
	std::string getPlayerNickname();
	void setPlayer(const std::shared_ptr<Player> &player);
	void free();
	bool isReady();
	~ServerSit();
};

