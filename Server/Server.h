#pragma once
#include <SFML\Network.hpp>
#include "ServerGame.h"
#include <iostream>
class Server
{
private:
	int currentId = 0;
	sf::TcpListener listener;
	sf::SocketSelector selector;
	ServerGame game;
	void loop();
	void checkForListener();
	void checkForSockets();
	void handlePacket(const std::shared_ptr<Player>& player, sf::Packet& packet);
public:
	Server();
	void run();
	~Server();

	enum Packets
	{
		PONG = 0,
		MSG,
		PLAYER_AMOUNT,
		MY_CARDS,
		OTHER_CARDS,
		STACK_CARDS,
		CURRENT_TURE,
		SIT_INFO
	};
};

