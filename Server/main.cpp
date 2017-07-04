#include <iostream>
#include <SFML\Network.hpp>

int main()
{
	sf::TcpListener listener;
	if (listener.listen(1337) != sf::Socket::Done)
	{
		std::cout << "There was an error when tried to listen\n";
	}

	sf::TcpSocket client;
	if (listener.accept(client) != sf::Socket::Done)
	{
		std::cout << "There was an error when tried to accept client\n";
	}

	sf::Packet packet;
	std::string helloPacket = "PING this is example of packet\n";
	packet << helloPacket;
	if (client.send(packet) != sf::Socket::Done)
	{
		std::cout << "There was an error when tried to send packet\n";
	}
	std::cout << "Hello world\n";
}