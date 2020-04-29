//
// Created by student on 29.04.2020.
//

#ifndef CARRENTAL_CLIENTREPOSITORY_H
#define CARRENTAL_CLIENTREPOSITORY_H

#include <list>
#include "model/Client.h"

typedef Client* clientptr ;

class ClientRepository {
private:
std::list<clientptr> ClientRepo;
public:
ClientRepository();
virtual ~ClientRepository();
clientptr get(unsigned int&);
unsigned int size();
void add(clientptr);
std::list<clientptr> find(bool (*fun)(clientptr));
std::string report();
};


#endif //CARRENTAL_CLIENTREPOSITORY_H
