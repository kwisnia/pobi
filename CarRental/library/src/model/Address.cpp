//
// Created by student on 08.04.2020.
//

#include "model/Address.h"
#include <sstream>
using namespace std;
Address::~Address() {}

Address::Address(const string &city, const string &street, const string &number) : city(city),
                                                                                                  street(street),
                                                                                                  number(number) {}

const string &Address::getCity() const {
    return city;
}

void Address::setCity(const string &city) {
    Address::city = city;
}

const string &Address::getStreet() const {
    return street;
}

void Address::setStreet(const string &street) {
    Address::street = street;
}

const string &Address::getNumber() const {
    return number;
}

void Address::setNumber(const string &number) {
    Address::number = number;
}

string Address::getAddressInfo() {
    ostringstream out;
    out << city<<" "<<street<<" "<<number;
    return out.str();
}
