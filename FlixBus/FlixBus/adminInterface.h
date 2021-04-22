#pragma once
#include "interfaceView.h"
#include "accountRepo.h"
class adminInterface : public interfaceView
{
private:
	accountRepo acctRep;
public:
	adminInterface();
	adminInterface(accountRepo&);
	void preLoad(accountRepo&); //might need to put reference here too
	int menuLogic();
	accountRepo getAcctRep();
};

