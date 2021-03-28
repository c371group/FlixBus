#include "registration.h"
#include "interfaceControl.h"

#include <iostream>

registration::registration()
{
	iC = interfaceControl();
	set_username(NULL);
	set_password(NULL);
}
registration::registration(bool pretend)
{
	set_ic(iC);
	set_username_extended();
	set_password_extended();
	std::cout << "Account created! You can now sign in!" << std::endl;
}

void registration::set_ic(interfaceControl intC)
{
	iC = intC;
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
	while (!iC.validateRegUser(user_input_string)) {
		if (user_input_string == "HELP" || user_input_string == "\"HELP\"") {
			std::cout << "USERNAME REQUIREMENTS:\n- Length between 6 and 20 characters \n- Spaces are not allowed\n- Usernames are case sensitive" << std::endl;
		}
		else {
			std::cout << "ERROR-- Username not valid." << std::endl; // maybe do something cool with reference errors later on so the reasons are listed below the error message
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
	while (!iC.validateRegUser(user_input_string)) {
		if (user_input_string == "HELP" || user_input_string == "\"HELP\"") {
			std::cout << "PASSWORD REQUIREMENTS:\n- At least 8 characters \n- A mixture of upper and lowercase letters\n- A mixture of numbers and letters\n- Usernames are case sensitive" << std::endl;
		}
		else {
			std::cout << "ERROR-- Password not valid." << std::endl; // maybe do something cool with reference errors later on so the reasons are listed below the error message
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

std::string registration::get_i_c() const
{
	return std::string();
}

std::string registration::get_username() const
{
	return username_;
}

std::string registration::get_password() const
{
	return password_;
}