//
// Created by student on 25.04.2020.
//

#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H


#include <list>
#include "model/Rent.h"

class RentRepository {
private:
    friend class RentManager;
    std::list<RentPtr> RentRepo;
public:
    RentRepository();
    virtual ~RentRepository();
};


#endif //CARRENTAL_RENTREPOSITORY_H
