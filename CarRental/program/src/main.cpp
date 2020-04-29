//
// Created by student on 05.04.2020.
//
#include <iostream>
#include "model/Client.h"
#include <boost/date_time.hpp>
#include "model/Rent.h"
#include "model/Bicycle.h"
#include "model/Car.h"
#include "model/Moped.h"
#include "repositories/RentRepository.h"
#include "utils.h"
using namespace std;
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
typedef bool (*RentPredicate)(clientptr);
bool checkFirstName(clientptr c)
{
    return (c->getFirstName()=="Jaina");
}
int main()
{
    RentRepository* RR=new RentRepository();
    ClientRepository* CR=new ClientRepository();
    VehicleRepository* VR=new VehicleRepository();
    fillRepos(CR,VR,RR);
    cout << CR->report() << endl<<endl;
    cout << VR->report()<<endl<<endl;
    cout << RR->report()<<endl<<endl;
    Address* a=new Address("Boralus","Proudmoore","30");
    Client* c=new Client("Jaina","Proudmoore","23123",a);
    Moped* romex=new Moped("wiiu", 20,200);
    pt::ptime testDefaultTime = pt::not_a_date_time;
    Rent* r=new Rent(3,c,romex,testDefaultTime);
    CR->add(c);
    VR->add(romex);
    RR->add(r);
    cout << CR->report() << endl<<endl;
    cout << VR->report()<<endl<<endl;
    cout << RR->report()<<endl<<endl;
    delete CR;
    delete VR;
    delete RR;
}
