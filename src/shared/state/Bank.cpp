#include "Bank.h"


using namespace std;

#include <vector>
#include <iostream>
#include <fstream>

#include <map>
#include <sstream>
#include "config.h"
#include <string>




using namespace state;


string readFileIntoString(const string &path) {

    auto ss = ostringstream{};
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '" << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    return ss.str();
}

Bank::Bank() : nbApart(32), nbHostel(12) {

    string path = RES_DIR;
    string filename(path + "Properties/bank.csv");
    string file_contents;

    char delimiter = ',';

    file_contents = readFileIntoString(filename);

    istringstream sstream(file_contents);
    string name;
    string record;
    Color color;
    map<std::string, Color> colormap{{"PINK",       PINK},
                                     {"LIGHT_BLUE", LIGHT_BLUE},
                                     {"PURPLE",     PURPLE},
                                     {"ORANGE",     ORANGE},
                                     {"RED",        RED},
                                     {"YELLOW",     YELLOW},
                                     {"GREEN",      GREEN},
                                     {"DARK_BLUE",  DARK_BLUE}};

    int pos;
    long long rent[6];
    long long apparthostel;
    for (int i = 0; i < 22; i++) {
        istringstream line(record);
        getline(line, record, delimiter);
        pos = stoi(record);
        getline(line, record, delimiter);
        name = record;
        for (int j = 0; j < 6; ++j) {
            getline(line, record, delimiter);
            rent[j] = stoll(record);
        }

        getline(line, record, delimiter);
        color=colormap[record];
        getline(line, record, delimiter);

        /*
        iscard = (strcasecmp("true", record.c_str()) == 0);
        getline(line, record, delimiter);
        money = (strcasecmp("true", record.c_str()) == 0);
        getline(line, record, delimiter);
        chance = (strcasecmp("true", record.c_str()) == 0);
        getline(line, record, delimiter);
        gojail = (strcasecmp("true", record.c_str()) == 0);
         */
        City(pos, name, 600000, new long long[6]{20000, 100000, 300000, 900000, 1600000, 2500000}, PINK,
             500000);

    }
    /*
    City* lens = new City(2, "LENS", 600000, new long long[6]{20000, 100000, 300000, 900000, 1600000, 2500000}, PINK, 500000);
    City* bordeaux = new City(4, "BORDEAUX", 600000, new long long[6]{40000, 200000, 600000, 1800000, 3200000, 4500000}, PINK, 500000);
    City* strasbourg = new City(7,"STRASBOURG", 1000000, new long long[6]{60000, 300000, 900000, 2700000, 4000000, 5500000}, LIGHT_BLUE, 500000);
    City* saint_etienne = new City(9, "SAINT-ETIENNE", 1000000, new long long[6]{60000, 300000, 900000, 2700000, 4000000, 5500000}, LIGHT_BLUE, 500000);
    City* nantes = new City(10, "NANTES", 1200000, new long long[6]{80000, 400000, 1000000, 3000000, 4500000, 6000000}, LIGHT_BLUE, 500000);
    City* noumea = new City(12, "NOUMEA", 1400000, new long long[6]{100000, 500000, 1500000, 4500000, 6250000, 7500000}, PURPLE, 1000000);
    City* lyon = new City(14, "LYON", 1400000, new long long[6]{100000, 500000, 1500000, 4500000, 6250000, 7500000}, PURPLE, 1000000);
    City* rouen = new City(15, "ROUEN", 1600000, new long long[6]{120000, 600000, 1800000, 5000000, 7000000, 9000000}, PURPLE, 1000000);
    City* toulouse = new City(17, "TOULOUSE", 1800000, new long long[6]{140000, 700000, 2000000, 5500000, 7500000, 9500000}, ORANGE, 1000000);
    City* besancon = new City(19, "BESANCON", 1800000, new long long[6]{140000, 700000, 2000000, 5500000, 7500000, 9500000}, ORANGE, 1000000);
    City* dijon = new City(20, "DIJON", 2000000, new long long[6]{160000, 800000, 2200000, 6000000, 8000000, 10000000}, ORANGE, 1000000);
    City* montpellier = new City(22, "MONTPELLIER", 2200000, new long long[6]{180000, 900000, 2500000, 7000000, 8750000, 10500000}, RED, 1500000);
    City* lille = new City(24, "LILLE", 2200000, new long long[6]{180000, 900000, 2500000, 7000000, 8750000, 10500000}, RED, 1500000);
    City* metz = new City(25,"METZ", 2400000, new long long[6]{200000, 1000000, 3000000, 7500000, 9250000, 11000000}, RED, 1500000);
    City* nimes = new City(27, "NIMES", 2600000, new long long[6]{220000, 1100000, 3300000, 8000000, 9750000, 11500000}, YELLOW, 1500000);
    City* nancy = new City(28, "NANCY", 2600000, new long long[6]{220000, 1100000, 3300000, 8000000, 9750000, 11500000}, YELLOW, 1500000);
    City* clermont_ferrand = new City(30, "CLERMONT-FERRAND", 2800000, new long long[6]{240000, 1200000, 3600000, 8500000, 10500000, 12000000}, YELLOW, 1500000);
    City* annecy = new City(32, "ANNECY", 3000000, new long long[6]{260000, 1300000, 3900000, 9000000, 11000000, 12750000}, GREEN, 2000000);
    City* caen = new City(33, "CAEN", 3000000, new long long[6]{260000, 1300000, 3900000, 9000000, 11000000, 12750000}, GREEN, 2000000);
    City* perpignan = new City(35, "PERPIGNAN", 3200000, new long long[6]{280000, 1500000, 4500000, 10000000, 12000000, 14000000}, GREEN, 2000000);
    City* reims = new City(38, "REIMS", 3500000, new long long[6]{350000, 1750000, 5000000, 11000000, 13000000, 15000000}, DARK_BLUE, 2000000);
    City* dunkerque = new City(40, "DUNKERQUE", 4000000, new long long[6]{500000, 2000000, 6000000, 14000000, 17000000, 20000000}, DARK_BLUE, 2000000);

    Station* stationLille = new Station(6, "STATION_LILLE", 2000000, new long long[4]{250000, 500000, 1000000, 2000000});
    Station* stationMarseille = new Station(16, "STATION_MARSEILLE", 2000000,new long long[4]{250000, 500000, 1000000, 2000000});
    Station* stationParis = new Station(26, "STATION_PARIS", 2000000, new long long[4]{250000, 500000, 1000000, 2000000});
    Station* stationLyon = new Station(36, "STATION_LYON", 2000000,new long long[4]{250000, 500000, 1000000, 2000000});

    Service* telecoms = new Service(13, "TELECOMS", 1500000);
    Service* satellite = new Service(29, "SATELLITE", 1500000);

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
*/
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

void Bank::eraseFromBankProperties(std::vector<Property>::iterator it) {
    this->bankProperties.erase(it);
}

int Bank::getNbApartBank() {
    return this->nbApart;
}

int Bank::getNbHostelBank() {
    return this->nbHostel;
}

void Bank::setNbApartBank(int NbApartBank) {
    this->nbApart = NbApartBank;
}

void Bank::setNbHostelBank(int NbHostelBank) {
    this->nbHostel = NbHostelBank;
}




