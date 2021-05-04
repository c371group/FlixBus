#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "interfaceControl.h"


/**
 * \brief interfaceView is the base class for all views. It contains important attributes and methods needed for the control of the menu.
 */
class interfaceView
{
private:
	// Interface control
	interfaceControl intcon;
	// Vector of vectors of strings, contains main menu
	std::vector<std::vector<std::string>> vecMen;
	// Vector of vectors of strings, contains menu options
	std::vector<std::vector<std::string>> vecStr;
public:
	// Base constructor.
	interfaceView();
	// Takes interfaceControl and assigns it.
	void set_intcon(interfaceControl);
	// Returns intcon attribute.
	interfaceControl get_intcon();
	// Takes vector<std::vector<std::string>> and assigns it to an attribute.
	void set_vecMen(std::vector<std::vector<std::string>>);
	// Takes vector<std::vector<std::string>> and assigns it to an attribute.
	void set_vecStr(std::vector<std::vector<std::string>>);
	// Returns vecMen attribute.
	std::vector<std::vector<std::string>> getVecMen();
	// Returns vecStr attributes.
	std::vector<std::vector<std::string>> getVecStr();
	// Displaying menu items.
	int display_menu_items(int i);
	// Returns vecMen attribute.
	std::vector<std::vector<std::string>> get_menu_items();
	// Returns vecStr attribute.
	std::vector<std::vector<std::string>> get_strs();
	// Iterates over the vector of strings and takes the persons response, adding it to the promptAns vector.
	std::vector<std::string> prompt_strs(int i);
	// Adds menu items.
	void set_menu_items(std::vector<std::vector<std::string>> full_menus);
	// Adding menu.
	void add_menu(std::vector<std::string> menu);
	// Removes menu.
	void remove_menu(int menu);
	// Adding choices.
	void add_choice(int i, int j, std::string choice);
	// Entering a choice.
	int enterChoice(int max);
	// Confirming menu choice.
	bool confirm_Menu_Choice(int i, int j);
	// Asking the user to confirm their choice.
	bool confirm_Prompt_Choices(int i, std::vector<std::string> choices);
};