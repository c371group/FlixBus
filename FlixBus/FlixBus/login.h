#pragma once
#include <string>
#include <iostream>
#include "interfaceControl.h"
#include "Account.h"
#include "accountRepo.h"
#include "interfaceView.h"
class login :
    public interfaceView
{
private:
	accountRepo acctRep;
	std::string allegedUsername;
	std::string allegedPassword;
public:
	login(accountRepo acctRepo);
	void enter_username(int);
	void enter_password(int);
	void set_Alleged_Username(std::string);
	void set_Alleged_Password(std::string);
	std::string getAllegedUsername();
	std::string getAllegedPassword();
};

