#pragma once
#include "INetworkSitController.h"
#include "INetworkStackController.h"
#include <SFML\Graphics.hpp>
#include <SFML\Network.hpp>
#include "PlayerSit.h"
#include "AssetsManager.h"

class Game : public INetworkSitController, public INetworkStackController, public sf::Drawable
{
private:
	sf::TcpSocket socket;
	AssetsManager assetsManager;
	std::array<PlayerSit, 4> sits;

	void setupSits(sf::RenderWindow& window);
public:
	Game();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void setup(sf::RenderWindow& window);
	~Game();
};

