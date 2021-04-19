#include "login.h"

login::login(accountRepo& acctRepo)
{
	int index = 0;
	this->acctRep = acctRepo;
	enter_username(index);
	enter_password(index);
	loggedInInterface lif = loggedInInterface(acctRep.getAccts()[index]); //TODO: probably have to modify this down the line
}

void login::enter_username(int ind)
{
	std::string user_input_string;
	std::cout << "Enter username: ";
	getline(std::cin, user_input_string);
	//TODO: Add handler for looking at list of usernames already registered in permanent file storage
	while (!get_intcon().checkUsernameExistence(acctRep, user_input_string,ind))
	{
		std::cout << "ERROR-- Username does not exist." << std::endl;
		enter_username(ind);
	}
	set_Alleged_Username(user_input_string);
}

void login::enter_password(int ind)
{
	int inde = ind;
	std::string user_input_string;
	std::cout << "Enter password: ";
	getline(std::cin, user_input_string);
	//TODO: Add handler for looking at list of passwords already registered in permanent file storage
	while (!get_intcon().checkPassword(acctRep, user_input_string, inde))
	{
		std::cout << "ERROR-- Password for this account is incorrect." << std::endl;
		std::cout << "Enter password: ";
		getline(std::cin, user_input_string);
	}
	set_Alleged_Password(user_input_string);
}

void login::set_Alleged_Username(std::string alleged_username)
{
	this->allegedUsername = alleged_username;
}

void login::set_Alleged_Password(std::string alleged_password)
{
	this->allegedPassword = alleged_password;
}

std::string login::getAllegedUsername()
{
	return allegedUsername;
}

std::string login::getAllegedPassword()
{
	return allegedPassword;
}
