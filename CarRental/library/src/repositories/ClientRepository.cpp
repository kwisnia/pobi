//
// Created by student on 29.04.2020.
//

#include "repositories/ClientRepository.h"
using namespace std;
ClientRepository::ClientRepository() {}

ClientRepository::~ClientRepository() {
    for (list<clientptr>::const_iterator iter = this->ClientRepo.begin(),
                 end = this->ClientRepo.end();
         iter != end;
         ++iter)
    {
        delete *iter;
    }
}

clientptr ClientRepository::get(unsigned int& id) {
    int i=0;
    if (this->size()<id or id==0)
        return nullptr;
    else
        for (list<clientptr>::const_iterator iter = this->ClientRepo.begin(),
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

void ClientRepository::add(clientptr c) {
    this->ClientRepo.push_back(c);
}

list<clientptr> ClientRepository::find(bool (*fun)(clientptr)) {
    list<clientptr> found;
    for (list<clientptr>::const_iterator iter = this->ClientRepo.begin(),
                 end = this->ClientRepo.end();
         iter != end;
         ++iter)
    {
        if(fun(*iter))
            found.push_back(*iter);
    }
    return found;
}

std::string ClientRepository::report() {
    std::ostringstream out;
    for (list<clientptr>::const_iterator iter = this->ClientRepo.begin(),
                 end = this->ClientRepo.end();
         iter != end;
         ++iter)
    {
        out << (*iter)->getClientInfo()<<endl;
    }
    return out.str();
}