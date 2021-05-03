#pragma once
#include "interfaceView.h"
#include "accountInfoView.h"
#include "fullTripListView.h"
#include "routeRepo.h"

class loggedInInterface :
    public interfaceView
{
private:
	accountRepo* acctRep;
	routeRepo* routeRep;
	revenue* revenue_;
	Account* acct;
public:
	loggedInInterface(Account* account);
	loggedInInterface(Account* account, routeRepo* routeRepo, revenue* revenue);
	void preLoad();
	int menuLogic();
};

