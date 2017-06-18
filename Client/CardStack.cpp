#include "CardStack.h"



void CardStack::onClicked(Card & card)
{
	card.setOppositeState();
}

void CardStack::onGetFocus()
{
	std::cout << "Focus get\n";
}

void CardStack::onLostFocus()
{
	std::cout << "Focus lost\n";
}

CardStack::CardStack()
{
}


CardStack::~CardStack()
{
}
