#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include "accountRepo.h"



/**
 * \brief  interfaceControl used for controlling the input.
 */
class interfaceControl
{
public:
	// Base constructor.
	interfaceControl() = default;
	// Validates input.
	bool validateInt(std::string input, int min_num, int max_num);
	// Validate username that user signs up with
	bool validateRegUser(std::string); 
	// Checks if the password did not violated the rules.
	bool validate_reg_pass(std::string input);
	// Checks if there is space
	bool hasSpace(std::string input);
	// Checks for length
	bool violatesLength(std::string input, int min_num);
	// Checks for length
	bool violatesLength(std::string input, int min_num, int max_num);
	// Checks if there is a mixture of numerical and alpha numerical characters.
	bool notMixtureNumAlpha(std::string);
	//Iterates over the input string, checking to see if the current character is an upper or lowercase letter.
	bool notMixtureUpperLower(std::string input);
	// Converts upper to lower case.
	std::string lower_string(std::string str);
	// Asks the user to choose yes or no.
	bool affirm(std::string input);
	// Checks if the user exists.
	bool checkUsernameExistence(accountRepo* acctRep, std::string, int&);
	// Checks if the password is correct.
	bool checkPassword(accountRepo* acctRep, std::string, int);
};