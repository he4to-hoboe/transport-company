// RevInputScreen.h
#ifndef REVINPUTSCREEN
#define REVINPUTSCREEN
#include "UserInterface.h"
//Экран для добавления платы
class RevInputScreen
{
private:
    DriversList* ptrDriversList; // список водителей
    RevRecord* ptrRevRecord; // список записей об оплате
    string revName; // имя водителя, который приносит прибыль
    float revPaid; // плата
    int month; // за месяц
    int FlightNo; // по рейсам
public:
    RevInputScreen(DriversList* ptrTL, RevRecord* ptrRR) : ptrDriversList(ptrTL),
        ptrRevRecord(ptrRR)
    {
        /*тут пусто*/
    }
    void setRev(); // добавить доход с одного водителя за месяц
};

#endif // REVINPUTSCREEN

