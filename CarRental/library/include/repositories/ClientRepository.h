//
// Created by student on 29.04.2020.
//

#ifndef CARRENTAL_CLIENTREPOSITORY_H
#define CARRENTAL_CLIENTREPOSITORY_H

#include <list>
#include "model/Client.h"

class ClientRepository {
private:
std::list<ClientPtr> ClientRepo;
public:
ClientRepository();
virtual ~ClientRepository();
ClientPtr get(unsigned int&);
unsigned int size();
void add(ClientPtr);
std::list<ClientPtr> findAll(ClientPredicate);
ClientPtr find(ClientPredicate);
std::string report();
};


#endif //CARRENTAL_CLIENTREPOSITORY_H
