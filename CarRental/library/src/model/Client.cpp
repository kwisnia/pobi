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
using namespace std;
string Client::getClientInfo() {
    ostringstream out;
    out << "Imie i nazwisko klienta: "<<firstName<<" "<<lastName<<endl;
    out << "Adres klienta: "<<getAddress()->getAddressInfo()<<endl;
    return out.str();
}
string Client::getFullClientInfo() {
    ostringstream out;
    out << getClientInfo()<<endl;
    out << "Dane o wypozyczeniach: "<<getCurrentRentsInfo()<<endl;
    return out.str();
}

Client::Client(const string &firstName, const string &lastName, const string &personalId,
               Address *address)
        : firstName(firstName), lastName(lastName), personalID(personalId), address(address){
    currentRents.clear();
}

Client::~Client()
{
}

const string &Client::getFirstName() const {
    return firstName;
}

void Client::setFirstName(const string &firstName) {
    if(firstName.length()>0)
    Client::firstName = firstName;
}

const string &Client::getLastName() const {
    return lastName;
}

void Client::setLastName(const string &lastName) {
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

const string Client::getCurrentRentsInfo() const {
    ostringstream out;

    for (int i=0;i<currentRents.size();i++)
        out << currentRents[i]->getRentInfo();
    return out.str();
}

const vector<Rent *> &Client::getCurrentRents() const {
    return currentRents;
}
void Client::delRent(Rent *rent){
    currentRents.erase(remove(currentRents.begin(), currentRents.end(), rent), currentRents.end());
}
