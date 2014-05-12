#ifndef DATEDEMO_H
#define DATEDEMO_H

#include <ctime>

using namespace std;


struct day_hour {
	int day;
	int hour; };





class DateDemo
{
    public:
	DateDemo();
	DateDemo(int year, int month, int day, int hour = 0, int minute = 0, int sec = 0);
	DateDemo(time_t s);


    void printMenu(void);
	void printToday(void);
    void printYesterday(void);
	void printTomorrow(void);
	void printFuture(int n);
	void printPast(int n);
	void printMonth(void);
	void printWeekday(void);
	int getYear(void);
	friend day_hour calcDifference(DateDemo & d1, DateDemo & d2);

	private:
	tm struct_date;
	time_t sek_date;
	void setStruct(void) { struct_date = *(localtime(&sek_date)); };
	void setSek(void) { sek_date = mktime(&struct_date); };
	time_t newDate(time_t sek) { return sek_date + sek; };
	time_t _temp;

};



#endif

