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

long long Property::getRent() {
    return 0;
}

void Property::modifyNbPossessed(Player player) {

}

Color Property::getColor() {
    return RED;
}

long long Property::getValuePurchase() {
    return this->valuePurchase;
}

void Property::resetPossessions() {

}
