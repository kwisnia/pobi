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
    try {
        if (firstName.length() != 0)
            Client::firstName = firstName;
        else
            throw ClientException("Wprowadzono puste pole!");
    }
    catch (const VehicleException& ex) {
        cout << "Wystapil problem: "<<endl;
        cout << ex.what()<<endl;
        throw;
    }
}

const string &Client::getLastName() const {
    return lastName;
}

void Client::setLastName(const string &lastName) {
    try {
        if (lastName.length() != 0)
            Client::lastName = lastName;
        else
            throw ClientException("Wprowadzono puste pole!");
    }
    catch (const VehicleException& ex) {
        cout << "Wystapil problem: "<<endl;
        cout << ex.what()<<endl;
        throw;
    }
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

void Client::setClientType(const ClientTypePtr &clientType)
{
try {
    if (clientType != nullptr)
        Client::clientType = clientType;
    else
        throw ClientException("Nie przekazano poprawnie typu klienta!");
}
catch (const ClientException& ex) {
cout << "Wystapil problem: "<<endl;
cout << ex.what()<<endl;
throw;
}
}

int Client::getMaxVehicles() {
    return this->clientType->getMaxVehicles();
}


