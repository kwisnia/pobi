//
// Created by student on 19.05.2020.
//

#ifndef CARRENTAL_RENTEXCEPTION_H
#define CARRENTAL_RENTEXCEPTION_H
#include <stdexcept>


class RentException : public std::logic_error {
public:
    explicit RentException(const char* what);
};


#endif //CARRENTAL_RENTEXCEPTION_H
