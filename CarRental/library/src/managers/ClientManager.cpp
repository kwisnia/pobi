//
// Created by student on 03.05.2020.
//

#include "managers/ClientManager.h"
#include <iostream>
using namespace std;
ClientPtr ClientManager::registerClient(string& firstName, string& lastName, string& personalID, AddressPtr address) {
    ClientPtr repeatCheck=clientRepository->find([personalID](ClientPtr c){return c->getPersonalId()==personalID;});
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

ClientPtr ClientManager::getClient(string& ID) {
    return clientRepository->find([ID](ClientPtr c){return c->getPersonalId()==ID;});
}

