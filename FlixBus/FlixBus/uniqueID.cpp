#include "uniqueID.h" //TODO: watch this, i'm dumb

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

int UniqueID::nextID = 0;

UniqueID::UniqueID() {
	id = ++nextID;
}

std::string UniqueID::toString()
{
	std::string str = std::to_string(id);
	return str;
}
UniqueID::UniqueID(const UniqueID& orig) {
	id = orig.id;
}

UniqueID& UniqueID::operator=(const UniqueID& orig) {
	id = orig.id;
	return(*this);
}