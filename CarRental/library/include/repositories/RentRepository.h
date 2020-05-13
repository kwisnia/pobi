//
// Created by student on 25.04.2020.
//

#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H


#include "model/Rent.h"
#include "Repository.h"

class RentRepository : public Repository<Rent> {
public:
    RentRepository();
    virtual ~RentRepository();
    void remove(RentPtr);
};


#endif //CARRENTAL_RENTREPOSITORY_H
