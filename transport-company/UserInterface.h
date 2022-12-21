//UserInterface.h
//заголовочный файл содержит объявления классов и т.п.
#ifndef TC_H
#define TC_H
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric> //для accumulate()
#include "driverslist.h"
#include "drivers.h"
#include "DriversInputScreen.h"
#include "FlightRevenue.h"
#include "revrecord.h"
#include "revinputscreen.h"
#include "expense.h"
#include "ExpenseRecord.h"
#include "expenseinputscreen.h"
#include "annualreport.h"
using namespace std;
//////////////////// глобальные методы //////////////////////
void getaLine(string& inStr); // получение строки текста
char getaChar(); // получение символа
//Главный класс для запуска приложения:
//этот класс определяет взаимодействие юзера с программой
class UserInterface
{
private:
    DriversList* ptrDriversList;
    DriversInputScreen* ptrDriversInputScreen;
    RevRecord* ptrRevRecord;
    RevInputScreen* ptrRevInputScreen;
    ExpenseRecord* ptrExpenseRecord;
    ExpenseInputScreen* ptrExpenseInputScreen;
    AnnualReport* ptrAnnualReport;
    char ch;
public:
    UserInterface();
    ~UserInterface();
    void interact();
};

#endif

