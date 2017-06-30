#pragma once
#include "INetworkSitController.h"
#include "INetworkStackController.h"
#include <SFML\Graphics.hpp>

class Game : public INetworkSitController, public INetworkStackController, public sf::Drawable
{
public:
	Game();
	~Game();
};

