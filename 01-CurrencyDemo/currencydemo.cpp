#include <iostream>
#include "currencydemo.h"
#include <iomanip>

using namespace std;


Currency::Currency ()
{
    int rub, kop, n;
    double rubl;

    cout << "Please enter the amount of money you have in roubles and copecks: " << endl;
    cin >> rub >> kop;

    rubl = getBalance(rub, kop);
    printBalance(rubl);
    printMenu();
    cin >> n;
    makeChoice(n, rubl);

}

void Currency::printMenu(void)
{
    cout << "What would you like to do?" << endl;
    cout << "Please enter 1 to add money to your account" << endl;
    cout << "Please enter 2 to remove money from your account" << endl;
    cout << "Please enter 3 to convert your roubles to US dollars" << endl;
    cout << "Please enter 4 to convert your roubles to Euros" << endl;
    cout << "Please enter 0 to quit" << endl;
}

void Currency::makeChoice(int n, double rubl)
{
while (n!=0)
{
    if(n==1) {
        rubl=addRoubles(rubl);
        printBalance(rubl);
        printMenu();
        cin >> n; }
    if(n==2) {
        rubl=removeRoubles(rubl);
        printBalance(rubl);
        printMenu();
        cin >> n; }
    if(n==3) {
        convertToDollars(rubl);
        printMenu();
        cin >> n; }
    if(n==4) {
        convertToEuros(rubl);
        printMenu();
        cin >> n; }
    if(n==0)
        break;

}
}

double Currency::getBalance(int rub, int kop)
{
    double rubl;
    rubl = (double)rub + ((double)kop)/100.00;
    return rubl;
}

void Currency::printBalance(double rubl)
{
    cout << "Your current balance is " << fixed << setprecision(2) << rubl <<" roubles." << endl;
}

double Currency::addRoubles(double rubl)
{
    int ruba, ka;
    double ra;
    cout << "Please enter the amount in roubles and copecks to add to your account: " << endl;
    cin >> ruba >> ka;

    ra = ((double)ruba + ((double)ka)/100.00) + rubl;
    return ra;
}

double Currency::removeRoubles(double rubl)
{
    int ruba, ka;
    double ra;
    cout << "Please enter the amount in roubles and copecks to be removed from your account: " << endl;
    cin >> ruba >> ka;

    ra = rubl - ((double)ruba + ((double)ka)/100.00);
    return ra;
}

void Currency::convertToDollars(double rubl)
{
    double dollarRate, rtd;
	cout << "Please enter the current exchange rate for a dollar (like 25.55): " << endl;
	cin >> dollarRate;
	rtd = rubl / dollarRate;
	cout << "Your balance in dollars is " << rtd << endl;
}

void Currency::convertToEuros(double rubl)
{
    double euroRate, rte;
	cout << "Please enter the current exchange rate for a euro (like 44.01): " << endl;
	cin >> euroRate;
	rte = rubl / euroRate;
	cout << "Your balance in euros is " << rte << endl;
}









