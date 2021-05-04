#pragma once
#include "interfaceView.h"
#include "accountRepo.h"
#include "routeRepo.h"



/**
 * \brief adminInterface, inherits from interfaceView. Used for managing administrator's view.
 */
class adminInterface : public interfaceView
{
private:
	// Reference to account repository.
	account_repo* acctRep;
	// Reference to route repository.
	route_repo* routeRep;
	// Reference to revenue repository.
	revenue* revenue_;
public:
	// Base constructor.
	adminInterface();
	// Constructor, takes account repository reference and assigns it to routeRep attribute.
	adminInterface(account_repo*);
	// Constructor, takes account repository, route repository and revenue references. Assign them to their corresponding attributes.
	adminInterface(account_repo*, route_repo*, revenue*);
	// Pre loading attributes and generates menu options.
	void preLoad(account_repo*);
	// Generates menu logic.
	int menuLogic(account_repo*);
	// Returns a reference to an account repository object.
	account_repo* getAcctRep();
};

