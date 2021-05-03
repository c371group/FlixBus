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
	accountRepo* acctRep;
	routeRepo* routeRep;
	revenue* revenue_;
	std::string allegedUsername;
	std::string allegedPassword;
public:
	login(accountRepo* acctRepo);
	login(accountRepo* acctRepo, routeRepo* routeRepo, revenue* revenue);
	int enter_username();
	void enter_password(int);
	void set_Alleged_Username(std::string);
	void set_Alleged_Password(std::string);
	std::string getAllegedUsername();
	std::string getAllegedPassword();
};

