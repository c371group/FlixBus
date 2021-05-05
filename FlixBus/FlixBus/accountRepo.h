#pragma once
#include <vector>
#include <iostream>
#include "Account.h"
#include "Revenue.h"
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>


/**
 * \brief Repository class, have vector of account objects. H
 */
class account_repo
{
private:
	// Vector of accounts.
	std::vector<account> accts;
public:
	// Base constructor.
	account_repo();
	// Returns vector of account objects.
	std::vector<account> get_accts() const;
	// Returns reference of an account object  from a vector.
	account* get_acc_by_index(int);
	// Returns reference to an account object from a vector by account_id
	account* get_acc_by_id(int);
	// Takes account object and adds it to a vector.
	void add_acct(account acct);
	// Loads data from csv.
	int read_acct_db();
	// Saves data to csv.
	void add_account_to_db(account acct);
};

