//
// Created by student on 25.04.2020.
//

#include "repositories/RentRepository.h"
using namespace std;
RentRepository::RentRepository() {}

RentRepository::~RentRepository() {
}

RentPtr RentRepository::get(unsigned int& id) {
    int i=0;
    if (this->size()<id or id==0)
        return nullptr;
    else
        for (list<RentPtr>::const_iterator iter = this->RentRepo.begin(),
                     end = this->RentRepo.end();
             iter != end;
             ++iter)
        {
            i++;
            if(i==id)
                return *iter;
        }
        return nullptr;
}

unsigned int RentRepository::size() {
    return RentRepo.size();
}

void RentRepository::add(RentPtr r) {
    this->RentRepo.push_back(r);
}

list<RentPtr> RentRepository::findAll(RentPredicate check) {
    list<RentPtr> found;
    for (list<RentPtr>::const_iterator iter = this->RentRepo.begin(),
                 end = this->RentRepo.end();
         iter != end;
         ++iter)
    {
        if(check(*iter))
            found.push_back(*iter);
    }
    return found;
}
RentPtr RentRepository::find(RentPredicate check) {
    for (list<RentPtr>::const_iterator iter = this->RentRepo.begin(),
                 end = this->RentRepo.end();
         iter != end;
         ++iter)
    {
        if(check(*iter))
            return *iter;
    }
    return nullptr;
}

string RentRepository::report() {
    ostringstream out;
    for (list<RentPtr>::const_iterator iter = this->RentRepo.begin(),
                 end = this->RentRepo.end();
         iter != end;
         ++iter)
    {
        out << (*iter)->getRentInfo()<<endl;
    }
    return out.str();
}

list<RentPtr> &RentRepository::getRentRepo() {
    return RentRepo;
}



