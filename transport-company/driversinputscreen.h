//DriversInputScreen.h
#ifndef DRIVERSINPUTSCREEN_H
#define DRIVERSINPUTSCREEN_H

#include "tc.h"



////////////////класс DriversInputScreen////////////////////
//класс DriversInputScreen. Это класс, отвечающий за отображение «экрана»,
//куда пользователь может ввести данные о новом водителе:
class DriversInputScreen
{
private:
    DriversList* ptrDriversList;
    string tName;
    int FlightNo;
public:
    DriversInputScreen(DriversList* ptrTL) : ptrDriversList(ptrTL)
    {
        /* тут пусто */
    }
    void setDriver(); // добавить данные о водителе
};
#endif // DRIVERSINPUTSCREEN_H

