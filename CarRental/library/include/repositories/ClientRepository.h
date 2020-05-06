//
// Created by student on 29.04.2020.
//

#ifndef CARRENTAL_CLIENTREPOSITORY_H
#define CARRENTAL_CLIENTREPOSITORY_H

#include <list>
#include "model/Client.h"

class ClientRepository {
    private:
        friend class ClientManager;
        std::list<ClientPtr> ClientRepo;
    public:
        ClientRepository();
        virtual ~ClientRepository();
};


#endif //CARRENTAL_CLIENTREPOSITORY_H
