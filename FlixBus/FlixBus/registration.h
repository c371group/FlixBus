#pragma once
#include <string>
#include <iostream>
#include "interfaceControl.h"
#include "interfaceView.h"
#include "Account.h"
#include "accountRepo.h"


class registration :
	public interfaceView
	//this might seem redundant, but we want to ensure we're not creating account objects with empty parameters
{
private:
	std::vector<std::string> responses_;
	std::string username_, password_;
	std::string user_id_, f_name_, l_name_, address_, email_, contact_number_;
	customer finalCustomer;
	account finalAccount;
public:
	registration(account_repo* acctRepo);
	void humanData();
	void populate();
	void createAcct();
	void addToRepo(account_repo*);
	void finalCreation(account_repo*);
	void acctData();
	void createCustomer();
	void set_username(std::string);
	void set_username_extended();
	void set_password(std::string);
	void set_password_extended();
	void set_user_id(std::string);
	void set_first_name(std::string);
	void set_last_name(std::string);
	void set_address(std::string);
	void set_email(std::string);
	void set_contact_number(std::string);
	void set_final_customer(customer);
	void set_final_account(account);

	std::string get_username() const;
	std::string get_password() const;
	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_address() const;
	std::string get_email() const;
	std::string get_contact_number() const;
	customer get_final_customer();
	account get_final_account();
};
