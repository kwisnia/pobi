//
// Created by student on 29.04.2020.
//

#include "repositories/VehicleRepository.h"
using namespace std;
VehicleRepository::VehicleRepository() {}

VehicleRepository::~VehicleRepository() {
}

VehiclePtr VehicleRepository::get(unsigned int& id) {
    int i=0;
    if (this->size()<id or id==0)
        return nullptr;
    else
        for (std::list<VehiclePtr>::const_iterator iter = this->VehicleRepo.begin(),
                     end = this->VehicleRepo.end();
             iter != end;
             ++iter)
        {
            i++;
            if(i==id)
                return *iter;
        }
    return nullptr;
}

unsigned int VehicleRepository::size() {
    return VehicleRepo.size();
}

void VehicleRepository::add(VehiclePtr v) {
    this->VehicleRepo.push_back(v);
}

list<VehiclePtr> VehicleRepository::findAll(VehiclePredicate check) {
    list<VehiclePtr > found;
    for (list<VehiclePtr>::const_iterator iter = this->VehicleRepo.begin(),
                 end = this->VehicleRepo.end();
         iter != end;
         ++iter)
    {
        if(check(*iter))
            found.push_back(*iter);
    }
    return found;
}

std::string VehicleRepository::report() {
    ostringstream out;
    for (list<VehiclePtr>::const_iterator iter = this->VehicleRepo.begin(),
                 end = this->VehicleRepo.end();
         iter != end;
         ++iter)
    {
        out << (*iter)->getVehicleInfo()<<endl;
    }
    return out.str();
}

VehiclePtr VehicleRepository::find(VehiclePredicate check) {
    for (list<VehiclePtr>::const_iterator iter = this->VehicleRepo.begin(),
                 end = this->VehicleRepo.end();
         iter != end;
         ++iter)
    {
        if(check(*iter))
            return *iter;
    }
    return nullptr;
}

const list<VehiclePtr> &VehicleRepository::getVehicleRepo() const {
    return VehicleRepo;
}
