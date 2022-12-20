#ifndef DRIVERS_H
#define DRIVERS_H

//Drivers.h
#include <iostream>
#include <vector>
#include <list>
#include <string>


using namespace std;
//////////////////// класс Drivers (водители) //////////////////
//Он хранит имя водителя и номер рейса, в котором он находится.
class Drivers
{
private:
    string name; // имя водителя
    int flightNumber; // номер рейса, в котором он находится
public:
    Drivers(string n, int aNo);
    ~Drivers();
    int getFlightNumber(); //возвращает номер рейса водителя
    string getName(); //возвращает имя водителя
};
#endif
