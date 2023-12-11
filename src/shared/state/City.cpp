#include "City.h"

using namespace std;
using namespace state;


City::City(int position, std::string name, int valuePurchase, int *rent, Color color) : Property(position, name, valuePurchase),
                                                                                        nbApart(0), hostel(0), color(color), monopoly(false){
    for(int i = 0; i < 6; i++){
        this->rent[i] = rent[i];
    }

}
