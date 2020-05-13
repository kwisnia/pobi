//
// Created by student on 25.04.2020.
//

#include "repositories/RentRepository.h"
using namespace std;
RentRepository::RentRepository() {}

RentRepository::~RentRepository() {
}

void RentRepository::remove(RentPtr r) {
    objects.remove(r);
}
