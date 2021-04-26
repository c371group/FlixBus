#pragma once
#include "interfaceView.h"
#include "accountInfoView.h"
#include "fullTripListView.h"
class loggedInInterface :
    public interfaceView
{
private:
	accountRepo acctRep;
	Account acct;
public:
	loggedInInterface(Account& account);
	void preLoad();
	int menuLogic();
};

