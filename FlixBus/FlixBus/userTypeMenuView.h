#pragma once
#include "interfaceView.h"
#include "customerInterface.h"
#include "accountRepo.h"
#include "adminInterface.h"
#include "routeRepo.h"


/**
 * \brief userTypeMenuView gives control over user menu. Inherits from interfaceView.
 */
class userTypeMenuView :
	public interfaceView
{
private:
	// Reference to account repository object.
	account_repo* acctRep;
	// Reference to route repository object.
	route_repo* routeRep;
	// Reference to revenue object.
	revenue* revenue_;
public:
	// Constructor that assigns account repository reference.
	userTypeMenuView(account_repo*);
	// Constructor takes account repository, route repository and revenue references.
	userTypeMenuView(account_repo*, route_repo*, revenue*);
	// Prepared the menu
	void preLoad(account_repo*);
	// Menu logic is located here.
	int menuLogic();
	// Returns reference of an account repository.
	account_repo* getAcctRep();
};



