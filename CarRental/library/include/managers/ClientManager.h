//
// Created by student on 03.05.2020.
//

#ifndef CARRENTAL_CLIENTMANAGER_H
#define CARRENTAL_CLIENTMANAGER_H
#include "repositories/ClientRepository.h"


class ClientManager {
private:
    ClientRepoPtr clientRepository=std::make_shared<ClientRepository>();
public:
    ClientPtr registerClient(std::string&,std::string&,std::string&,AddressPtr);
    static void unregisterClient(ClientPtr);
    ClientPtr getClient(std::string&);

};


#endif //CARRENTAL_CLIENTMANAGER_H
