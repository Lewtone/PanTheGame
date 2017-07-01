#pragma once
#include "CardContainer.h"
#include <iostream>
#include "INetworkStackController.h"
class CardStack :
	public CardContainer
{
private:
	virtual void onClicked(Card &card) override;
	virtual void onGetFocus() override;
	virtual void onLostFocus() override;
	INetworkStackController* controller;
public:
	CardStack(INetworkStackController* controller);
	virtual ~CardStack();
};

