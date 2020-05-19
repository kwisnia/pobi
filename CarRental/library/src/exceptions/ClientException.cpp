//
// Created by student on 19.05.2020.
//

#include "exceptions/ClientException.h"

ClientException::ClientException(const char *what) : logic_error(what) {

}
