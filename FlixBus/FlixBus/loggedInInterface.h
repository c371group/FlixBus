#pragma once
#include "interfaceView.h"
class loggedInInterface :
    public interfaceView
{
private:
	accountRepo acctRep;
public:
	loggedInInterface(Account& account);
	void preLoad();
	int menuLogic();
};

