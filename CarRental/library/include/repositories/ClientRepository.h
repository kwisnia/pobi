//
// Created by student on 29.04.2020.
//

#ifndef CARRENTAL_CLIENTREPOSITORY_H
#define CARRENTAL_CLIENTREPOSITORY_H

#include <list>
#include "model/Client.h"
#include "Repository.h"

class ClientRepository : public Repository<Client> {
    public:
        ClientRepository();
        virtual ~ClientRepository();

};


#endif //CARRENTAL_CLIENTREPOSITORY_H
