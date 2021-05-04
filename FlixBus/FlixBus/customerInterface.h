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
	account_repo* acctRep;
	route_repo* routeRep;
	revenue* revenue_;
public:
	customerInterface();
	customerInterface(account_repo*);
	customerInterface(account_repo*, route_repo*, revenue*);
	void preLoad(account_repo*); //might need to put reference here too
	int menuLogic();
	account_repo* getAcctRep();
};

