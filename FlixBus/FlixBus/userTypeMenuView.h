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
	accountRepo* acctRep;
	routeRepo* routeRep;
	revenue* revenue_;
public:
	userTypeMenuView(accountRepo*);
	userTypeMenuView(accountRepo*, routeRepo*, revenue*);
	void preLoad(accountRepo*);
	int menuLogic();
	accountRepo* getAcctRep();
};



