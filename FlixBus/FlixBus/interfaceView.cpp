#include "interfaceView.h"

interfaceView::interfaceView()
{
	this->intcon = interfaceControl();
	//TODO: make this cleaner I guess? not sure
}

interfaceControl interfaceView::get_intcon()
{
	return intcon;
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
	return vecMen;
}

std::vector<std::vector<std::string>> interfaceView::getVecStr()
{
	return vecStr;
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

	return k;
}

std::vector<std::vector<std::string>> interfaceView::get_menu_items()
{
	return vecMen;
}

std::vector<std::vector<std::string>> interfaceView::get_strs()
{
	return vecStr;
}

std::vector<std::string> interfaceView::prompt_strs(int i) //i refers to place of a set of prompts in the master list
{
	std::vector<std::string> promptAns;
	std::string temp;
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

int interfaceView::enterChoice(int max, interfaceControl int_con)
{
	std::string user_input_string;
	std::cout << "Enter desired choice: ";
	getline(std::cin, user_input_string);

	while (!int_con.validateInt(user_input_string, 1, max))
	{
		std::cout << "ERROR-- A valid choice must be entered: ";
		getline(std::cin, user_input_string);
	}
	const auto choice_int = stoi(user_input_string);
	return choice_int;
}

bool interfaceView::confirm_Menu_Choice(int i, int j, interfaceControl int_con)
{
	std::string user_input_string;
	std::cout << "You chose " << get_menu_items()[i][j] << "." << std::endl;
	std::cout << "Is this correct? (Enter \"Y\" or \"Yes\" to confirm, enter anything else to cancel): ";
	getline(std::cin, user_input_string);
	return int_con.affirm(user_input_string);
}

bool interfaceView::confirm_Prompt_Choices(int i, interfaceControl int_con, std::vector<std::string> choices)
{
	std::string user_input_string;
	std::cout << "You chose: \n\n" << std::endl;
	for (int j = 0; j < choices.size(); j++)
	{
		std::cout << get_strs()[i][j] << ": " << choices[j] << std::endl;
	}
	std::cout << "\n\nIs this information correct? (Enter \"Y\" or \"Yes\" to confirm, enter anything else to cancel): ";
	getline(std::cin, user_input_string);
	return int_con.affirm(user_input_string);
}