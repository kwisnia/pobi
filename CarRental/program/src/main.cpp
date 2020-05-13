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

int main()
{
    RentManagerPtr RM(new RentManager());
    ClientManagerPtr CM(new ClientManager());
    VehicleManagerPtr VM(new VehicleManager());
    fillRepos(CM,VM,RM);
    AddressPtr a(new Address("Boralus","Proudmoore","30"));
    pt::ptime testDefaultTime = pt::not_a_date_time;
    CM->registerClient("Jaina", "Proudmoore", "23123", a);
    VM->registerMoped("wiiu",20,200);
    cout << CM->report() << endl<<endl;
    cout << VM->report()<<endl<<endl;
    cout << RM->reportCurrent()<<endl<<endl;

    // Test prostej wyszukiwarki w repozytorium (tak po prostu napisalem, to nie jest czesc warsztatu)
    string pesel;
    cout << "Podaj pesel: ";
    cin >> pesel;
    list<ClientPtr> wynik=CM->findAll([pesel](ClientPtr c){return c->getPersonalId()==pesel;});
    cout << "Dane znalezionego klienta: "<<wynik.front()->getClientInfo();
}
