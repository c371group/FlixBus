#pragma once
#include <string>
#include <vector>

class interfaceControl {
public: 
	interfaceControl(){}
	//bool validateInt(std::string input);
	bool validateInt(std::string input, int min_num, int max_num);
	bool validateRegUser(std::string); //validate username that user signs up with
	bool validate_reg_pass(std::string input);
	bool hasSpace(std::string input);
	bool violatesLength(std::string input, int min_num);
	bool violatesLength(std::string input, int min_num, int max_num);
	bool notMixtureNumAlpha(std::string);
	bool notMixtureUpperLower(std::string input);
};