#pragma once
#include "interfaceView.h"
#include "accountRepo.h"
#include "registration.h"
class customerInterface :
    public interfaceView
{
private:
	accountRepo acctRep;
public:
	customerInterface();
	customerInterface(accountRepo);
	void preLoad(accountRepo acctRep);
	int menuLogic();
	accountRepo getAcctRep();
};

