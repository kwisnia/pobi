//
// Created by student on 19.04.2020.
//

#ifndef CARRENTAL_RENT_H
#define CARRENTAL_RENT_H


#include "model/Client.h"
#include "model/Vehicle.h"
#include <boost/date_time.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
class Rent {
private:
    boost::uuids::uuid ID;
    ClientPtr client;
    VehiclePtr vehicle;
    pt::ptime beginTime;
    pt::ptime endTime;
    int rentCost=0;
public:
    const pt::ptime &getBeginTime() const;

    virtual ~Rent();

    const pt::ptime &getEndTime() const;

    Rent(ClientPtr client, VehiclePtr vehicle, pt::ptime& beginTime);

    const boost::uuids::uuid getId() const;

    ClientPtr getClient() const;

    VehiclePtr getVehicle() const;

    std::string getRentInfo();

    void endRent(pt::ptime&);

    int getRentDays() const;

    int getRentCost() const;


};


#endif //CARRENTAL_RENT_H
