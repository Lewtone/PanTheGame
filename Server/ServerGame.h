#pragma once
#include "Player.h"
#include "ServerSit.h"
#include <memory>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

class ServerGame
{
private:
	static const int SITS_SIZE = 4;
	std::vector<std::shared_ptr<Player>> players;
	std::vector<std::shared_ptr<ServerSit>> sits;
	std::vector<int> playingSitsId;
	int currentSitTure = 0;
	bool started = false;

	void startGame();
	std::vector<ServerCard> getAllPossibleCards();
	void shuffleVector(std::vector<ServerCard>& cards);
public:
	ServerGame();
	void addPlayer(std::shared_ptr<Player> player);
	void deletePlayer(std::vector<std::shared_ptr<Player>>::iterator it);
	bool canStartGame();
	std::vector<std::shared_ptr<Player>>& getPlayers();

	void onPing(const std::shared_ptr<Player> & player, sf::Packet & packet);
	void onTakeSit(const std::shared_ptr<Player> & player, sf::Packet & packet);
	~ServerGame();
};

