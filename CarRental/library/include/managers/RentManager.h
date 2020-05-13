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
    RentPtr rentVehicle(ClientPtr,VehiclePtr,pt::ptime);
    void returnVehicle(VehiclePtr);
    void checkClientRentBalance(ClientPtr);
    void changeClientType(ClientPtr,int);
    std::list<RentPtr> getAllClientRents(ClientPtr);
    std::list<RentPtr> findAllCurrent(RentPredicate);
    std::list<RentPtr> findAllArchive(RentPredicate);
    RentPtr findArchive(RentPredicate);
    RentPtr findCurrent(RentPredicate);
    std::string reportCurrent();
    std::string reportArchive();
    unsigned int currentRepoSize();
    unsigned int archiveRepoSize();
};


#endif //CARRENTAL_RENTMANAGER_H
