#include "uniqueID.h" //TODO: watch this, i'm dumb


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

UniqueID::UniqueID(const int id_)
{
	id = id_;
}

UniqueID& UniqueID::operator=(const UniqueID& orig) {
	id = orig.id;
	return(*this);
}
