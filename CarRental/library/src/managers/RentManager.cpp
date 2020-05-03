//
// Created by student on 03.05.2020.
//

#include "managers/RentManager.h"
#include <iostream>
using namespace std;

RentPtr RentManager::rentVehicle(int id,ClientPtr c, VehiclePtr v, pt::ptime beginTime) {
    list<RentPtr> clientrents=currentRents->findAll([c](RentPtr r){return r->getClient()==c;});
    RentPtr vehiclecheck=currentRents->find([v](RentPtr r){return r->getVehicle()==v;});
    if (clientrents.size()>c->getMaxVehicles() or vehiclecheck==nullptr)
        return nullptr;
    else
    {   RentPtr newr(new Rent(id,c,v,beginTime));
        currentRents->add(newr);
        return newr;
}}

void RentManager::returnVehicle(VehiclePtr v) {
    RentPtr vehiclecheck=currentRents->find([v](RentPtr r){return r->getVehicle()==v;});
    pt::ptime endTime=pt::not_a_date_time;
    if (vehiclecheck!=nullptr)
    {
    vehiclecheck->endRent(endTime);
    list<RentPtr>::const_iterator i;
    for (i=currentRents->getRentRepo().begin();i!=currentRents->getRentRepo().end();i++)
    {
        if((*i)->getVehicle()==v)
            archiveRents->getRentRepo().splice(archiveRents->getRentRepo().end(),currentRents->getRentRepo(),i);
        break;
    }
    checkClientRentBalance(vehiclecheck->getClient());
    }
    else cout << "Blad: Pojazd nie jest wypozyczony"<<endl;
}

void RentManager::checkClientRentBalance(ClientPtr c) {
    list<RentPtr> clientrents=archiveRents->findAll([c](RentPtr r){return r->getClient()==c;});
    int balance=0;
    list<RentPtr>::const_iterator i;
    for (i=currentRents->getRentRepo().begin();i!=currentRents->getRentRepo().end();i++)
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
    list<RentPtr> clientcurrentrents=currentRents->findAll([c](RentPtr r){return r->getClient()==c;});
    list<RentPtr> clienttotalrents=archiveRents->findAll([c](RentPtr r){return r->getClient()==c;});
    clienttotalrents.splice(clienttotalrents.end(),clientcurrentrents);
    return clienttotalrents;
}

