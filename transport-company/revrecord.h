//RevRecord.h
#ifndef REVRECORD
#define REVRECORD
#include "UserInterface.h"
//класс RevRecord. Он хранит непосредственно записи доходов.
//С ним будет взаимодействовать экран добавления дохода.
class RevRecord
{
private:
    list <FlightRevenue*> setPtrsRR; // указатели на объекты FlightRevenue (по одному на водителя)
    list <FlightRevenue*>::iterator iter;
public:
    ~RevRecord();
    void insertRev(int, int, float); // добавить плату
    void display(); // отобразить все строки с платами
    float getSumOfRev(); // подсчитать сумму всех платежей всех водителей
};

#endif // REVRECORD

