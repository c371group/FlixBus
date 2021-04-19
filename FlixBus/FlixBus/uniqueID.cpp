#include "uniqueID.h"

class UniqueID {
protected:
	static int nextID;
public:
	int id;
	UniqueID();
	UniqueID(const UniqueID& orig);
	UniqueID& operator=(const UniqueID& orig);
};

int UniqueID::nextID = 0;

UniqueID::UniqueID() {
	id = ++nextID;
}

UniqueID::UniqueID(const UniqueID& orig) {
	id = orig.id;
}

UniqueID& UniqueID::operator=(const UniqueID& orig) {
	id = orig.id;
	return(*this);
}