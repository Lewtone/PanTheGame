#include "ServerCard.h"



ServerCard::ServerCard(Suit suit, Rank rank) :
	suit(suit),
	rank(rank)
{
}

Suit ServerCard::getSuit()
{
	return suit;
}

Rank ServerCard::getRank()
{
	return rank;
}


ServerCard::~ServerCard()
{
}
