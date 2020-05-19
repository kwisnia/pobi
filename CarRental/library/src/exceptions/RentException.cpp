//
// Created by student on 19.05.2020.
//

#include "exceptions/RentException.h"

RentException::RentException(const char *what) : logic_error(what) {

}
