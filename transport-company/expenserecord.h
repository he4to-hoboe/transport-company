//ExpenseRecord.h
#ifndef EXPENSERECORD
#define EXPENSERECORD
#include "UserInterface.h"
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

#endif // EXPENSERECORD

