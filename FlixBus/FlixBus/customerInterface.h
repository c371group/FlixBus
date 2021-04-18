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
	customerInterface(accountRepo);
	void preLoad(accountRepo acctRep);
	int menuLogic();
	accountRepo getAcctRep();
};

