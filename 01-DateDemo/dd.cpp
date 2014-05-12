
#include "dd.h"
#include <iostream>
#include <ctime>
#include <cstdlib>


#define DAY (24*60*60)


using namespace std;

const char *months[] =  {"January", "February", "March",
                        "April", "May", "June",
						"July", "August", "September",
						"October", "November", "December" };
const char *weekdays[] =    {"Sunday", "Monday", "Tuesday",
                            "Wednesday", "Thursday", "Friday",
                            "Saturday" };


DateDemo::DateDemo()
{
    sek_date = time(NULL); setStruct();
}

DateDemo::DateDemo(int year, int month, int day, int hour, int minute, int sec)
{
	struct_date.tm_sec=sec;
	struct_date.tm_min=minute;
	struct_date.tm_hour=hour;
	struct_date.tm_mday=day;
	struct_date.tm_mon=month-1;
	struct_date.tm_year=year-1900;
	setSek();
}

DateDemo::DateDemo(time_t s)
{
    sek_date = s; setStruct();
}

void DateDemo::printMenu(void)
{
    cout << "What would you like to do?" << endl;
    cout << "Please enter 1 to print today's date" << endl;
    cout << "Please enter 2 to print yesterday's date" << endl;
    cout << "Please enter 3 to print tomorrow's date" << endl;
    cout << "Please enter 4 to print a date N days from now" << endl;
    cout << "Please enter 5 to print a date N days ago" << endl;
    cout << "Please enter 6 to print the current month" << endl;
    cout << "Please enter 7 to print the current weekday" << endl;
    cout << "Please enter 8 to calculate the difference between two days" << endl;
    cout << "Please enter 0 to quit" << endl;
}


void DateDemo::printToday(void)
{
    time_t today = time(NULL);
    cout << "Today: " <<ctime(&today);
}

void DateDemo::printYesterday(void)
{
    time_t yesterday = time(NULL) - DAY;
    cout << "Yesterday: " << ctime(&yesterday);
}

void DateDemo::printTomorrow(void)
{
    time_t tomorrow = time(NULL) + DAY;
	cout << "Tomorrow: " << ctime(&tomorrow);
}

void DateDemo::printFuture(int n)
{
    time_t future = time(NULL) + DAY*n;
	cout << "Future Date: " << ctime(&future);
}

void DateDemo::printPast(int n)
{
    time_t past = time(NULL) - DAY*n;
	cout << "Past Date: " << ctime(&past);
}

void DateDemo::printMonth(void)
{
    cout << months[struct_date.tm_mon] << endl;
}

void DateDemo::printWeekday(void)
{
    cout << weekdays[struct_date.tm_wday] << endl;
}

int DateDemo::getYear(void)
{
    return struct_date.tm_year + 1900;
}

day_hour calcDifference(DateDemo &d1, DateDemo &d2)
{
	int diff = d1.sek_date - d2.sek_date;
	if (diff < 0)
        diff = -diff;
	day_hour temp;
	temp.day = diff / DAY;
	return temp;
}



