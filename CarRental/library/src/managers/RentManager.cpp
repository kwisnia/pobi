//
// Created by student on 03.05.2020.
//

#include "managers/RentManager.h"
#include <iostream>
using namespace std;
void RentManager::add(RentPtr r) {
    currentRents->RentRepo.push_back(r);
}

list<RentPtr> RentManager::findAll(RentRepoPtr rr,RentPredicate check) {
    list<RentPtr> found;
    for (list<RentPtr>::const_iterator iter = rr->RentRepo.begin(),
                 end = rr->RentRepo.end();
         iter != end;
         ++iter)
    {
        if(check(*iter))
            found.push_back(*iter);
    }
    return found;
}
RentPtr RentManager::find(RentRepoPtr rr,RentPredicate check) {
    for (list<RentPtr>::const_iterator iter = rr->RentRepo.begin(),
                 end = rr->RentRepo.end();
         iter != end;
         ++iter)
    {
        if(check(*iter))
            return *iter;
    }
    return nullptr;
}

string RentManager::report(RentRepoPtr rr) {
    ostringstream out;
    for (list<RentPtr>::const_iterator iter = rr->RentRepo.begin(),
                 end = rr->RentRepo.end();
         iter != end;
         ++iter)
    {
        out << (*iter)->getRentInfo()<<endl;
    }
    return out.str();
}



RentPtr RentManager::rentVehicle(int id,ClientPtr c, VehiclePtr v, pt::ptime beginTime) {
    list<RentPtr> clientrents=findAll(currentRents,[c](RentPtr r){return r->getClient()==c;});
    RentPtr vehiclecheck=find(currentRents,[v](RentPtr r){return r->getVehicle()==v;});
    if (clientrents.size()==c->getMaxVehicles() or vehiclecheck!=nullptr)
        return nullptr;
    else
    {   RentPtr newr(new Rent(id,c,v,beginTime));
        add(newr);
        return newr;
}}

void RentManager::returnVehicle(VehiclePtr v) {
    RentPtr vehiclecheck=find(currentRents,[v](RentPtr r){return r->getVehicle()==v;});
    pt::ptime endTime=pt::not_a_date_time;
    if (vehiclecheck!=nullptr)
    {
    vehiclecheck->endRent(endTime);
    list<RentPtr>::const_iterator i;
    for (i=currentRents->RentRepo.begin();i!=currentRents->RentRepo.end();i++)
    {
        if((*i)->getVehicle()==v)
            archiveRents->RentRepo.splice(archiveRents->RentRepo.end(),currentRents->RentRepo,i);
        break;
    }
    checkClientRentBalance(vehiclecheck->getClient());
    }
    else cout << "Blad: Pojazd nie jest wypozyczony"<<endl;
}

void RentManager::checkClientRentBalance(ClientPtr c) {
    list<RentPtr> clientrents=findAll(archiveRents,[c](RentPtr r){return r->getClient()==c;});
    int balance=0;
    list<RentPtr>::const_iterator i;
    for (i=clientrents.begin();i!=clientrents.end();i++)
    {
        balance+=(*i)->getRentCost();
    }
    changeClientType(c, balance);

}

void RentManager::changeClientType(ClientPtr c, int balance) {
    ClientTypePtr bronze(new Bronze());
    ClientTypePtr silver(new Silver());
    ClientTypePtr gold(new Gold());
    ClientTypePtr platinum(new Platinum());
    ClientTypePtr diamond(new Diamond());
    switch(c->getMaxVehicles())
    {
        case 1:
            if(balance>=100)
                c->setClientType(bronze);
            break;
        case 2:
            if(balance>=200)
                c->setClientType(silver);
            break;
        case 3:
            if(balance>=400)
                c->setClientType(gold);
            break;
        case 4:
            if(balance>=800)
                c->setClientType(platinum);
            break;
        case 5:
            if(balance>=1600)
                c->setClientType(diamond);
            break;

}}

list<RentPtr> RentManager::getAllClientRents(ClientPtr c) {
    list<RentPtr> clientarchiverents=findAll(archiveRents,[c](RentPtr r){return r->getClient()==c;});
    list<RentPtr> clienttotalrents=findAll(currentRents,[c](RentPtr r){return r->getClient()==c;});
    clienttotalrents.splice(clienttotalrents.end(),clientarchiverents);
    return clienttotalrents;
}

const RentRepoPtr &RentManager::getCurrentRents() const {
    return currentRents;
}

const RentRepoPtr &RentManager::getArchiveRents() const {
    return archiveRents;
}

std::list<RentPtr> &RentManager::getCurrentRentsList() {
    return currentRents->RentRepo;
}

std::list<RentPtr> &RentManager::getArchiveRentsList() {
    return archiveRents->RentRepo;
}

