//
// Created by student on 05.04.2020.
//

#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include <vector>
#include "Address.h"
#include "model/ClientType.h"
#include "exceptions/ClientException.h"
#include <sstream>
class Rent;

class Client {
    private:
        std::string firstName,lastName;
        std::string const personalID;
        AddressPtr address;
        ClientTypePtr clientType;
        bool isArchive=false;

public:
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalId,
           AddressPtr address);

    virtual ~Client();

    std::string getClientInfo();

    const ClientTypePtr &getClientType() const;

    void setClientType(const ClientTypePtr &clientType);

    int getMaxVehicles();

    bool isArchive1() const;

    void setIsArchive(bool isArchive);

    const std::string &getFirstName() const;

    void setFirstName(const std::string &firstName);

    const std::string &getLastName() const;

    void setLastName(const std::string &lastName);

    AddressPtr getAddress() const;

    void setAddress(AddressPtr address);

    const std::string &getPersonalId() const;
    };


#endif //CARRENTAL_CLIENT_H
