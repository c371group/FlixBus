#include "interfaceControl.h"


/* Description: the validInt function (overloaded) takes string input (returning false if empty) and attempts to convert to an integer, returning false if not. After successful conversion, the integer version of the string (intInput) is checked to make sure it does not exceed max_num and that min_num is not greater than intInput. If either of these two conditions are violated, return false. Otherwise, return true.
Pre: min_num cannot be greater than max_num.
Post: Returns true if string satisfies conditions established by min_num and/or max_num. */
bool interfaceControl::validateInt(std::string input, int min_num, int max_num)
{
	int int_input;

	if (input.length() == 0)
	{
		return false;
	}
	else
	{
		try
		{
			int_input = stoi(input);
		}
		catch (std::exception a)
		{
			return false;
		}

		if (int_input < min_num || int_input > max_num)
		{
			return false;
		}
	}
	return true;
}

// Validate username that user signs up with
bool interfaceControl::validateRegUser(std::string input)
{
	if (hasSpace(input) || violatesLength(input, 6, 20))
	{
		return false;
	}
	return true;
}

// Checks if the password did not violated the rules.
bool interfaceControl::validate_reg_pass(std::string input)
{
	if (violatesLength(input, 8) || notMixtureNumAlpha(input) || notMixtureUpperLower(input))
	{
		return false;
	}
	return true;
}

// Checks if there is space
bool interfaceControl::hasSpace(std::string input)
{
	for (int character = 0; character < input.length(); character++)
	{
		if (std::isspace(input[character]))
		{
			std::cout << "Cannot have spaces." << std::endl;
			return true;
		}
	}
	return false;
}

// Checks for length
bool interfaceControl::violatesLength(std::string input, int min_num)
{
	//if the length is less than the minimum number of characters, return true because it violates the length
	if (input.length() < min_num)
	{
		std::cout << "Must be at least " << min_num << " characters." << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

// Checks for length
bool interfaceControl::violatesLength(std::string input, int min_num, int max_num)
{
	if (input.length() > max_num || input.length() < min_num)
	{
		std::cout << "Must be between " << min_num << " and " << max_num << " characters." << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

// Checks if there is a mixture of numerical and alpha numerical characters.
bool interfaceControl::notMixtureNumAlpha(std::string input)
{
	bool letterFound = false;
	bool numberFound = false;
	for (int character = 0; character < input.length(); character++)
	{
		if (std::isalpha(input[character]))
		{
			letterFound = true;
		}
		else if (std::isdigit(input[character]))
		{
			numberFound = true;
		}
	}

	if (letterFound && numberFound)
	{
		return false;
	}

	std::cout << "Must be mixture of numbers and letters." << std::endl;
	return true;
}

/*Iterates over the input string, checking to see if the current character is an upper or lowercase
letter. If so, set respective condition to true. Once the iteration is complete, check if
lowerFound and upperFound are both true. If so, return false because the string IS a mixture of
upper and lowercase letters. Else, return true.*/
bool interfaceControl::notMixtureUpperLower(std::string input)
{
	bool lowerFound = false;
	bool upperFound = false;
	for (int character = 0; character < input.length(); character++)
	{
		if (std::isalpha(input[character]))
		{
			if (std::islower(input[character]))
			{
				lowerFound = true;
			}
			else if (std::isupper(input[character]))
			{
				upperFound = true;
			}
		}
	}

	if (lowerFound && upperFound)
	{
		return false;
	}
	std::cout << "Must be mixture of uppercase and lowercase letters." << std::endl;
	return true;
}

// Converts upper to lower case.
std::string interfaceControl::lower_string(std::string str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z') //checking for uppercase characters
			str[i] = str[i] + 32; //converting uppercase to lowercase
	}
	return str;
}

// Asks the user to choose yes or no.
bool interfaceControl::affirm(std::string input)
{
	std::string inputManip = lower_string(input);
	if (inputManip == "yes" || inputManip == "y")
	{
		return true;
	}
	return false;
}

/*Takes the account repo and iterates over the accounts in there, checking usernames for a match for
 * the string the user entered. if the match is found at a certain index, change the index parameter
 * to that index (passed by reference) and return true because a match WAS found. if not,
 * return false
 */
bool interfaceControl::checkUsernameExistence(accountRepo* acctRep, std::string claimedUsername, int& index){
	for (int i = 0; i < acctRep->getAccts().size(); i++) {
		if (acctRep->getAccts()[i].get_username() == claimedUsername)
		{
			index = i;
			//DEBUGGING
			//std::cout << "FOUND YA" << std::endl;
			return true;
		}
	}
	return false;
}

// Checks if the password is correct.
bool interfaceControl::checkPassword(accountRepo* acctRep, std::string claimedPassword, int index)
{
	if (acctRep->getAccts()[index].get_password() == claimedPassword)
	{
		return true;
	}
	return false;
}
