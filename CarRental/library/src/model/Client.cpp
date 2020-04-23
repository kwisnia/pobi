//
// Created by student on 05.04.2020.
//

#include "../../include/model/Client.h"
#include <iostream>
#include <string>
#include <sstream>
#include "model/Address.h"
#include "model/Rent.h"
class Rent;

std::string Client::getClientInfo() {
    std::ostringstream out;
    out << "Imie i nazwisko klienta: "<<firstName<<" "<<lastName<<std::endl;
    out << "Adres klienta: "<<getAddress()->GetAddressInfo()<<std::endl;
    return out.str();
}
std::string Client::getFullClientInfo() {
    std::ostringstream out;
    out << getClientInfo()<<std::endl;
    out << "Dane o wypozyczeniach: "<<getCurrentRentsInfo()<<std::endl;
    return out.str();
}

Client::Client(const std::string &firstName, const std::string &lastName, const std::string &personalId,
               Address *address)
        : firstName(firstName), lastName(lastName), personalID(personalId), address(address){
    currentRents.clear();
}

Client::~Client()
{
}

const std::string &Client::getFirstName() const {
    return firstName;
}

void Client::setFirstName(const std::string &firstName) {
    if(firstName.length()>0)
    Client::firstName = firstName;
}

const std::string &Client::getLastName() const {
    return lastName;
}

void Client::setLastName(const std::string &lastName) {
    if(lastName.length()>0)
    Client::lastName = lastName;
}

Address *Client::getAddress() const {
    return address;
}

void Client::setAddress(Address *address) {
    if(address!= nullptr)
    Client::address = address;
}

const std::string &Client::getPersonalId() const {
    return personalID;
}

void Client::addRent(Rent * rent) {
    currentRents.push_back(rent);
}

const std::string Client::getCurrentRentsInfo() const {
    std::ostringstream out;

    for (int i=0;i<currentRents.size();i++)
        out << currentRents[i]->getRentInfo();
    return out.str();
}

const std::vector<Rent *> &Client::getCurrentRents() const {
    return currentRents;
}
void Client::delRent(Rent *rent){
    currentRents.erase(std::remove(currentRents.begin(), currentRents.end(), rent), currentRents.end());
}
