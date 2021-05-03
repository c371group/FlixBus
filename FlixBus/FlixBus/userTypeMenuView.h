#pragma once
#include "interfaceView.h"
#include "customerInterface.h"
#include "accountRepo.h"
#include "adminInterface.h"
#include "routeRepo.h"

class userTypeMenuView :
	public interfaceView
{
private:
	accountRepo acctRep;
	routeRepo* routeRep;
public:
	userTypeMenuView(accountRepo&);
	userTypeMenuView(accountRepo&, routeRepo*);
	void preLoad(accountRepo&);
	int menuLogic();
	accountRepo getAcctRep();
};



