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
    RentRepoPtr RR(new RentRepository());
    ClientRepoPtr CR(new ClientRepository());
    VehicleRepoPtr VR(new VehicleRepository());
    fillRepos(CR,VR,RR);
    cout << CR->report() << endl<<endl;
    cout << VR->report()<<endl<<endl;
    cout << RR->report()<<endl<<endl;
    AddressPtr a(new Address("Boralus","Proudmoore","30"));
    ClientPtr c(new Client("Jaina","Proudmoore","23123",a));
    VehiclePtr romex(new Moped("wiiu", 20,200));
    pt::ptime testDefaultTime = pt::not_a_date_time;
    RentPtr r(new Rent(3,c,romex,testDefaultTime));
    CR->add(c);
    VR->add(romex);
    RR->add(r);
    cout << CR->report() << endl<<endl;
    cout << VR->report()<<endl<<endl;
    cout << RR->report()<<endl<<endl;

    // Test prostej wyszukiwarki w repozytorium (tak po prostu napisalem, to nie jest czesc warsztatu)
    string pesel;
    cout << "Podaj pesel: ";
    cin >> pesel;
    ClientPtr wynik=CR->find([pesel](ClientPtr c){return c->getPersonalId()==pesel;});
    cout << "Dane znalezionego klienta: "<<wynik->getClientInfo();
}
