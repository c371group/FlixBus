#include "interfaceView.h"


// Interface control
interfaceView::interfaceView()
{
	this->intcon = interfaceControl();
}

// Returns intcon attribute.
interfaceControl interfaceView::get_intcon()
{
	return this->intcon;
}

// Takes vector<std::vector<std::string>> and assigns it to an attribute.
void interfaceView::set_vecMen(std::vector<std::vector<std::string>> vecMen)
{
	this->vecMen = vecMen;
}

// Takes vector<std::vector<std::string>> and assigns it to an attribute.
void interfaceView::set_vecStr(std::vector<std::vector<std::string>> vecStr)
{
	this->vecStr = vecStr;
}

// Returns vecMen attribute.
std::vector<std::vector<std::string>> interfaceView::getVecMen()
{
	return this->vecMen;
}

// Returns vecStr attributes.
std::vector<std::vector<std::string>> interfaceView::get_strs()
{ //returns the vector of different vectors/sets of strings
	return this->vecStr;
}

// Takes interfaceControl and assigns it.
void interfaceView::set_intcon(interfaceControl intcon)
{
	this->intcon = intcon;
}

// Displaying menu items.
int interfaceView::display_menu_items(int i)
{
	int k = 0;
	for (int j = 0; j < get_menu_items()[i].size(); j++)
	{
		std::cout << j + 1 << ". " << get_menu_items()[i][j] << "\n";
		k++;
	}
	std::cout << "\n\n" << std::endl;
	return k;
}

// Returns the vector of different vectors/menus
std::vector<std::vector<std::string>> interfaceView::get_menu_items()
{ 
	return this->vecMen;
}

// Int i refers to the index of a set of prompts/strings in vecStr
std::vector<std::string> interfaceView::prompt_strs(int i)

{
	//keeps a set of answers to the prompts
	std::vector<std::string> promptAns;
	//the persons answer to any given prompt
	std::string temp;
	/*iterates over the vector of strings and takes the persons response, adding it to
	the promptAns vector*/
	for (int j = 0; j < get_strs()[i].size(); j++)
	{
		std::cout << get_strs()[i][j] << ": ";
		getline(std::cin, temp);
		promptAns.push_back(temp);
	}
	//TODO: make sure user can't enter blank values
	return promptAns;
}

// Adds menu items.
void interfaceView::set_menu_items(std::vector<std::vector<std::string>> full_menus)
{
	vecMen = full_menus;
}

void interfaceView::add_menu(std::vector<std::string> menu)
{
}

void interfaceView::remove_menu(int menu)
{
}

void interfaceView::add_choice(int i, int j, std::string choice)
{
}

// Entering a choice.
int interfaceView::enterChoice(int max)
{
	std::string user_input_string;
	std::cout << "Enter desired choice: ";
	getline(std::cin, user_input_string);

	while (!get_intcon().validateInt(user_input_string, 1, max))
	{
		std::cout << "ERROR-- A valid choice must be entered: ";
		getline(std::cin, user_input_string);
	}
	const auto choice_int = stoi(user_input_string);
	return choice_int;
}

// Confirming menu choice.
bool interfaceView::confirm_Menu_Choice(int i, int j)
{
	std::string user_input_string;
	std::cout << "You chose " << get_menu_items()[i][j] << "." << std::endl;
	std::cout << "Is this correct? (Enter \"Y\" or \"Yes\" to confirm, enter anything else to cancel): ";
	getline(std::cin, user_input_string);
	return get_intcon().affirm(user_input_string);
}

// Asking the user to confirm thier choice.
bool interfaceView::confirm_Prompt_Choices(int i, std::vector<std::string> choices)
{
	std::string user_input_string;
	std::cout << "You chose: \n\n" << std::endl;
	for (int j = 0; j < choices.size(); j++)
	{
		std::cout << get_strs()[i][j] << ": " << choices[j] << std::endl;
	}
	std::cout << "\n\nIs this information correct? (Enter \"Y\" or \"Yes\" to confirm, enter anything else to cancel): ";
	getline(std::cin, user_input_string);
	return get_intcon().affirm(user_input_string);
}