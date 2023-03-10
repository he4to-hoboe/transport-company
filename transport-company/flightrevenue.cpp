//FlightRevenue.cpp
#include "UserInterface.h"
FlightRevenue::FlightRevenue(int an) : FlightNo(an) //конструктор
{ //Алгоритм fill() помещает копию значения value (у нас это 0)
//в каждый элемент диапазона, ограниченного парой итераторов [first,last).
//Т.е. в конструкторе просто инициализируем массив значениями 0.
    fill(&months[0], &months[12], 0);
}

void FlightRevenue::setRev(int m, float am) // сеттер доход за месяц m, сумма - am
{
    months[m] = am; // привязываем оплату к месяцу
}

int FlightRevenue::getFlightNo() // геттер запрос номера рейса
{
    return FlightNo;
}

float FlightRevenue::getRevNo(int month) //Геттер запрос дохода за месяц month
{
    return months[month];
}

float FlightRevenue::getSumOfRev() // cумма дохода в строке
{ //По умолчанию алгоритм accumulate() суммирует элементы.
 //Нужно указать точку старта, конечную точку и значение от которого начинаем прибавлять.
 //Чаще всего это ноль, но может быть и результат других вычислений.
    return accumulate(&months[0], &months[12], 0);
}
