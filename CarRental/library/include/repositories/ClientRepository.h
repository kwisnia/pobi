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
        void add(ClientPtr);
        int RepoSize();
        std::_List_iterator<std::shared_ptr<Client>> begin();
        std::_List_iterator<std::shared_ptr<Client>> end();
};


#endif //CARRENTAL_CLIENTREPOSITORY_H
