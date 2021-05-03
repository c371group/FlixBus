#pragma once
#include <vector>
#include <iostream>
#include "Account.h"
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>


class accountRepo
{
private:
	std::vector<Account> accts;
public:
	accountRepo();
	std::vector<Account> getAccts();
	Account* get_acc_by_index(int);
	void add_acct(Account acct);
	int read_acct_db();
	void add_account_to_db(Account acct);
};

