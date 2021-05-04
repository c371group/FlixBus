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
	accountRepo* acctRep;
	// Reference to route repository.
	routeRepo* routeRep;
	// Reference to revenue repository.
	revenue* revenue_;
public:
	// Base constructor.
	adminInterface();
	// Constructor, takes account repository reference and assigns it to routeRep attribute.
	adminInterface(accountRepo*);
	// Constructor, takes account repository, route repository and revenue references. Assign them to their corresponding attributes.
	adminInterface(accountRepo*, routeRepo*, revenue*);
	// Pre loading attributes and generates menu options.
	void preLoad(accountRepo*);
	// Generates menu logic.
	int menuLogic(accountRepo*);
	// Returns a reference to an account repository object.
	accountRepo* getAcctRep();
};

