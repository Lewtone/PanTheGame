#include "Player.h"
#include "Server.h"


Player::Player()
{
}

void Player::sendMessage(std::string message)
{
	sf::Packet packet;
	packet << static_cast<sf::Uint8>(Server::MSG) << message;
	this->send(packet);
}


Player::~Player()
{
}
