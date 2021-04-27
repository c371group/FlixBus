#include "accountRepo.h"

accountRepo::accountRepo()
{
	/*//TODO: probably read from file here, nothing fancy (or secure haha)
	//DUMMY DATA BELOW, DELETE LATER
	Account dummyAcct0 = Account(Customer(0), 0);
	Account dummyAcct1 = Account(Customer(1), 1);
	Account dummyAcct2 = Account(Customer(2), 2);
	Account dummyAcct3 = Account(Customer(3), 3);
	Account dummyAcct4 = Account(Customer(4), 4);
	Account dummyAcct5 = Account(Customer(5), 5);
	std::vector<Account> acctList = { dummyAcct0, dummyAcct1, dummyAcct2, dummyAcct3, dummyAcct4, dummyAcct5 };
	for (auto& acct : acctList)
	{
		add_acct(acct);
	}*/
	read_acct_db();
}

std::vector<Account> accountRepo::getAccts()
{
	return this->accts;
}

void accountRepo::add_acct(Account acct)
{
	accts.push_back(acct);
}

int accountRepo::read_acct_db() {
	std::ifstream input_from_file("AccountsDB.csv");
	std::string line;
	int lineno = 0; //line number
	while (getline(input_from_file, line)) {
		lineno++;
		line += ",";

		std::stringstream ss(line);
		std::string word;
		std::vector<std::string> words;

		while (getline(ss, word, ','))
			words.push_back(word);
		Customer cust = Customer(words[2], words[3], words[4], words[5], words[6]);
		Account acct = Account(cust, words[0], words[1]);
		add_acct(acct);
	}
	return 0;
}