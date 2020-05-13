//
// Created by student on 25.04.2020.
//

#include "repositories/RentRepository.h"
using namespace std;
RentRepository::RentRepository() {}

RentRepository::~RentRepository() {
}
void RentRepository::add(RentPtr c) {
    RentRepo.push_back(c);
}

int RentRepository::RepoSize() {
    return RentRepo.size();
}
_List_iterator<shared_ptr<Rent>> RentRepository::begin() {
    return RentRepo.begin();
}

_List_iterator<shared_ptr<Rent>> RentRepository::end() {
    return RentRepo.end();
}

void RentRepository::remove(RentPtr r) {
    RentRepo.remove(r);
}
