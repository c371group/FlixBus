#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Account.h"

class accountRepo
{
private:
	std::vector<Account> accts;
public:
	accountRepo();
	std::vector<Account> getAccts();
	void add_acct(Account acct);
	int read_acct_db();
};

