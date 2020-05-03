//
// Created by student on 02.05.2020.
//

#include "model/ClientType.h"
ClientType::ClientType() {}
ClientType::~ClientType() {}
int Default::getMaxVehicles() const {
    return 1;
}

unsigned int Default::applyDiscount(int price) {
    return price;
}


int Bronze::getMaxVehicles() const {
    return 2;
}

unsigned int Bronze::applyDiscount(int price) {
    return price-3;
}

int Silver::getMaxVehicles() const {
    return 3;
}

unsigned int Silver::applyDiscount(int price) {
    return price-6;
}

int Gold::getMaxVehicles() const {
    return 4;
}

unsigned int Gold::applyDiscount(int price) {
    return price-(0.05*price);
}

int Platinum::getMaxVehicles() const {
    return 5;
}

unsigned int Platinum::applyDiscount(int price) {
    return price-(0.1*price);
}

int Diamond::getMaxVehicles() const {
    return 10;
}

unsigned int Diamond::applyDiscount(int price) {
    if (price<125)
        return price-(0.1*price);
    else if (price>=125 and price<250)
        return price-(0.2*price);
    else if (price>=250 and price <500)
        return price-(0.3*price);
    else
        return price-(0.4*price);
}
