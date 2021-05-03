#pragma once
#include <vector>
#include <iostream>
#include "Account.h"
#include "Revenue.h"
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>


class accountRepo
{
private:
	std::vector<Account> accts;
	revenue revenue_;
public:
	accountRepo();
	explicit accountRepo(revenue);
	std::vector<Account> getAccts();
	Account* get_acc_by_index(int);
	revenue* get_revenue();
	void add_acct(Account acct);
	void set_revenue(revenue);
	int read_acct_db();
	void add_account_to_db(Account acct);
};

