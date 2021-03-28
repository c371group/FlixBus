#pragma once
#include <string>
#include "interfaceControl.h"
class registration //this might seem redundant, but we want to ensure we're not creating account objects with empty parameters
{
private:
	interfaceControl iC;
	std::string username_, password_;
	std::string user_id_, f_name_, l_name_, address_, email_,contact_number_;
public:
	registration();
	registration(interfaceControl iC);
	void set_ic(interfaceControl iC);
	void set_username(std::string username);
	void set_username_extended();
	void set_password(std::string password);
	void set_password_extended();
	void set_user_id(std::string user_id);
	void set_first_name(std::string f_nam);
	void set_last_name(std::string l_name);
	void set_address(std::string address);
	void set_email(std::string email);
	void set_contact_number(std::string contact_number);

	std::string get_i_c() const;
	std::string get_username() const;
	std::string get_password() const;
	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_address() const;
	std::string get_email() const;
	std::string get_contact_number() const;
};
