#include "accountRepo.h"

// Base constructor.
account_repo::account_repo()
{
	/* Loads AccountsDB into acctRepo the moment the object is created-- while this
	implementation has an unfeasible time complexity with a large userbase, it
	works for the small userbase of this demo without any hassle. */
	read_acct_db();
}

// Returns vector of account objects.
std::vector<account> account_repo::get_accts() const
{
	return this->accts;
}

// Returns reference of an account object  from a vector.
account* account_repo::get_acc_by_index(int indx)
{
	return &this->accts[indx];
}

// Returns reference to an account object from a vector by account_id
account* account_repo::get_acc_by_id(int id)
{
	int index = 0;
	for(auto & acc: this->accts)
	{
		if(acc.get_acct_id().id == id)
		{
			return &this->accts[index];
		}
		index++;
	}
}

// Takes account object and adds it to a vector.
void account_repo::add_acct(account acct)
{
	accts.push_back(acct);
}

// Loads data from csv.
int account_repo::read_acct_db() {
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
		customer cust = customer(words[3], words[4], words[5], words[6], words[7]);
		account acct = account(cust, words[1], words[2]);
		add_acct(acct);
	}
	return 0;
}

// Saves data to csv.
void account_repo::add_account_to_db(account acct) {
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
	fout << acct.get_customer().get_first_name() << "," << acct.get_customer().get_last_name() << ",";
	fout << acct.get_customer().get_email() << "," << acct.get_customer().get_address() << ",";   //send to file
	fout << acct.get_customer().get_contact_number() << std::endl;
	fout.close();       //close file
}