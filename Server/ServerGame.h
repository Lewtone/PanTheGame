#pragma once
#include "Player.h"
#include <memory>
#include <vector>
#include <iostream>
class ServerGame
{
private:
	std::vector<std::unique_ptr<Player>> players;
public:
	ServerGame();
	void addPlayer(std::unique_ptr<Player> player);
	void deletePlayer(std::vector<std::unique_ptr<Player>>::iterator it);
	std::vector<std::unique_ptr<Player>>& getPlayers();

	void onPing(Player * player, sf::Packet & packet);
	~ServerGame();
};

