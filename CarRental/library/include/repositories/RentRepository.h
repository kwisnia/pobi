//
// Created by student on 25.04.2020.
//

#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H


#include <list>
#include "model/Rent.h"

typedef Rent* rentptr ;
class RentRepository {
private:
    std::list<rentptr> RentRepo;
public:
    RentRepository();
    virtual ~RentRepository();
    rentptr get(unsigned int&);
    unsigned int size();
    void add(rentptr);
    std::list<rentptr> find(bool (*fun)(rentptr));
    std::string report();
};


#endif //CARRENTAL_RENTREPOSITORY_H
