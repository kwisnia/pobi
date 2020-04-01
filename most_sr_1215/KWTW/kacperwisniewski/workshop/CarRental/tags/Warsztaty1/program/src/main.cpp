//
// Created by student on 01.04.2020.
//

#include <iostream>
#include "model/Client.h"
using namespace std;
int main()
{
    Client Michal("Michal","Gebel","229691");
    Client* Wojtek=new Client("Wojciech","Slabosz","230000");
    Wojtek->setfirstName("");
    Wojtek->GetClientInfo();
    delete Wojtek;
}