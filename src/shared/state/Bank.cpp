#include "Bank.h"

using namespace std;
#include <vector>
namespace state{


    std::vector<Property> Bank::getBankProperties() {
        return this->bankProperties;
    }

    void Bank::addToBankProperties(Property property) {
        this->bankProperties.push_back(property);
    }

    void Bank::eraseFromBankProperties( std::vector<Property>::iterator it) {
        this->bankProperties.erase(it);
    }
}