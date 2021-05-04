#pragma once
#include <string>
#include <iostream>
#include "interfaceControl.h"
#include "Account.h"
#include "accountRepo.h"
#include "interfaceView.h"
#include "loggedInInterface.h"

class login :
    public interfaceView
{
private:
	account_repo* acctRep;
	route_repo* routeRep;
	revenue* revenue_;
	std::string allegedUsername;
	std::string allegedPassword;
public:
	login(account_repo* acctRepo);
	login(account_repo* acctRepo, route_repo* routeRepo, revenue* revenue);
	int enter_username();
	void enter_password(int);
	void set_Alleged_Username(std::string);
	void set_Alleged_Password(std::string);
	std::string getAllegedUsername();
	std::string getAllegedPassword();
};

