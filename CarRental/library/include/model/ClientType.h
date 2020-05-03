//
// Created by student on 02.05.2020.
//

#ifndef CARRENTAL_CLIENTTYPE_H
#define CARRENTAL_CLIENTTYPE_H


class ClientType {
public:
    ClientType();
    virtual ~ClientType();
    virtual int getMaxVehicles() const=0;
    virtual unsigned int applyDiscount(int price)=0;

};
class Default : public ClientType
{
public:
     int getMaxVehicles() const override;
     unsigned int applyDiscount(int price) override;
};

class Bronze : public ClientType
{
public:
     int getMaxVehicles() const override ;
     unsigned int applyDiscount(int price) override;
};

class Silver : public ClientType
{
public:
     int getMaxVehicles() const override;
     unsigned int applyDiscount(int price) override;
};

class Gold : public ClientType
{
public:
     int getMaxVehicles() const override;
     unsigned int applyDiscount(int price) override;
};

class Platinum : public ClientType
{
public:
     int getMaxVehicles() const override;
     unsigned int applyDiscount(int price) override;
};

class Diamond : public ClientType
{
public:
     int getMaxVehicles() const override;
     unsigned int applyDiscount(int price) override;
};

#endif //CARRENTAL_CLIENTTYPE_H
