//
// Created by student on 02.05.2020.
//

#ifndef CARRENTAL_TYPEDEFS_H
#define CARRENTAL_TYPEDEFS_H
#include <functional>
#include <memory>
class Client;
class Vehicle;
class Moped;
class Bicycle;
class Car;
class Rent;
class Address;
class RentRepository;
class VehicleRepository;
class ClientRepository;
class ClientType;
class ClientManager;
class RentManager;
class VehicleManager;

typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Vehicle> VehiclePtr ;
typedef std::shared_ptr<Moped> MopedPtr;
typedef std::shared_ptr<Bicycle> BicyclePtr;
typedef std::shared_ptr<Car> CarPtr;
typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<Address> AddressPtr ;
typedef std::shared_ptr<ClientRepository> ClientRepoPtr;
typedef std::shared_ptr<VehicleRepository> VehicleRepoPtr;
typedef std::shared_ptr<RentRepository> RentRepoPtr;
typedef std::shared_ptr<ClientType> ClientTypePtr;
typedef std::shared_ptr<ClientManager> ClientManagerPtr;
typedef std::shared_ptr<RentManager> RentManagerPtr;
typedef std::shared_ptr<VehicleManager> VehicleManagerPtr;
typedef std::function<bool(ClientPtr)> ClientPredicate;
typedef std::function<bool(RentPtr)> RentPredicate;
typedef std::function<bool(VehiclePtr)> VehiclePredicate;



#endif //CARRENTAL_TYPEDEFS_H
