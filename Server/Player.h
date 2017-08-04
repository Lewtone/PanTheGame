#pragma once
#include <SFML\Network.hpp>
#include <memory>
#include "ServerCard.h"
#include "ServerSit.h"

class ServerSit;
class Player : public sf::TcpSocket
{
private:
	int id;
	std::string nickname;
	std::vector<ServerCard> cards;
public:
	Player();
	int getId();
	std::string getNickname();
	void sendMessage(std::string message);
	void sendCards();
	void sendOtherCardsInfo(std::vector<std::unique_ptr<ServerSit>>& sits);
	void sendInfoAboutCurrentTure(int currentTure);
	void sendSitInfo(std::vector<std::unique_ptr<ServerSit>> &sits);
	const std::vector<ServerCard> &getCards();
	~Player();

	enum Packets
	{
		PING = 0
	};
};

