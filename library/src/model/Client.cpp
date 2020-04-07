//
// Created by student on 05.04.2020.
//

#include "../../include/model/Client.h"
#include <iostream>
#include <string>
std::string Client::GetClientInfo() {
    return firstName+lastName+personalID;
}
Client::Client()
{
}
Client::Client(std::string imie, std::string nazwisko, std::string ID):firstName(imie), lastName(nazwisko), personalID(ID)
{
}
Client::~Client()
{
}
std::string Client::getfirstName() {return firstName;}
void Client::setfirstName(std::string newname)
{
    if (newname.length()==0)
        return;
    else
        firstName=newname;};
void Client::setlastName(std::string newlastname)
{
    if (newlastname.length()==0)
        return;
    else
        lastName=newlastname;}
std::string Client::getlastName() {return lastName;}
std::string Client::getpersonalID() {return personalID;}
