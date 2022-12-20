//FlightRevenue.h

#ifndef FLIGHTREVENUE_H
#define FLIGHTREVENUE_H

#include "tc.h"

////////////////////класс FlightRevenue//////////////////////////
//класс, хранящий одну табличную строку доходов с рейса
// одна строка таблицы прибыли: рейс и 12 доходов по месяцам
class FlightRevenue
{
private:
    int FlightNo; // рейсы, за которые уплачено
    float months[12]; // месяцы
public:
    FlightRevenue(int); // конструктор с одним параметром
    void setRev(int, float); // добавить пллату за месяц
    //сумма платежей из одной строки (прибыль с одного водителя за все месяцы)
    float getSumOfRev();
    int getFlightNo(); //Запрос номера рейса
    float getRevNo(int); //Запрос дохода за месяц int
};
#endif
