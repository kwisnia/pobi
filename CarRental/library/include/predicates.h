//
// Created by student on 19.05.2020.
//

#ifndef CARRENTAL_PREDICATES_H
#define CARRENTAL_PREDICATES_H
#include <regex>
#include "model/typedefs.h"
#include "model/Rent.h"
class FirstNamePredicate {
private:
    std::string pattern;
public:
    explicit FirstNamePredicate(const std::string& pattern);
    bool operator()(const ClientPtr &ptr) const;
};
class LastNamePredicate {
private:
    std::string pattern;
public:
    explicit LastNamePredicate(const std::string& pattern);
    bool operator()(const ClientPtr &ptr) const;
};
class IDPredicate {
private:
    std::string pattern;
public:
    explicit IDPredicate(const std::string& pattern);
    bool operator()(const ClientPtr &ptr) const;
};

#endif //CARRENTAL_PREDICATES_H
