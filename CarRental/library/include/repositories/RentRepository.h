//
// Created by student on 25.04.2020.
//

#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H


#include <list>
#include "model/Rent.h"

class RentRepository {
private:
    std::list<RentPtr> RentRepo;
public:
    std::list<RentPtr> &getRentRepo();

public:
    RentRepository();
    virtual ~RentRepository();
    RentPtr get(unsigned int&);
    unsigned int size();
    void add(RentPtr);
    std::list<RentPtr> findAll(RentPredicate);
    RentPtr find(RentPredicate);
    std::string report();
};


#endif //CARRENTAL_RENTREPOSITORY_H
