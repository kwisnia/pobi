//
// Created by student on 19.05.2020.
//

#ifndef CARRENTAL_CLIENTEXCEPTION_H
#define CARRENTAL_CLIENTEXCEPTION_H
#include <stdexcept>

class ClientException : public std::logic_error {
public:
    explicit ClientException(const char* what);
};


#endif //CARRENTAL_CLIENTEXCEPTION_H
