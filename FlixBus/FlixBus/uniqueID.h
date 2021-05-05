#pragma once
#include <iostream>
#include <string>


/**
 * \brief uniqueID
 */
class UniqueID {
protected:
	static int nextID;
public:
	int id;
	UniqueID();
	std::string toString();
	UniqueID(const UniqueID& orig);
	UniqueID& operator=(const UniqueID& orig);
};
