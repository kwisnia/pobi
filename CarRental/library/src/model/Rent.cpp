//
// Created by student on 19.04.2020.
//

#include "model/Rent.h"
using namespace std;
Rent::Rent(ClientPtr client, VehiclePtr vehicle, pt::ptime& beginTime) : ID(boost::uuids::random_generator()()), client(client),
                                                                                           vehicle(vehicle),
                                                                                           beginTime(beginTime) {
    if (beginTime==pt::not_a_date_time)
        this->beginTime=pt::second_clock::local_time();
    endTime=pt::not_a_date_time;

}

const boost::uuids::uuid Rent::getId() const {
    return ID;
}

ClientPtr Rent::getClient() const {
    return client;
}

VehiclePtr Rent::getVehicle() const {
    return vehicle;
}
string Rent::getRentInfo() {
    ostringstream out;
    out << "ID wypozyczenia: "<<boost::uuids::to_string(ID)<<endl<<client->getClientInfo()<<endl<<"Dane wypozyczonego pojazdu: "<<endl<<vehicle->getVehicleInfo()<<endl;
    out << "Data rozpoczecia wypozyczenia: "<<beginTime<<endl;
    out << "Data zakonczenia wypozyczenia: "<<endTime<<endl;
    return out.str();
}

const pt::ptime &Rent::getBeginTime() const {
    return beginTime;
}

const pt::ptime &Rent::getEndTime() const {
    return endTime;
}

void Rent::endRent(pt::ptime &endTime)
{
    try{
    if (this->endTime==pt::not_a_date_time)
    {
        if (endTime.is_not_a_date_time())
            this->endTime = pt::second_clock::local_time();
        else if (endTime < beginTime)
            throw RentException("Czas koncowy mniejszy od poczatkowego");
        else
            this->endTime = endTime;

        rentCost = this->getClient()->getClientType()->applyDiscount(getRentDays() * vehicle->getActualRentalPrice());
    }}
    catch(const RentException& ex) {
        cout << "Wystapil problem: " << endl;
        cout << ex.what();
        throw;
    }}

int Rent::getRentDays() const {
    if (endTime==pt::not_a_date_time)
        return 0;
    pt::time_period period(beginTime, endTime);
    if (period.length().minutes()<1 and period.length().hours()<1)
        return 0;
    int RentDays=(period.length().hours()/24)+1;
    return RentDays;

}

int Rent::getRentCost() const {
    return rentCost;
}

Rent::~Rent() {

}


