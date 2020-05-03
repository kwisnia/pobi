//
// Created by student on 29.04.2020.
//

#include "repositories/ClientRepository.h"
using namespace std;
ClientRepository::ClientRepository() {}

ClientRepository::~ClientRepository() {
}

ClientPtr ClientRepository::get(unsigned int& id) {
    int i=0;
    if (this->size()<id or id==0)
        return nullptr;
    else
        for (list<ClientPtr>::const_iterator iter = this->ClientRepo.begin(),
                     end = this->ClientRepo.end();
             iter != end;
             ++iter)
        {
            i++;
            if(i==id)
                return *iter;
        }
    return nullptr;
}

unsigned int ClientRepository::size() {
    return ClientRepo.size();
}

void ClientRepository::add(ClientPtr c) {
    this->ClientRepo.push_back(c);
}

list<ClientPtr> ClientRepository::findAll(ClientPredicate check) {
    list<ClientPtr> found;
    for (list<ClientPtr>::const_iterator iter = this->ClientRepo.begin(),
                 end = this->ClientRepo.end();
         iter != end;
         ++iter)
    {
        if(check(*iter))
            found.push_back(*iter);
    }
    return found;
}

ClientPtr ClientRepository::find(ClientPredicate check) {
    for (list<ClientPtr>::const_iterator iter = this->ClientRepo.begin(),
                 end = this->ClientRepo.end();
         iter != end;
         ++iter)
    {
        if(check(*iter))
            return *iter;
    }
    return nullptr;
}

std::string ClientRepository::report() {
    std::ostringstream out;
    for (list<ClientPtr>::const_iterator iter = this->ClientRepo.begin(),
                 end = this->ClientRepo.end();
         iter != end;
         ++iter)
    {
        out << (*iter)->getClientInfo()<<endl;
    }
    return out.str();
}

