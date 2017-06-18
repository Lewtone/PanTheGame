#pragma once
#include "CardContainer.h"
#include <iostream>
class CardStack :
	public CardContainer
{
private:
	virtual void onClicked(Card &card) override;
	virtual void onGetFocus() override;
	virtual void onLostFocus() override;
public:
	CardStack();
	virtual ~CardStack();
};

