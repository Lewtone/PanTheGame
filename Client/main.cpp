#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Pan The Game");
	sf::Texture texture;
	texture.loadFromFile("assets/cards.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(560*2, 780*0, 560, 780));
	sprite.setScale(0.5f, 0.5f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Green);
		window.draw(sprite);
		window.display();
	}

	return 0;
}