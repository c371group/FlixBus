#include "accountRepo.h"

accountRepo::accountRepo()
{
	/* Loads AccountsDB into acctRepo the moment the object is created-- while this
	implementation has an unfeasible time complexity with a large userbase, it
	works for the small userbase of this demo without any hassle. */
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
	/* Prints new account to new line of csv file-- I tried to see if I could automatically
	add a delimiter somehow, but everything I found is too complex for this to be honest. If
	anyone wants to have a go at it, be my guest. */

	std::ofstream fout;
	/* Opens AccountsDB.csv-- if the file is not already present, creates it.
	Not sure we can count on that last part, however, because of how Visual Studio
	handles csv files and having to manually add them to the solution for the project. 
	If you have any questions or comments about this, contact Mason. */
	fout.open("AccountsDB.csv", std::ios::app); 
	fout << std::endl;
	fout << acct.get_username() << "," << acct.get_password() << ",";
	fout << acct.get_customer().getFirstName() << "," << acct.get_customer().getLastName() << ",";
	fout << acct.get_customer().getEmail() << "," << acct.get_customer().getAddress() << ",";   //send to file
	fout << acct.get_customer().getContactNumber() << std::endl;
	fout.close();       //close file
}