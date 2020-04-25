//
// Created by student on 08.04.2020.
//

#ifndef CARRENTAL_ADDRESS_H
#define CARRENTAL_ADDRESS_H
#include <string>


class Address {
    private:
        std::string city,street,number;
    public:
    Address(const std::string &city, const std::string &street, const std::string &number);

    virtual ~Address();
        std::string GetAddressInfo();

    const std::string &getCity() const;

    void setCity(const std::string &city);

    const std::string &getStreet() const;

    void setStreet(const std::string &street);

    const std::string &getNumber() const;

    void setNumber(const std::string &number);
};


#endif //CARRENTAL_ADDRESS_H
