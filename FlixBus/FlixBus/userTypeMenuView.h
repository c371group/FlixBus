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
	accountRepo* acctRep;
	// Reference to route repository object.
	routeRepo* routeRep;
	// Reference to revenue object.
	revenue* revenue_;
public:
	// Constructor that assigns account repository reference.
	userTypeMenuView(accountRepo*);
	// Constructor takes account repository, route repository and revenue references.
	userTypeMenuView(accountRepo*, routeRepo*, revenue*);
	// Prepared the menu
	void preLoad(accountRepo*);
	// Menu logic is located here.
	int menuLogic();
	// Returns reference of an account repository.
	accountRepo* getAcctRep();
};



