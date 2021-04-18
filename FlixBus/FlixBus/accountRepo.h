#pragma once
#include <vector>
#include "Account.h"

class accountRepo
{
private:
	std::vector<Account> accts;
public:
	accountRepo();
	std::vector<Account> getAccts();
	void add_acct(Account acct);
};

