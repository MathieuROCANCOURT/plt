#include "Bank.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include "config.h"
#include <string>


using namespace std;
using namespace state;


string readFileIntoStringBank(const string &path) {
    ostringstream ss;
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
    string filename(path + "CSV/Bank.csv");
    string file_contents;

    char delimiter = ',';

    file_contents = readFileIntoStringBank(filename);

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
    long long purchaseprice;
    long long rent[6];
    long long apparthostel;
    for (int i = 0; i < 22; i++) {
        std::getline(sstream, record);
        istringstream line(record);
        getline(line, record, delimiter);
        pos = stoi(record);
        getline(line, record, delimiter);
        name = record;
        getline(line, record, delimiter);
        purchaseprice = stoll(record);
        for (int j = 0; j < 6; ++j) {
            getline(line, record, delimiter);
            rent[j] = stoll(record);
        }

        getline(line, record, delimiter);
        color = colormap[record];
        getline(line, record, delimiter);
        apparthostel = stoll(record);

        bankProperties.push_back(City(pos, name, purchaseprice, rent, color, apparthostel
        ));
    }
    long long rentStation[4];
    for (int i = 0; i < 4; i++) {
        std::getline(sstream, record);
        istringstream line(record);
        getline(line, record, delimiter);
        pos = stoi(record);
        getline(line, record, delimiter);
        name = record;
        getline(line, record, delimiter);
        purchaseprice = stoll(record);
        for (int j = 0; j < 4; ++j) {
            getline(line, record, delimiter);
            rentStation[j] = stoll(record);
        }
        for (int j = 0; j < 4; ++j) {
            getline(line, record, delimiter);
        }
        bankProperties.push_back(Station(pos, name, purchaseprice, rentStation));
    }
    for (int i = 0; i < 2; i++) {
        std::getline(sstream, record);
        istringstream line(record);
        getline(line, record, delimiter);
        pos = stoi(record);
        getline(line, record, delimiter);
        name = record;
        getline(line, record, delimiter);
        purchaseprice = stoll(record);
        for (int j = 0; j < 8; ++j) {
            getline(line, record, delimiter);
        }


        bankProperties.push_back(Service(pos, name, purchaseprice));
    }
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




