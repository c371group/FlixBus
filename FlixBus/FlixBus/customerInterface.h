#pragma once
#include "interfaceView.h"
#include "accountRepo.h"
#include "registration.h"
#include "login.h"

class customerInterface :
    public interfaceView
{
private:
	accountRepo acctRep;
public:
	customerInterface();
	customerInterface(accountRepo&);
	void preLoad(accountRepo&); //might need to put reference here too
	int menuLogic();
	accountRepo getAcctRep();
};

