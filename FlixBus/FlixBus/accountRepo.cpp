#include "accountRepo.h"

accountRepo::accountRepo()
{
	//TODO: probably read from file here, nothing fancy (or secure haha)
	//DUMMY DATA BELOW, DELETE LATER
	Account dummyAcct0 = Account(Customer(0), 0);
	Account dummyAcct1 = Account(Customer(1), 1);
	Account dummyAcct2 = Account(Customer(2), 2);
	Account dummyAcct3 = Account(Customer(3), 3);
	Account dummyAcct4 = Account(Customer(4), 4);
	Account dummyAcct5 = Account(Customer(5), 5);
	add_acct(dummyAcct0);
	add_acct(dummyAcct1);
	add_acct(dummyAcct2);
	add_acct(dummyAcct3);
	add_acct(dummyAcct4);
	add_acct(dummyAcct5);
}

std::vector<Account> accountRepo::getAccts()
{
	return this->accts;
}

void accountRepo::add_acct(Account acct)
{
	accts.push_back(acct);
}