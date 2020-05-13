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
    RentRepository();
    virtual ~RentRepository();
    void remove(RentPtr);
    void add(RentPtr);
    int RepoSize();
    std::_List_iterator<std::shared_ptr<Rent>> begin();
    std::_List_iterator<std::shared_ptr<Rent>> end();

};


#endif //CARRENTAL_RENTREPOSITORY_H
