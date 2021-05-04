#include "fullTripListView.h"

// Base constructor.
fullTripListView::fullTripListView() = default;

fullTripListView::fullTripListView(bool voided) //it could be that I'm tired but this is a workaround to a weird problem that loggedInInterface presents where it doesn't like me declaring a new fullTripListView object in the switch case statement
{
	system("CLS");
	read_full_list();
	system("PAUSE");
}
int fullTripListView::read_full_list() //ideally later we could pass a vector here of columns we don't want displayed
{
	//this is just plaintext for now
	std::ifstream input_from_file("Trips502508.csv");
	std::string line;
	int lineno = 0; //line number
	int linecount = 0; //just putting this here for now, ideally used when we have a search term and we want to count how many times that search term occurs.
	while (getline(input_from_file, line)) {
		lineno++;
		line += ",";

		std::stringstream ss(line);
		std::string word;
		std::vector<std::string> words;

		int fNum = 15; //constant number for formatting

		while (getline(ss, word, ','))
			words.push_back(word);
		linecount++;
		if (linecount != 1)
		{
			std::cout << std::left << std::setw(fNum) << words[1] << std::setw(fNum) << words[2] << std::setw(fNum) << words[5] << std::setw(fNum) << words[6] << std::setw(fNum) << words[7] << std::setw(fNum) << words[8] << std::endl;
		}
		else
		{
			std::cout << std::endl;
			std::cout << std::left << std::setw(fNum) << "DATE" << std::setw(fNum) << "BUS TYPE" << std::setw(fNum) << "DEPARTING FROM" << std::setw(fNum) << "DESTINATION" << std::setw(fNum) << "DEPARTURE" << std::setw(fNum) << "ARRIVAL" << std::endl;
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}