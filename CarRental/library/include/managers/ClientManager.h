//
// Created by student on 03.05.2020.
//

#ifndef CARRENTAL_CLIENTMANAGER_H
#define CARRENTAL_CLIENTMANAGER_H
#include "repositories/ClientRepository.h"
#include "predicates.h"

class ClientManager {
private:
    ClientRepoPtr clientRepository=std::make_shared<ClientRepository>();
public:
    ClientPtr registerClient(std::string,std::string,std::string,AddressPtr);
    static void unregisterClient(ClientPtr);
    ClientPtr getClient(std::string);
    template <class P>
    std::list<ClientPtr> findAll(const P &predicate) const;
    template <class P>
    ClientPtr find(const P &check);
    std::string report();
    unsigned int RepoSize();
};
template <class P>
std::list<ClientPtr> ClientManager::findAll(const P &predicate) const {
    std::list<ClientPtr> found;
    for (std::list<ClientPtr>::const_iterator iter = this->clientRepository->begin(),
                 end = this->clientRepository->end();
         iter != end;
         ++iter)
    {
        if(predicate(*iter))
            found.push_back(*iter);
    }
    return found;
}
template <class P>
ClientPtr ClientManager::find(const P &check) {
    for (std::list<ClientPtr>::const_iterator iter = this->clientRepository->begin(),
                 end = this->clientRepository->end();
         iter != end;
         ++iter)
    {
        if(check(*iter))
            return *iter;
    }
    return nullptr;
}

#endif //CARRENTAL_CLIENTMANAGER_H
