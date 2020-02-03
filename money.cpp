/********
 Author:
 Program: Money class - program assignment #1
 Due Date:
 Purpose:
 ********/
#include "money.h"


// convert current currency values to a string
string Money::toString() {
    return "";
}

// format amount as a local currency and return
string Money::toCurrency(double amount) {

    stringstream ss;
    ss.imbue(locale(""));

    ss << showbase << put_money(amount*100);

    return ss.str();

}

// convert currency to float
// read currency values from stdin and compute value
// return results
string Money::processChange() {
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> cents;
    // adds the total amount of money
    total = (hundreds * 100) + (tens * 10) + (fives * 5) + (ones * 1) + (quarters * 0.25) + (dimes * 0.10) + (nickels * 0.05) + (cents * 0.01);
    return  to_string(hundreds) + " hundreds " + to_string(tens)
             + " tens " + to_string(fives) + " fives " + to_string(ones)
             + " ones " + to_string(quarters) + " quarters " + to_string(dimes)
             + " dimes " + to_string(nickels) + " nickels " + to_string(cents)
             + " pennies = "+ toCurrency(total);
}

// read from stdin and process float command
// convert float to change
// return results
string Money::processFloat() {

    float amount;
    cin >> amount;
    int amountInt = (int) (amount*100);

//  converts amount from float to a string with two decimal places
//  std::ostringstream streamObj;
//  streamObj << fixed << std::setprecision(2);
//  streamObj << amount;
//  std::string strObj = streamObj.str();

    hundreds = amountInt / 10000;
    tens = (amountInt % 10000) / 1000;
    fives = ((amountInt % 10000) % 1000) / 500;
    ones = (((amountInt % 10000) % 1000) % 500) / 100;
    quarters = ((((amountInt % 10000) % 1000) % 500) % 100) / 25;
    dimes = (((((amountInt % 10000) % 1000) % 500) % 100) % 25) / 10;
    nickels = ((((((amountInt % 10000) % 1000) % 500) % 100) % 25) % 10) /5;
    cents = (((((((amountInt % 10000) % 1000) % 500) % 100) % 25) % 10) % 5) / 1;

    return toCurrency(amount) + " = " + to_string(hundreds) + " hundreds " + to_string(tens) + " tens "
            + to_string(fives) + " fives " + to_string(ones) + " ones " +  to_string(quarters) + " quarters "
            + to_string(dimes) + " dimes " + to_string(nickels) + " nickels " + to_string(cents) + " pennies ";
}

// read from stdin and process check command
// convert float to dollar words & cents
// return results
string Money::processCheck() {
  return "";
}

// read from stdin and process change-float command
// read float of customer payment
// read float of transaction cost
// calculate difference and compute change values
// return the results
string Money::processChangeFloat() {

    cin >> amountPaid >> cost;
    double amountPaidDouble = (double)amountPaid;
    double changeDue = (amountPaid - cost);

//    this is to print changeDue as a string without rounding
//    std::ostringstream streamObj;
//    streamObj << fixed << std::setprecision(2);
//    streamObj << changeDue;
//    std::string strObj = streamObj.str();

    // an int version of changeDue to use in calculations
    int changeDueInt = (int) (changeDue * 100);

    hundreds = changeDueInt / 10000;
    tens = (changeDueInt % 10000) / 1000;
    fives = ((changeDueInt % 10000) % 1000) / 500;
    ones = (((changeDueInt % 10000) % 1000) % 500) / 100;
    quarters = ((((changeDueInt % 10000) % 1000) % 500) % 100) / 25;
    dimes = (((((changeDueInt % 10000) % 1000) % 500) % 100) % 25) / 10;
    nickels = ((((((changeDueInt % 10000) % 1000) % 500) % 100) % 25) % 10) / 5;
    cents = (((((((changeDueInt % 10000) % 1000) % 500) % 100) % 25) % 10) % 5) / 1;

    return "change back on " + toCurrency(amountPaidDouble) + " for purchase of " + toCurrency(cost)
            + " is " + toCurrency(changeDue) + " which is " + to_string(hundreds) + " hundreds " + to_string(tens)
            + " tens " + to_string(fives) + " fives " + to_string(ones) + " ones " + to_string(quarters)
            + " quarters " + to_string(dimes) + " dimes " + to_string(nickels) + " nickels " + to_string(cents) + " pennies ";
}

// read from stdin and process change-change command
// read change of customer payment
// read float of transaction cost
// calculate difference and compute change values
// output the results
string Money::processChangeChange() {
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> cents >> cost;
    amountPaid = (hundreds*100) + (tens * 10) + (fives * 5) + (ones * 1) + (quarters * 0.25) + (dimes * 0.10) + (nickels * 0.05) + (cents * 0.01);
    double changeDue = amountPaid-cost;
    int changeDueInt = (int)((amountPaid - cost)*100);

    std::ostringstream streamObj;
    streamObj << fixed << std::setprecision(2) ;
    streamObj << changeDue;
    std::string strObj = streamObj.str();

    hundreds2 = changeDueInt / 10000;
    tens2 = (changeDueInt % 10000) / 1000;
    fives2 = ((changeDueInt % 10000) % 1000) / 500;
    ones2 = (((changeDueInt % 10000) % 1000) % 500) / 100;
    quarters2 = ((((changeDueInt % 10000) % 1000) % 500) % 100) / 25;
    dimes2 = (((((changeDueInt % 10000) % 1000) % 500) % 100) % 25) / 10;
    nickels2 = ((((((changeDueInt % 10000) % 1000) % 500) % 100) % 25) % 10) /5;
    cents2 = (((((((changeDueInt % 10000) % 1000) % 500) % 100) % 25) % 10) % 5) / 1;

    // cout << changeDue << endl << amountPaid << endl;
    return  "change back on " + to_string(hundreds) + " hundreds " + to_string(tens)
            + " tens " + to_string(fives) + " fives " + to_string(ones)
            + " ones " + to_string(quarters) + " quarters " + to_string(dimes)
            + " dimes " + to_string(nickels) + " nickels " + to_string(cents)
            + " pennies for purchase of " + toCurrency(cost) + " is " + toCurrency(changeDue) + " which is "
            + to_string(hundreds2) + " hundreds " + to_string(tens2) + " tens " + to_string(fives2)
            + " fives " + to_string(ones2) + " ones " + to_string(quarters2) + " quarters "
            + to_string(dimes2 ) + " dimes " + to_string(nickels2) + " nickels " + to_string(cents2) + " pennies ";
}
