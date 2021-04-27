#include "registration.h"

registration::registration(accountRepo& acctRepo)
{
	std::vector<std::string> promptSet1 = {
"Enter first name", "Enter last name", "Enter email", "Enter address", "Enter contact number"
	};
	std::vector<std::vector<std::string>> temp = {promptSet1};
	set_vecStr(temp);
	system("CLS");
	acctData();
	humanData();
	finalCreation(acctRepo);
}

void registration::humanData()
{
	responses_ = prompt_strs(0);
	const auto confirm = confirm_Prompt_Choices(0, responses_);
	if (!confirm)
	{
		humanData();
	}
	else
	{
		populate();
	}
}

void registration::populate()
{
	set_first_name(responses_[0]);
	set_last_name(responses_[1]);
	set_email(responses_[2]);
	set_address(responses_[3]);
	set_contact_number(responses_[4]);
}


void registration::set_username(std::string username)
{
	username_ = username;
}

void registration::set_username_extended()
{
	std::string user_input_string;
	std::cout << "Enter desired username (Enter \"HELP\" for requirements): ";
	getline(std::cin, user_input_string);
	//TODO: Add handler for looking at list of usernames already registered in permanent file storage
	while (!get_intcon().validateRegUser(user_input_string))
	{
		if (get_intcon().lower_string(user_input_string) == "help" || get_intcon().lower_string(user_input_string) == "\"help\"")
		{
			std::cout <<
				"USERNAME REQUIREMENTS:\n- Length between 6 and 20 characters \n- Spaces are not allowed\n- Usernames are case sensitive"
				<< std::endl;
		}
		else
		{
			std::cout << "ERROR-- Username not valid." << std::endl;
			// maybe do something cool with reference errors later on so the reasons are listed below the error message
		}
		std::cout << "Enter desired username (Enter \"HELP\" for requirements): ";
		getline(std::cin, user_input_string);
	}
	set_username(user_input_string);
}

void registration::set_password(std::string password)
{
	password_ = password;
}

void registration::set_password_extended()
{
	std::string user_input_string;
	std::cout << "Enter desired password (Enter \"HELP\" for requirements): ";
	getline(std::cin, user_input_string);
	while (!get_intcon().validate_reg_pass(user_input_string))
	{
		if (get_intcon().lower_string(user_input_string) == "help" || get_intcon().lower_string(user_input_string) == "\"help\"")
		{
			std::cout <<
				"PASSWORD REQUIREMENTS:\n- At least 8 characters \n- A mixture of upper and lowercase letters\n- A mixture of numbers and letters\n- Passwords are case sensitive"
				<< std::endl;
		}
		else
		{
			std::cout << "ERROR-- Password not valid." << std::endl;
			// maybe do something cool with reference errors later on so the reasons are listed below the error message
		}
		std::cout << "Enter desired password (Enter \"HELP\" for requirements): ";
		getline(std::cin, user_input_string);
	}
	set_password(user_input_string);
}

void registration::set_user_id(std::string val)
{
	user_id_ = val;
}

void registration::set_first_name(std::string f_nam) { f_name_ = f_nam; }

void registration::set_last_name(std::string val)
{
	l_name_ = val;
}

void registration::set_address(std::string val)
{
	address_ = val;
}

void registration::set_email(std::string val)
{
	email_ = val;
}

void registration::set_contact_number(std::string val)
{
	contact_number_ = val;
}

void registration::set_final_customer(Customer cust)
{
	finalCustomer = cust;
}

void registration::set_final_account(Account acct)
{
	finalAccount = acct;
}

std::string registration::get_first_name() const { return f_name_; }

std::string registration::get_last_name() const
{
	return l_name_;
}

std::string registration::get_address() const
{
	return address_;
}

std::string registration::get_email() const
{
	return email_;
}

std::string registration::get_contact_number() const
{
	return contact_number_;
}

std::string registration::get_username() const
{
	return username_;
}

std::string registration::get_password() const
{
	return password_;
}

void registration::createCustomer()
{
	const Customer customer(responses_[0], responses_[1],responses_[2],responses_[3],responses_[4]);
	set_final_customer(customer);
}

void registration::createAcct()
{
	const Account acnt(finalCustomer, get_username(), get_password());
	set_final_account(acnt);
}

void registration::addToRepo(accountRepo& acctRep)
{
	acctRep.add_acct(finalAccount);
	acctRep.add_account_to_db(finalAccount);
}

void registration::finalCreation(accountRepo& acctRep)
{
	createCustomer();
	createAcct();
	addToRepo(acctRep);
	std::cout << "Account created! You can now sign in!" << std::endl;
}

void registration::acctData()
{
	set_username_extended();
	set_password_extended();
}