//
// Created by student on 25.04.2020.
//

#include "repositories/RentRepository.h"
using namespace std;
RentRepository::RentRepository() {}

RentRepository::~RentRepository() {
    for (list<rentptr>::const_iterator iter = this->RentRepo.begin(),
                 end = this->RentRepo.end();
         iter != end;
         ++iter)
    {
        delete *iter;
    }
}

rentptr RentRepository::get(unsigned int& id) {
    int i=0;
    if (this->size()<id or id==0)
        return nullptr;
    else
        for (list<rentptr>::const_iterator iter = this->RentRepo.begin(),
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

void RentRepository::add(rentptr r) {
    this->RentRepo.push_back(r);
}

list<rentptr> RentRepository::find(bool (*fun)(rentptr)) {
    list<rentptr> found;
    for (list<rentptr>::const_iterator iter = this->RentRepo.begin(),
                 end = this->RentRepo.end();
         iter != end;
         ++iter)
    {
        if(fun(*iter))
            found.push_back(*iter);
    }
    return found;
}

string RentRepository::report() {
    ostringstream out;
    for (list<rentptr>::const_iterator iter = this->RentRepo.begin(),
                 end = this->RentRepo.end();
         iter != end;
         ++iter)
    {
        out << (*iter)->getRentInfo()<<endl;
    }
    return out.str();
}

