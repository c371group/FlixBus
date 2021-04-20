#pragma once
#include "interfaceView.h"
#include "customerInterface.h"
#include "accountRepo.h"
#include "adminInterface.h"

class userTypeMenuView :
	public interfaceView
{
private:
	accountRepo acctRep;
public:
	userTypeMenuView(accountRepo&);
	void preLoad(accountRepo&);
	int menuLogic();
	accountRepo getAcctRep();
};



