//DriversList.h
#ifndef DRIVERSLIST_H
#define DRIVERSLIST_H
#include "drivers.h"
using namespace std;
//класс DriversList — список всех водителей.
//Он содержит множество указателей на класс Drivers
// и оперирует ими при выводе
class DriversList
{
private:
    // установить указатели на водителей
    list <Drivers*> setPtrsDrive; // указатели на класс водителей
    list <Drivers*>::iterator iter; //итератор
public:
    ~DriversList(); // деструктор (удаление водителей)
    void insertDriver(Drivers*); // добавить водителя в список
    int getFlightNo(string); // возвращает номер рейса
    void display(); // вывод списка водителей
};
#endif
