#pragma once
#include <array>
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
	sf::TcpSocket socket;
	AssetsManager assetsManager;
	std::array<PlayerSit, 4> sits;
	CardStack stack;
	ArrowWidget arrow;

	void setupSits(sf::RenderWindow& window);
	void setupStack(sf::RenderWindow& window);

	virtual void onStackCardGet() override;
	virtual void onCardsPut() override;
	virtual void onSitTake() override;
public:
	Game();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void setup(sf::RenderWindow& window);
	void handleEvent(const sf::Event& event);
	~Game();
};

