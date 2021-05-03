#pragma once
#include "interfaceView.h"
#include "accountRepo.h"
#include "routeRepo.h"

class adminInterface : public interfaceView
{
private:
	accountRepo* acctRep;
	routeRepo* routeRep;
public:
	adminInterface();
	adminInterface(accountRepo*);
	adminInterface(accountRepo*, routeRepo*);
	void preLoad(accountRepo*); //might need to put reference here too
	int menuLogic(accountRepo*);
	accountRepo* getAcctRep();
};

