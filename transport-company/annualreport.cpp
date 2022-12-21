//AnnualReport.cpp
#include "tc.h"
//---------------------------------------------------------
////////////////методы класса AnnualReport/////////////////
//Конструктор
AnnualReport::AnnualReport(RevRecord* pRR, ExpenseRecord* pER) : ptrRR(pRR), ptrER(pER)
{ /* пусто */
}
//---------------------------------------------------------
void AnnualReport::display()
{
    cout << "Annual Report\n--------------\n" << endl; //Годовой отчет
    cout << "Income\n" << endl; // Доходы
    cout << "\tPayment for the flight:\t"; // Плата за рейс
    rents = ptrRR->getSumOfRev();
    cout << rents << endl;
    cout << "Expenses\n" << endl;  // Расходы
    expenses = ptrER->displaySummary();
    cout << "Total expenses:\t\t\t";  //Расходы всего
    cout << expenses << endl;
    // вычисляем прибыльность
    cout << "\nBalance:\t\t\t" << (rents - expenses) << endl; // Баланс
}
