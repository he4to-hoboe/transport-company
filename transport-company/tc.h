//tc.h
//заголовочный файл содержит объявления классов и т.п.
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric> //для accumulate()
#include "driverslist.h"
#include "drivers.h"
using namespace std;
//////////////////// глобальные методы //////////////////////
void getaLine(string& inStr); // получение строки текста
char getaChar(); // получение символа



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





//////////////////// класс RevRecord ///////////////////////
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





////////////////////класс RevInputScreen //////////////////
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





///////////////////////класс Expense///////////////////////
//Класс затрат
class Expense
{
public:
    int month, day; // месяц и день уплаты расходов
    string category; // категория расходов (топливо, платные налоги, ремонт/ТО, налоги)
    string payee; // кому платим (АЗС, РОСАВТОДОР, СТО, государство, )
    float amount; // сколько платим
    Expense()
    { }
    Expense(int m, int d, string c, string p, float a) :
        month(m), day(d), category(c), payee(p), amount(a)
    {
        /* тут пусто! */
    }
};




///////////////////класс ExpenseRecord/////////////////////
//Класс записей о затратах
class ExpenseRecord
{
private:
    vector<Expense*> vectPtrsExpenses; //вектор указателей на расходы
    vector<Expense*>::iterator iter;
public:
    ~ExpenseRecord();
    void insertExp(Expense*);
    void display();
    float displaySummary(); // нужно для годового отчета
};





////////////////класс ExpenseInputScreen///////////////////
//Класс для ввода расходов
class ExpenseInputScreen
{
private:
    ExpenseRecord* ptrExpenseRecord; // запись о расходах
public:
    ExpenseInputScreen(ExpenseRecord*);
    void setExpense();
};





//////////////////класс AnnualReport///////////////////////
//Класс годового отчета
class AnnualReport
{
private:
    RevRecord* ptrRR; // записи доходов
    ExpenseRecord* ptrER; // записи расходов
    float expenses, rents; // суммы доходов и расходов
public:
    AnnualReport(RevRecord*, ExpenseRecord*);
    void display(); // отображение годового отчета
};





//////////////////Класс UserInterface//////////////////////
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

