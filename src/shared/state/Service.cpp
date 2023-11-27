#include "Service.h"

using namespace std;
using namespace state;


Service::Service(int position, std::string name, int valuePurchase) : Property(position, name, valuePurchase),
                 nbServicePossessed(0){ }
