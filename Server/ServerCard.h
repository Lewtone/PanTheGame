#pragma once

enum Suit
{
	CLUBS = 0,
	DIAMONDS,
	HEARTS,
	SPADES
};

enum Rank
{
	NINE = 0,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE
};

class ServerCard
{
private:
	Suit suit;
	Rank rank;
public:
	ServerCard(Suit suit, Rank rank);
	Suit getSuit();
	Rank getRank();
	~ServerCard();
};

