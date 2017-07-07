#pragma once
#include <SFML\Network.hpp>
#include "ServerGame.h"
#include <iostream>
class Server
{
private:
	sf::TcpListener listener;
	sf::SocketSelector selector;
	ServerGame game;
	void loop();
	void checkForListener();
	void checkForSockets();
	void handlePacket(Player* player, sf::Packet& packet);
public:
	Server();
	void run();
	~Server();

	enum Packets
	{
		PONG = 0,
		MSG
	};
};

