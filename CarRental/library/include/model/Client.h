//
// Created by student on 05.04.2020.
//

#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include <vector>
#include "Address.h"
class Rent;

class Client {
    private:
        std::string firstName,lastName;
        std::string const personalID;
        Address* address;
        std::vector<Rent*> currentRents;
    public:

    Client(const std::string &firstName, const std::string &lastName, const std::string &personalId,
           Address *address);
    virtual ~Client();
    std::string getClientInfo();

    const std::string &getFirstName() const;

    void setFirstName(const std::string &firstName);

    const std::vector<Rent *> &getCurrentRents() const;

    const std::string &getLastName() const;

    void setLastName(const std::string &lastName);

    Address *getAddress() const;

    void setAddress(Address *address);

    const std::string &getPersonalId() const;

    void addRent(Rent*);
    const std::string getCurrentRentsInfo() const;
    std::string getFullClientInfo();
    void delRent(Rent *rent);

    };


#endif //CARRENTAL_CLIENT_H
