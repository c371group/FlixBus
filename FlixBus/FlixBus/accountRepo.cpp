#include "accountRepo.h"

accountRepo::accountRepo()
{
	//TODO: probably read from file here, nothing fancy (or secure haha)
}

std::vector<Account> accountRepo::getAccts()
{
	return accts;
}

void accountRepo::add_acct(Account acct)
{
	accts.push_back(acct);
}