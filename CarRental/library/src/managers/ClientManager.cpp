//
// Created by student on 03.05.2020.
//

#include "managers/ClientManager.h"
#include <iostream>
using namespace std;



std::string ClientManager::report() {
    std::ostringstream out;
    for (list<ClientPtr>::const_iterator iter = this->clientRepository->begin(),
                 end = this->clientRepository->end();
         iter != end;
         ++iter)
    {
        out << (*iter)->getClientInfo()<<endl;
    }
    return out.str();
}
ClientPtr ClientManager::registerClient(string firstName, string lastName, string personalID, AddressPtr address) {
    IDPredicate predicate(personalID);
    ClientPtr repeatCheck=find<IDPredicate>(predicate);
    if (repeatCheck != nullptr)
        return repeatCheck;
    else if (address == nullptr)
        return nullptr;
    else {
        ClientPtr newc(new Client(firstName,lastName,personalID,address));
        clientRepository->add(newc);
        return newc;
    }
}
void ClientManager::unregisterClient(ClientPtr c) {
    if (c->isArchive1())
        cout << "Klient zostal juz odrejestrowany"<<endl;
    c->setIsArchive(true);
}

ClientPtr ClientManager::getClient(string ID) {
    return find([ID](ClientPtr c){return c->getPersonalId()==ID;});
}

unsigned int ClientManager::RepoSize() {
    return clientRepository->RepoSize();
}


