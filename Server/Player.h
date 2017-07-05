#pragma once
#include <SFML\Network.hpp>

class Player : public sf::TcpSocket
{
public:
	Player();
	~Player();
};

