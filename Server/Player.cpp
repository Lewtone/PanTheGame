#include "Player.h"
#include "Server.h"


int Player::getPlayerSittingId(std::vector<std::shared_ptr<ServerSit>> &sits)
{
	for (auto& sit : sits)
		if (sit->getPlayerId() == id)
			return sit->getId();

	return -1;
}

Player::Player(int id)
{
	this->id = id;
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

void Player::sendOtherCardsInfo(std::vector<std::shared_ptr<ServerSit>>& sits)
{
	sf::Packet packet;
	packet << static_cast<sf::Uint8>(Server::OTHER_CARDS) << sits.size();
	
	for (int i = 0; i != sits.size(); ++i)
	{
		std::vector<ServerCard> currentSitCards = sits[i]->getCards();
		packet << currentSitCards.size();
	}

	this->send(packet);
}

void Player::sendInfoAboutCurrentTure(int currentTure)
{
	sf::Packet packet;
	packet << static_cast<sf::Uint8>(Server::CURRENT_TURE) << currentTure;
	
	this->send(packet);
}

void Player::sendSitInfo(std::vector<std::shared_ptr<ServerSit>>& sits)
{
	sf::Packet packet;
	packet << static_cast<sf::Uint8>(Server::SIT_INFO) << getPlayerSittingId(sits) << sits.size();

	for (int i = 0; i != sits.size(); ++i)
	{
		auto& sit = sits[i];
		if (sit->isTaken())
			packet << true << sit->getPlayerNickname();
		else
			packet << false;
	}

	this->send(packet);
}

void Player::sendPlayersAmount(int playersAmount)
{
	sf::Packet packet;
	packet << static_cast<sf::Uint8>(Server::PLAYER_AMOUNT) << playersAmount;

	this->send(packet);
}

void Player::setReady(bool state)
{
	this->ready = state;
}

bool Player::isReady()
{
	return ready;
}

const std::vector<ServerCard>& Player::getCards()
{
	return cards;
}

void Player::addCard(ServerCard card)
{
	cards.push_back(card);
}


Player::~Player()
{
}
