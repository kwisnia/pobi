//
// Created by student on 08.04.2020.
//

#include "model/Address.h"
Address::~Address() {}

Address::Address(const std::string &city, const std::string &street, const std::string &number) : city(city),
                                                                                                  street(street),
                                                                                                  number(number) {}

const std::string &Address::getCity() const {
    return city;
}

void Address::setCity(const std::string &city) {
    Address::city = city;
}

const std::string &Address::getStreet() const {
    return street;
}

void Address::setStreet(const std::string &street) {
    Address::street = street;
}

const std::string &Address::getNumber() const {
    return number;
}

void Address::setNumber(const std::string &number) {
    Address::number = number;
}

std::string Address::GetAddressInfo() {
    return city+" "+street+" "+number;
}
