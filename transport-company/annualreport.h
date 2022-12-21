//AnnualReport.h
#ifndef ANNUALREPORT
#define ANNUALREPORT
#include "tc.h"
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
#endif // ANNUALREPORT

