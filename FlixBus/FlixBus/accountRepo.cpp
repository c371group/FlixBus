#include "accountRepo.h"

accountRepo::accountRepo()
{
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

void accountRepo::add_account_to_db(Account acct) {
	std::ofstream fout;
	fout.open("AccountsDB.csv", std::ios::app);
	fout << std::endl;
	fout << acct.get_username() << "," << acct.get_password() << ",";
	fout << acct.get_customer().getFirstName() << "," << acct.get_customer().getLastName() << ",";
	fout << acct.get_customer().getEmail() << "," << acct.get_customer().getAddress() << ",";   //send to file
	fout << acct.get_customer().getContactNumber() << std::endl;
	fout.close();       //close file
}