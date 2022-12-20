//Файл tc.cpp содержит все определения методов

#include "tc.h"


void getaLine(string& inStr) // получение строки текста
{
    char temp[21];
    cin.get(temp, 20, '\n');
    cin.ignore(20, '\n'); //число пропускаемых символов и символ разделения
    inStr = temp;
}
//---------------------------------------------------------
char getaChar() // получение символа
{
    char ch = cin.get();
    cin.ignore(80, '\n'); //число пропускаемых символов и символ разделения
    return ch;
}


//--------------------------------------------------------
//////////////методы класса ExpenseInputScreen/////////////
// конструктор
ExpenseInputScreen::ExpenseInputScreen(ExpenseRecord* per) : ptrExpenseRecord(per)
{
    /*пусто*/
}
//------------------------------------------------------
void ExpenseInputScreen::setExpense()
{
    int month, day;
    string category, payee;
    float amount;
    cout << "Enter the month (1-12): "; //Введите месяц (1-12)
    cin >> month;
    cin.ignore(80, '\n');
    cout << "Enter the day (1-31): ";   //Введите день (1-31)
    cin >> day;
    cin.ignore(80, '\n');
    cout << "Enter the expense category (fuel, toll roads, repair, taxes): ";  // Введите категорию расходов (Топливо, Платные дороги, Ремонт, Налоги)
    getaLine(category);
    cout << "Enter the recipient (Gazprom, rosavtodor,service station, Russia): "; // Введите получателя (Газпром, РОСАВТОДОР, СТО, Россия)
    getaLine(payee);
    cout << "Enter the amount (350.65): "; // Введите сумму
    cin >> amount;
    cin.ignore(80, '\n');
    // создаем новый расход
    Expense* ptrExpense = new Expense(month, day, category, payee, amount);
    // вставляем расход в список всех расходов
    ptrExpenseRecord->insertExp(ptrExpense);
}



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



//---------------------------------------------------------
////////////////методы класса UserInterface//////////////
UserInterface::UserInterface()
{
    ptrDriversList = new DriversList;
    ptrRevRecord = new RevRecord;
    ptrExpenseRecord = new ExpenseRecord;
}
//---------------------------------------------------------
UserInterface::~UserInterface()
{
    delete ptrDriversList;
    delete ptrRevRecord;
    delete ptrExpenseRecord;
}
//---------------------------------------------------------
void UserInterface::interact()
{
    while (true)
    {
        cout << "\n Click to add a driver 'a', \n"            //Нажмите для добавления водителя
            << " Click to record the driver's income 'b', \n"  //Нажмите для записи дохода водителя
            << " Click to record expenses 'c', \n"		  //Нажмите для записи расходов
            << " Click to withdraw tenants 'd', \n"		  //Нажмите для вывода жильцов
            << " Click to withdraw revenue 'e', \n"          //Нажмите для вывода доходов
            << " Click to display expenses 'f', \n"		  //Нажмите для вывода расходов
            << " Click to display the annual report 'g', \n"  //Нажмите для вывода годового отчета
            << " Click to exit the program 'q'.\n";     //Нажмите для выхода из программы
        ch = getaChar();
        switch (ch)
        {
        case 'a': ptrDriversInputScreen = new DriversInputScreen(ptrDriversList);
            ptrDriversInputScreen->setDriver();
            delete ptrDriversInputScreen;
            break;
        case 'b': ptrRevInputScreen = new RevInputScreen(ptrDriversList, ptrRevRecord);
            ptrRevInputScreen->setRev();
            delete ptrRevInputScreen;
            break;
        case 'c': ptrExpenseInputScreen = new ExpenseInputScreen(ptrExpenseRecord);
            ptrExpenseInputScreen->setExpense();
            delete ptrExpenseInputScreen;
            break;
        case 'd': ptrDriversList->display();
            break;
        case 'e': ptrRevRecord->display();
            break;
        case 'f': ptrExpenseRecord->display();
            break;
        case 'g':
            ptrAnnualReport = new AnnualReport(ptrRevRecord, ptrExpenseRecord);
            ptrAnnualReport->display();
            delete ptrAnnualReport;
            break;
        case 'q':
            cout << "The program is completed"; // Программа завершена
            return;
            break;
        default: cout << "Unknown output function\n"; //Неизвестная функция вывода
            break;
        } // конец switch
    } // конец while
} // конец interact()
