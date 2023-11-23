#include "Service.h"

using namespace std;
using namespace state;


Service::Service(int position, bool isProperty, bool isCard, bool money, bool chance, bool goToJail, std::string name,
                 int valuePurchase) : Property(position, isProperty, isCard, money, chance, goToJail, name, valuePurchase),
                 nbServicePossessed(0){ }
