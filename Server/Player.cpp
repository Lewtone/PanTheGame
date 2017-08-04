#include "Player.h"
#include "Server.h"


Player::Player()
{
}

int Player::getId()
{
	return id;
}

std::string Player::getNickname()
{
	return nickname;
}

void Player::sendMessage(std::string message)
{
	sf::Packet packet;
	packet << static_cast<sf::Uint8>(Server::MSG) << message;
	this->send(packet);
}

void Player::sendCards()
{
	sf::Packet packet;
	packet << static_cast<sf::Uint8>(Server::MY_CARDS) << cards.size();

	for (auto& card : cards)
		packet << static_cast<sf::Uint8>(card.getRank()) << static_cast<sf::Uint8>(card.getSuit());

	this->send(packet);
}

void Player::sendOtherCardsInfo(std::vector<std::unique_ptr<ServerSit>>& sits)
{
	sf::Packet packet;
	packet << static_cast<sf::Uint8>(Server::OTHER_CARDS) << sits.size();
	
	for (int i = 0; i != sits.size(); ++i)
	{
		std::vector<ServerCard> currentSitCards = sits[i]->getCards();
		packet << i << currentSitCards.size();
	}

	this->send(packet);
}

void Player::sendInfoAboutCurrentTure(int currentTure)
{
	sf::Packet packet;
	packet << static_cast<sf::Uint8>(Server::CURRENT_TURE) << currentTure;
	
	this->send(packet);
}

void Player::sendSitInfo(std::vector<std::unique_ptr<ServerSit>>& sits)
{
	sf::Packet packet;
	packet << static_cast<sf::Uint8>(Server::SIT_INFO) << sits.size();

	for (int i = 0; i != sits.size(); ++i)
	{
		auto& sit = sits[i];
		if (sit->isTaken())
			packet << i << sit->getPlayerNickname();
	}

	this->send(packet);
}

const std::vector<ServerCard>& Player::getCards()
{
	return cards;
}


Player::~Player()
{
}
