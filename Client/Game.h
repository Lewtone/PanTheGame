#pragma once
#include <vector>
#include "INetworkSitController.h"
#include "INetworkStackController.h"
#include <SFML\Graphics.hpp>
#include <SFML\Network.hpp>
#include "PlayerSit.h"
#include "AssetsManager.h"
#include "CardStack.h"
#include "ArrowWidget.h"

class Game : public INetworkSitController, public INetworkStackController, public sf::Drawable
{
private:
	static constexpr int PLAYER_SITS_AMOUT = 4;
	sf::TcpSocket socket;
	AssetsManager assetsManager;
	std::vector<PlayerSit> sits;
	CardStack stack;
	ArrowWidget arrow;
	int mySitId = -1;
	int currentTureSitId = -1;

	void setupSits(sf::RenderWindow& window);
	void setupStack(sf::RenderWindow& window);

	virtual void onStackCardGet() override;
	virtual void onCardsPut(std::vector<Card> &cards) override;
	virtual void onSitTake(int id) override;

	void handlePacket(sf::Packet& packet);
	void sendPacket(sf::Packet& packet);
	void onPong(sf::Packet& packet);
	void onMsg(sf::Packet& packet);
	void onPlayerAmount(sf::Packet& packet);
	void onMyCards(sf::Packet& packet);
	void onOtherCards(sf::Packet& packet);
	void onStackCards(sf::Packet& packet);
	void onSitInfo(sf::Packet& packet);
	void onCurrentTure(sf::Packet& packet);
public:
	Game();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void setup(sf::RenderWindow& window);
	void handleEvent(const sf::Event& event);
	void doNetworkStuff();
	void connect();

	enum ServerPackets
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

	enum ClientPackets
	{
		PING = 0,
		TAKE_SIT,
		PUT_CARDS
	};
	~Game();
};

