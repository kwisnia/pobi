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

Client::Client(const string &firstName, const string &lastName, const string &personalId,
               AddressPtr address)
        : firstName(firstName), lastName(lastName), personalID(personalId), address(address){
    clientType=std::make_shared<Default>();
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

AddressPtr Client::getAddress() const {
    return address;
}

void Client::setAddress(AddressPtr address) {
    if(address!= nullptr)
    Client::address = address;
}

const std::string &Client::getPersonalId() const {
    return personalID;
}

bool Client::isArchive1() const {
    return isArchive;
}

void Client::setIsArchive(bool isArchive) {
    Client::isArchive = isArchive;
}

const ClientTypePtr &Client::getClientType() const {
    return clientType;
}

void Client::setClientType(const ClientTypePtr &clientType) {
    if (clientType!=nullptr)
    Client::clientType = clientType;
}

int Client::getMaxVehicles() {
    return this->clientType->getMaxVehicles();
}


