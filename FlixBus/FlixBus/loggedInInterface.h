#pragma once
#include "interfaceView.h"
#include "accountInfoView.h"
#include "fullTripListView.h"
#include "routeRepo.h"

class loggedInInterface :
    public interfaceView
{
private:
	account_repo* acctRep;
	route_repo* routeRep;
	revenue* revenue_;
	account* acct;
public:
	loggedInInterface(account* account);
	loggedInInterface(account* account, route_repo* routeRepo, revenue* revenue);
	void preLoad();
	int menuLogic();
};

