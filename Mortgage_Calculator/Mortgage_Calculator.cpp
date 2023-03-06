#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int loanAmount;
    int initialAmount;
    int loanTerm;
    double interestRate;

    cout << "Введите сумму кредита: "; cin >> loanAmount;
    cout << "Введите начальную сумму: "; cin >> initialAmount;
    cout << "Введите срок кредита: "; cin >> loanTerm;
    cout << "Введите процентную ставку: "; cin >> interestRate;


    loanAmount = loanAmount - initialAmount;
    double monthlyRate = interestRate / 12 / 100;
    cout << "\n\nМесячная ставка: " << monthlyRate << endl;
    double totalBid = pow(monthlyRate + 1, loanTerm);
    cout << "Общая ставка: " << totalBid << endl;
    double monthlyPayment = loanAmount * monthlyRate * totalBid / (totalBid - 1);
    cout << "Ежемесячный платеж: " << monthlyPayment << " руб." << endl;
    int overpayment = monthlyPayment * loanTerm - loanAmount;
    cout << "Переплата: " << overpayment << " руб." << endl;

    double debtRepayment = loanAmount / loanTerm;
    double percentagePart;
    double remainingDebt;
    remainingDebt = loanAmount;
    cout << "Месяц          " << "Платеж        " << "Остаток           " << "Процент           " << endl;
    for (int i = 1;i <= loanTerm; i++)
    {
        percentagePart = remainingDebt * monthlyRate;
        debtRepayment = monthlyPayment - percentagePart;
        remainingDebt = remainingDebt - debtRepayment;
        
        cout << i << "      " << monthlyPayment << " руб.     " << (int)remainingDebt << " руб.        " << round((percentagePart * 100) / 100) <<" руб.      " << endl;
    }
    system("pause");
}