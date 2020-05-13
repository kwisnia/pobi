//
// Created by student on 29.04.2020.
//

#include "repositories/ClientRepository.h"
using namespace std;
ClientRepository::ClientRepository() {}

ClientRepository::~ClientRepository() {
}
void ClientRepository::add(ClientPtr c) {
    ClientRepo.push_back(c);
}

int ClientRepository::RepoSize() {
    return ClientRepo.size();
}

_List_iterator<shared_ptr<Client>> ClientRepository::begin() {
    return ClientRepo.begin();
}

_List_iterator<shared_ptr<Client>> ClientRepository::end() {
    return ClientRepo.end();
}
