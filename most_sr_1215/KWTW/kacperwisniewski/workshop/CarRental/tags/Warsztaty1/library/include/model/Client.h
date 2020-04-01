//
// Created by student on 01.04.2020.
//

#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H
#include <string>
class Client
{
private:
    std::string firstName,lastName;
    std::string const personalID;
    Client();
public:
    Client(std::string,std::string,std::string);
    ~Client();
    std::string GetClientInfo();
    std::string getfirstName();
    void setfirstName(std::string);
    void setlastName(std::string);
    std::string getlastName();
    std::string getpersonalID();
};
#endif //CARRENTAL_CLIENT_H
