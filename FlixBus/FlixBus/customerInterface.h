#pragma once
#include "interfaceView.h"
#include "accountRepo.h"
#include "registration.h"
#include "login.h"
#include "routeRepo.h"

class customerInterface :
    public interfaceView
{
private:
	accountRepo* acctRep;
	routeRepo* routeRep;
public:
	customerInterface();
	customerInterface(accountRepo*);
	customerInterface(accountRepo*, routeRepo*);
	void preLoad(accountRepo*); //might need to put reference here too
	int menuLogic();
	accountRepo* getAcctRep();
};

