#pragma once
#include <SFML\Network.hpp>
#include <memory>
#include "ServerCard.h"
#include "ServerSit.h"

class ServerSit;
class Player : public sf::TcpSocket
{
private:
	bool ready;
	int id;
	std::string nickname;
	std::vector<ServerCard> cards;

	int getPlayerSittingId(std::vector<std::shared_ptr<ServerSit>> &sits);
public:
	Player(int id);
	int getId();
	std::string getNickname();
	void sendMessage(std::string message);
	void sendCards();
	void sendOtherCardsInfo(std::vector<std::shared_ptr<ServerSit>>& sits);
	void sendInfoAboutCurrentTure(int currentTure);
	void sendSitInfo(std::vector<std::shared_ptr<ServerSit>> &sits);
	void sendPlayersAmount(int playersAmount);
	void setReady(bool state);
	bool isReady();
	const std::vector<ServerCard> &getCards();
	void addCard(ServerCard card);
	~Player();

	enum Packets
	{
		PING = 0,
		TAKE_SIT,
		PUT_CARDS
	};
};

