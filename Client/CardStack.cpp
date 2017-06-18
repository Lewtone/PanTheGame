#include "CardStack.h"



void CardStack::onClicked(Card & card)
{
	std::cout << "Stack card clicked\n";
}

void CardStack::onGetFocus()
{
	std::cout << "Focus get\n";
	for (size_t i = this->cards.size() - 1; i > 0; --i)
		this->cards.at(i).hover();
}

void CardStack::onLostFocus()
{
	std::cout << "Focus lost\n";
	for (size_t i =0; i < this->cards.size(); ++i)
		this->cards.at(i).unhover();
}

CardStack::CardStack()
{
}


CardStack::~CardStack()
{
}
