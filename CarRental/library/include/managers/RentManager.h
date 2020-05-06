//
// Created by student on 03.05.2020.
//

#ifndef CARRENTAL_RENTMANAGER_H
#define CARRENTAL_RENTMANAGER_H
#include "repositories/RentRepository.h"

class RentManager {
private:
    RentRepoPtr currentRents=std::make_shared<RentRepository>();
    RentRepoPtr archiveRents=std::make_shared<RentRepository>();
public:
    const RentRepoPtr &getCurrentRents() const;
    const RentRepoPtr &getArchiveRents() const;
    std::list<RentPtr> &getCurrentRentsList();
    std::list<RentPtr> &getArchiveRentsList();
    RentPtr rentVehicle(int,ClientPtr,VehiclePtr,pt::ptime);
    void returnVehicle(VehiclePtr);
    void checkClientRentBalance(ClientPtr);
    void changeClientType(ClientPtr,int);
    std::list<RentPtr> getAllClientRents(ClientPtr);
    void add(RentPtr);
    std::list<RentPtr> findAll(RentRepoPtr,RentPredicate);
    RentPtr find(RentRepoPtr,RentPredicate);
    std::string report(RentRepoPtr);
};


#endif //CARRENTAL_RENTMANAGER_H
