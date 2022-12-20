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





//---------------------------------------------------------
/////////////////методы класса RevRecord//////////////////
RevRecord::~RevRecord() // деструктор
{ // удалить строки с платежами,
// удалить указатели из множества.
    while (!setPtrsRR.empty())
    {
        iter = setPtrsRR.begin();
        delete* iter;
        setPtrsRR.erase(iter);
    }
}
//---------------------------------------------------------
void RevRecord::insertRev(int FlightNo, int month, float amount)
{
    iter = setPtrsRR.begin(); // Инициализация итератора
    while (iter != setPtrsRR.end()) // условие выхода
    { // если текущий объект совпадает с созданным для поиска,
        if (FlightNo == (*iter)->getFlightNo())
        { // заносим доход в список
            (*iter)->setRev(month, amount);
            return;
        }
        else
            iter++;
    } // если не нашли строку - создаем новую
    FlightRevenue* ptrRow = new FlightRevenue(FlightNo);
    ptrRow->setRev(month, amount); // заносим в нее платеж
    setPtrsRR.push_back(ptrRow); // заносим строку в вектор
}
//---------------------------------------------------------
void RevRecord::display() // отобразить все строки с доходами
{
    cout << "\nNumber\tJan Feb Mar Apr May June July Aug Sept Oct Nov Dec\n" << endl
        << "------------------------------------------------------------------\n" << endl;
    if (setPtrsRR.empty())
        cout << "***No income***\n" << endl;
    else
    {
        iter = setPtrsRR.begin(); //итератор на список с указателями на объекты FlightRevenue
        while (iter != setPtrsRR.end())
        {
            cout << (*iter)->getFlightNo() << '\t'; // вывести номер рейса
            for (int j = 0; j < 12; j++) // вывести доходы по месяцам
            {
                if (((*iter)->getRevNo(j)) == 0)
                    cout << " 0 ";
                else
                    cout << (*iter)->getRevNo(j) << " ";
            }
            cout << endl;
            iter++;
        }
        cout << endl;
        cout << endl;
    }
}
//---------------------------------------------------------
float RevRecord::getSumOfRev() // сумма всех платежей
{
    float sumRevs = 0.0;
    iter = setPtrsRR.begin();
    while (iter != setPtrsRR.end())
    { // плюсуем суммы всех доходов водителей за все время
        sumRevs += (*iter)->getSumOfRev();
        iter++;
    }
    return sumRevs;
}




//---------------------------------------------------------
/////////////////методы класса RevInputScreen/////////////
void RevInputScreen::setRev()
{
    cout << "Enter the driver's name: ";
    getaLine(revName);
    // получить номер рейса по имени водителя
    FlightNo = ptrDriversList->getFlightNo(revName);
    if (FlightNo > 0) // если имя найдено, и такой водитель существует -
    { // получить сумму платежа
        cout << "Enter the amount of income (800.50): " << endl; // Введите сумму дохода (800.50)
        cin >> revPaid; // вводим цену
        cin.ignore(80, '\n');
        cout << "Enter the payment month number (1-12): " << endl; // Введите номер месяца оплаты (1-12)
        cin >> month;
        cin.ignore(80, '\n');
        month--; // (внутренняя нумерация 0-11)
         // вставляем сумму в запись о доходе
        ptrRevRecord->insertRev(FlightNo, month, revPaid);
    }
    else
        cout << "There is no such driver.\n" << endl; //Такого водителя нет
}





//---------------------------------------------------------
//////////////////методы класса ExpenseRecord//////////////
ExpenseRecord::~ExpenseRecord() // деструктор
{ // удалить объекты expense
// удалить указатели на вектор
    while (!vectPtrsExpenses.empty())
    {
        iter = vectPtrsExpenses.begin();
        delete* iter;
        vectPtrsExpenses.erase(iter);
    }
}
//--------------------------------------------------------
void ExpenseRecord::insertExp(Expense* ptrExp)
{
    vectPtrsExpenses.push_back(ptrExp);
}
//---------------------------------------------------------
void ExpenseRecord::display() // распечатываем все расходы
{
    cout << "\nDate\tRecipient\tAmount\tCategory\n"  // дата\получатель\сумма\категория
        << "----------------------------------------\n" << endl;
    if (vectPtrsExpenses.size() == 0) // В контейнере нет расходов
        cout << "***There are no expenses***\n" << endl;  // расходов нет
    else
    {
        iter = vectPtrsExpenses.begin();
        while (iter != vectPtrsExpenses.end())
        { // распечатываем все расходы
            cout << (*iter)->month << '/' << (*iter)->day << '\t' << (*iter)->payee << '\t' << '\t';
            cout << (*iter)->amount << '\t' << (*iter)->category << endl;
            iter++;
        }
        cout << endl;
    }
}
//--------------------------------------------------------
// используется при составлении годового отчета
float ExpenseRecord::displaySummary()
{
    float totalExpenses = 0; // Сумма по всем категориям расходов
    if (vectPtrsExpenses.size() == 0)
    {
        cout << "\tAll categories\t\t0\n"; // Все категории
        return 0;
    }
    iter = vectPtrsExpenses.begin();
    while (iter != vectPtrsExpenses.end())
    {
        //выводим на экран категории расходов
        cout << '\t' << ((*iter)->category) << '\t' << ((*iter)->amount) << endl;
        totalExpenses += (*iter)->amount; //подсчитываем все расходы
        iter++;
    }
    return totalExpenses;
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
