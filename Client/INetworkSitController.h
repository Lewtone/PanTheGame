#pragma once
class INetworkSitController
{
public:
	virtual void onCardsPut() = 0;
	virtual void onSitTake(int id) = 0;
};

