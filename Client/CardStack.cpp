#include "CardStack.h"



void CardStack::onClicked(Card & card)
{
	std::cout << "Clicked\n";
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
