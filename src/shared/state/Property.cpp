#include "Property.h"

using namespace std;
using namespace state;


bool Property::operator==(const Property &other) const{
    return (this->position == other.position);
}


Property::Property(int position, std::string name, long long valuePurchase) : position(position), name(name), valuePurchase(valuePurchase){}

int Property::getPosition() {
    return (this->position);
}
