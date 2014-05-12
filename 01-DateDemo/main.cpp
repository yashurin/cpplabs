#include "dd.h"
#include <iostream>
#include <ctime>
#include <cstdlib>


#define DAY (24*60*60)


using namespace std;

int main()
{

    int dtemp;

DateDemo today;

today.printMenu();

int n;
cin >> n;
while (n!=0)
{
    if(n==1) {
        today.printToday();
        today.printMenu();
        cin >> n; }
    if(n==2) {
        today.printYesterday();
        today.printMenu();
        cin >> n; }
    if(n==3) {
        today.printTomorrow();
        today.printMenu();
        cin >> n; }
    if(n==4) {
        cout << "Enter the number of days from now: " << endl;
		cin >> dtemp;
		cout << dtemp << " days from now will be: " << endl;
		today.printFuture(dtemp);
        today.printMenu();
        cin >> n; }
    if(n==5) {
        cout << "Enter the number of days ago: " << endl;
        cin >> dtemp;
        cout << dtemp << " days ago was: " << endl;
        today.printPast(dtemp);
        today.printMenu();
        cin >> n; }
    if(n==6) {
        today.printMonth();
        today.printMenu();
        cin >> n; }
    if(n==7) {
        today.printWeekday();
        today.printMenu();
        cin >> n; }
    if(n==8) {
        cout << "Enter a year, a month, and a day: " << endl;
        int y1, m1, d1;
        cin >> y1 >> m1 >> d1;
        DateDemo somedate(y1, m1, d1);
        day_hour temp  = calcDifference(today, somedate);
        cout << "The difference between today and some other date is " << temp.day << " days." << endl;
        today.printMenu();
        cin >> n; }
    if(n==0)
        break;

}

cout << "Goodbye" << endl;

    return 0;
}

