//
// Created by student on 29.04.2020.
//

#include "repositories/VehicleRepository.h"
using namespace std;
VehicleRepository::VehicleRepository() {}

VehicleRepository::~VehicleRepository() {
    for (list<vehicleptr>::const_iterator iter = this->VehicleRepo.begin(),
                 end = this->VehicleRepo.end();
         iter != end;
         ++iter)
    {
        delete *iter;
    }
}

vehicleptr VehicleRepository::get(unsigned int& id) {
    int i=0;
    if (this->size()<id or id==0)
        return nullptr;
    else
        for (std::list<vehicleptr>::const_iterator iter = this->VehicleRepo.begin(),
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

void VehicleRepository::add(vehicleptr v) {
    this->VehicleRepo.push_back(v);
}

list<vehicleptr> VehicleRepository::find(bool (*fun)(vehicleptr )) {
    list<vehicleptr > found;
    for (list<vehicleptr >::const_iterator iter = this->VehicleRepo.begin(),
                 end = this->VehicleRepo.end();
         iter != end;
         ++iter)
    {
        if(fun(*iter))
            found.push_back(*iter);
    }
    return found;
}

std::string VehicleRepository::report() {
    ostringstream out;
    for (list<vehicleptr>::const_iterator iter = this->VehicleRepo.begin(),
                 end = this->VehicleRepo.end();
         iter != end;
         ++iter)
    {
        out << (*iter)->getVehicleInfo()<<endl;
    }
    return out.str();
}