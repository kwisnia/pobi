//
// Created by student on 19.05.2020.
//

#include "predicates.h"
using namespace std;
FirstNamePredicate::FirstNamePredicate(const std::string &pattern):pattern(pattern) {

}

bool FirstNamePredicate::operator()(const ClientPtr &ptr) const {
    regex pattern2{"\\w*"+pattern+"\\w*"};
    return regex_match(ptr->getFirstName(),pattern2);
}

LastNamePredicate::LastNamePredicate(const std::string &pattern):pattern(pattern) {

}

bool LastNamePredicate::operator()(const ClientPtr &ptr) const {
    regex pattern2{"\\w*"+pattern+"\\w*"};
    return regex_match(ptr->getLastName(),pattern2);
    }
IDPredicate::IDPredicate(const std::string &pattern):pattern(pattern) {

}

bool IDPredicate::operator()(const ClientPtr &ptr) const {
    regex pattern2{"\\w*"+pattern+"\\w*"};
    return regex_match(ptr->getPersonalId(),pattern2);}
