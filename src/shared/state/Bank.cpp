#include "Bank.h"
#include "City.h"
#include "Station.h"
#include "Service.h"

using namespace std;
#include <vector>
namespace state{


    Bank::Bank() : nbApart(32), nbHostel(12){

        City* lens = new City(2, true, false, false, false, false, "LENS", 600000, new int[6]{20000, 100000, 300000, 900000, 1600000, 250000}, PINK);
        City* bordeaux = new City(4, true, false, false, false, false, "BORDEAUX", 600000, new int[6]{40000, 200000, 600000, 1800000, 3200000, 4500000}, PINK);
        City* strasbourg = new City(7, true, false, false, false, false, "STRASBOURG", 1000000, new int[6]{60000, 300000, 900000, 2700000, 4000000, 5500000}, LIGHT_BLUE);
        City* saint_etienne = new City(9, true, false, false, false, false, "SAINT-ETIENNE", 1000000, new int[6]{60000, 300000, 900000, 2700000, 4000000, 5500000}, LIGHT_BLUE);
        City* nantes = new City(10, true, false, false, false, false, "NANTES", 1200000, new int[6]{80000, 400000, 1000000, 3000000, 4500000, 6000000}, LIGHT_BLUE);
        City* noumea = new City(12, true, false, false, false, false, "NOUMEA", 1400000, new int[6]{100000, 500000, 1500000, 4500000, 6250000, 7500000}, PURPLE);
        City* lyon = new City(14, true, false, false, false, false, "LYON", 1400000, new int[6]{100000, 500000, 1500000, 4500000, 6250000, 7500000}, PURPLE);
        City* rouen = new City(15, true, false, false, false, false, "ROUEN", 1600000, new int[6]{120000, 600000, 1800000, 5000000, 7000000, 9000000}, PURPLE);
        City* toulouse = new City(17, true, false, false, false, false, "TOULOUSE", 1800000, new int[6]{140000, 700000, 2000000, 5500000, 7500000, 9500000}, ORANGE);
        City* besancon = new City(19, true, false, false, false, false, "BESANCON", 1800000, new int[6]{140000, 700000, 2000000, 5500000, 7500000, 9500000}, ORANGE);
        City* dijon = new City(20, true, false, false, false, false, "TOULOUSE", 2000000, new int[6]{160000, 800000, 2200000, 6000000, 8000000, 10000000}, ORANGE);
        City* montpellier = new City(22, true, false, false, false, false, "MONTPELLIER", 2200000, new int[6]{180000, 900000, 2500000, 7000000, 8750000, 10500000}, RED);
        City* lille = new City(24, true, false, false, false, false, "LILLE", 2200000, new int[6]{180000, 900000, 2500000, 7000000, 8750000, 10500000}, RED);
        City* metz = new City(25, true, false, false, false, false, "METZ", 2400000, new int[6]{200000, 1000000, 3000000, 7500000, 9250000, 11000000}, RED);
        City* nimes = new City(27, true, false, false, false, false, "NIMES", 2600000, new int[6]{220000, 1100000, 3300000, 8000000, 9750000, 11500000}, YELLOW);
        City* nancy = new City(28, true, false, false, false, false, "NANCY", 2600000, new int[6]{220000, 1100000, 3300000, 8000000, 9750000, 11500000}, YELLOW);
        City* clermont_ferrand = new City(30, true, false, false, false, false, "CLERMONT-FERRAND", 2800000, new int[6]{240000, 1200000, 3600000, 8500000, 10500000, 12000000}, YELLOW);
        City* annecy = new City(32, true, false, false, false, false, "ANNECY", 3000000, new int[6]{260000, 1300000, 3900000, 9000000, 11000000, 12750000}, GREEN);
        City* caen = new City(33, true, false, false, false, false, "CAEN", 3000000, new int[6]{260000, 1300000, 3900000, 9000000, 11000000, 12750000}, GREEN);
        City* perpignan = new City(35, true, false, false, false, false, "PERPIGNAN", 3200000, new int[6]{280000, 1500000, 4500000, 10000000, 12000000, 14000000}, GREEN);
        City* reims = new City(38, true, false, false, false, false, "REIMS", 3500000, new int[6]{350000, 1750000, 5000000, 11000000, 13000000, 15000000}, DARK_BLUE);
        City* dunkerque = new City(40, true, false, false, false, false, "DUNKERQUE", 4000000, new int[6]{500000, 2000000, 6000000, 14000000, 17000000, 20000000}, DARK_BLUE);

        Station* stationLille = new Station(6, true, false, false, false, false, "LILLE", 2000000, new int[4]{250000, 500000, 1000000, 2000000});
        Station* stationMarseille = new Station(16, true, false, false, false, false, "MARSEILLE", 2000000, new int[4]{250000, 500000, 1000000, 2000000});
        Station* stationParis = new Station(26, true, false, false, false, false, "PARIS", 2000000, new int[4]{250000, 500000, 1000000, 2000000});
        Station* stationLyon = new Station(36, true, false, false, false, false, "LYON", 2000000, new int[4]{250000, 500000, 1000000, 2000000});

        Service* telecoms = new Service(13, true, false, false, false, false, "TELECOMS", 1500000);
        Service* satellite = new Service(29, true, false, false, false, false, "SATELLITE", 1500000);

        bankProperties.push_back(lens);
        bankProperties.push_back(bordeaux);
        bankProperties.push_back(strasbourg);
        bankProperties.push_back(saint_etienne);
        bankProperties.push_back(nantes);
        bankProperties.push_back(noumea);
        bankProperties.push_back(lyon);
        bankProperties.push_back(rouen);
        bankProperties.push_back(toulouse);
        bankProperties.push_back(besancon);
        bankProperties.push_back(dijon);
        bankProperties.push_back(montpellier);
        bankProperties.push_back(lille);
        bankProperties.push_back(metz);
        bankProperties.push_back(nimes);
        bankProperties.push_back(nancy);
        bankProperties.push_back(clermont_ferrand);
        bankProperties.push_back(annecy);
        bankProperties.push_back(caen);
        bankProperties.push_back(perpignan);
        bankProperties.push_back(reims);
        bankProperties.push_back(dunkerque);

        bankProperties.push_back(stationLille);
        bankProperties.push_back(stationMarseille);
        bankProperties.push_back(stationParis);
        bankProperties.push_back(stationLyon);

        bankProperties.push_back(telecoms);
        bankProperties.push_back(satellite);

        //cout << "les propriete de la banque sont" << endl;
        //for (property i : bankProperties) {
        //  cout << i.name << endl;
        //
    }

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

