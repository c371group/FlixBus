#pragma once
#include <string>
#include <vector>

#include "interfaceControl.h"

class interfaceView
{
private:
	std::vector<std::vector<std::string>> vecMen;
	std::vector<std::vector<std::string>> vecStr;
public:
	interfaceView();
	int display_menu_items(int i);
	std::vector<std::vector<std::string>> get_menu_items();
	std::vector<std::vector<std::string>> get_strs();
	std::vector<std::string> prompt_strs(int i);
	void set_menu_items(std::vector<std::vector<std::string>> full_menus);
	void add_menu(std::vector<std::string> menu);
	void remove_menu(int menu);
	void add_choice(int i, int j, std::string choice);
	int enterChoice(int max, interfaceControl int_con);
	bool confirm_Choice(int i, int j, interfaceControl int_con);
};
