#pragma once
class INetworkSitController
{
public:
	virtual void onCardsPut(std::vector<Card> &cards) = 0;
	virtual void onSitTake(int id) = 0;
};

