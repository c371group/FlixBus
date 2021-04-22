#include "interfaceView.h"
//OUR ABSTRACT CLASS
interfaceView::interfaceView()
{
	this->intcon = interfaceControl();
}

interfaceControl interfaceView::get_intcon()
{
	return this->intcon;
}

void interfaceView::set_vecMen(std::vector<std::vector<std::string>> vecMen)
{
	this->vecMen = vecMen;
}

void interfaceView::set_vecStr(std::vector<std::vector<std::string>> vecStr)
{
	this->vecStr = vecStr;
}

std::vector<std::vector<std::string>> interfaceView::getVecMen()
{
	return this->vecMen;
}

std::vector<std::vector<std::string>> interfaceView::get_strs()
{ //returns the vector of different vectors/sets of strings
	return this->vecStr;
}

void interfaceView::set_intcon(interfaceControl intcon)
{
	this->intcon = intcon;
}

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

std::vector<std::vector<std::string>> interfaceView::get_menu_items()
{ //returns the vector of different vectors/menus
	return this->vecMen;
}

std::vector<std::string> interfaceView::prompt_strs(int i)
//i refers to the index of a set of prompts/strings in vecStr
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

bool interfaceView::confirm_Menu_Choice(int i, int j)
{
	std::string user_input_string;
	std::cout << "You chose " << get_menu_items()[i][j] << "." << std::endl;
	std::cout << "Is this correct? (Enter \"Y\" or \"Yes\" to confirm, enter anything else to cancel): ";
	getline(std::cin, user_input_string);
	return get_intcon().affirm(user_input_string);
}

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