#pragma once
#include <SFML\Network.hpp>

class Player : public sf::TcpSocket
{
public:
	Player();
	void sendMessage(std::string message);
	~Player();

	enum Packets
	{
		PING = 0
	};
};

