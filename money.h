/********
 Author:
 Program: Money class - program assignment #1
 Due Date:
 Purpose:
 ********/
#ifndef MONEY_H
#define MONEY_H
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <locale>

using namespace std;
class Money
{
private:
    double total;
    int hundreds, tens, fives, ones, quarters, dimes, nickels, cents;
    int hundreds2, tens2, fives2, ones2, quarters2, dimes2, nickels2, cents2;

    //double cost, amountPaid;
    float cost, amountPaid;

public:
    string toString();
    string toCurrency(double amount);
    string processChange();
    string processFloat();
    string processCheck();
    string processChangeFloat();
    string processChangeChange();
};
#endif
