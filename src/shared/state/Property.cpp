#include "Property.h"

using namespace std;
using namespace state;


bool Property::operator==(const Property &other) const{
    return (this->name == other.name) && (this->valuePurchase == other.valuePurchase);
}


Property::Property(int position, bool isProperty, bool isCard, bool money, bool chance, bool goToJail, std::string name, int valuePurchase) :
        Box(position, isProperty, isCard, money, chance, goToJail), name(name), valuePurchase(valuePurchase){}
